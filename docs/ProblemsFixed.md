# Problems Fixed

This document tracks various issues encountered while setting up GfmEngine with SFML and FLAC, along with the solutions applied.  
It is intended as a reference for future contributors who may run into similar problems.  
Note: The problems & fixes are not in chronological order.

---

## 1. **SFML & Dependency Management**

### 1.1. **Switching to Git Submodule for SFML**
**Problem:**  
Previously, SFML was fetched using `FetchContent`, leading to complex build configurations and long fetching time.  

**Solution:**  
- Switched to using a **Git submodule** for SFML.
- Ensured submodules are initialized and updated before building:
  ```sh
  git submodule update --init --recursive
  ```
- Updated `CMakeLists.txt` to add SFML as a subdirectory:
  ```cmake
  add_subdirectory(external/SFML)
  ```

### 1.2. **Using System Packages for SFML Dependencies**
**Problem:**  
Manually building all SFML dependencies added unnecessary overhead.

**Solution:**  
- Installed SFML dependencies via `apt`:
  ```sh
  sudo apt-get update && sudo apt-get install -y \
      libxrandr-dev \
      libxinerama-dev \
      libxcursor-dev \
      libxi-dev \
      libudev-dev \
      libgl-dev \
      libfreetype6-dev \
      libflac-dev \
      libogg-dev \
      libvorbis-dev \
      libvorbisenc2 \
      libvorbisfile3 \
      libpthread-stubs0-dev \
      x11proto-core-dev \
      libx11-dev
  ```
- This significantly reduced build times and simplified package management.

---

## 2. **Development Environment Issues**

### 2.1. **IntelliSense Not Detecting SFML Headers in VS Code**
**Problem:**  
VS Code could not find SFML headers (`#include <SFML/Graphics.hpp>` showed errors).  

**Solution:**  
- Ensured CMake generates `compile_commands.json` by adding:
  ```cmake
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  ```
  to `CMakeLists.txt`

- Configured VS Code to use `compile_commands.json`:
  ```json
  {
      "C_Cpp.default.compileCommands": "${workspaceFolder}/build/compile_commands.json",
      "cmake.configureOnOpen": true
  }
  ```
- Verified SFML include directories are correctly passed to the compiler.

---

## 3. **CMake & Build Script Issues**

### 3.1. **GLIBC Version Too Old on Ubuntu 22.04**
**Problem:**  
Running the `GfmEngineTest` executable on Ubuntu 22.04 resulted in a GLIBC version too old error.  
Ubuntu 22.04 has a older GLIBC version than the one that use to built (Linux Mint 22.1 "Xia"), causing compatibility issues.

**Solution:**  
- Built `GfmEngineTest` inside an **Ubuntu 20.04 Docker container** to ensure compatibility with older GLIBC versions.
- Created a `Dockerfile` to set up the build environment:
  ```dockerfile
  # Use Ubuntu 20.04 to ensure compatibility with older GLIBC versions
  FROM ubuntu:20.04

  # Set non-interactive mode to prevent prompts during installation
  ENV DEBIAN_FRONTEND=noninteractive

  # Install system dependencies
  RUN apt-get update && apt-get install -y \
      build-essential \
      wget \
      git \
      g++ \
      ninja-build \
      libxrandr-dev \
      libxinerama-dev \
      libxcursor-dev \
      libxi-dev \
      libudev-dev \
      libgl-dev \
      libfreetype6-dev \
      libflac-dev \
      libogg-dev \
      libvorbis-dev \
      libvorbisenc2 \
      libvorbisfile3 \
      libpthread-stubs0-dev \
      x11proto-core-dev \
      libx11-dev \
      && rm -rf /var/lib/apt/lists/*

  # Install CMake 3.28
  RUN wget -O cmake.sh https://github.com/Kitware/CMake/releases/download/v3.28.3/cmake-3.28.3-linux-x86_64.sh \
      && chmod +x cmake.sh \
      && mkdir /opt/cmake \
      && ./cmake.sh --skip-license --prefix=/opt/cmake \
      && ln -s /opt/cmake/bin/cmake /usr/local/bin/cmake \
      && rm cmake.sh

  # Set working directory
  WORKDIR /app

  # Copy the project files into the container
  COPY . .

  # Configure and build
  RUN rm -rf build && cmake -B build -G Ninja && cmake --build build --config Release
  ```

- Added a build script (`build-ubuntu20-docker.sh.in`) to automate the process:
  ```sh
  #!/bin/bash
  set -e  # Exit on error

  PROJECT_DIR="@CMAKE_SOURCE_DIR@"
  CONTAINER_NAME="temp-container"
  IMAGE_NAME="gfmengine-builder-ubuntu20"

  if [[ -z "$PROJECT_DIR" || "$PROJECT_DIR" == "/" ]]; then
      echo "Error: PROJECT_DIR is not set or invalid!"
      exit 1
  fi

  # Build the Docker image
  docker build -t "$IMAGE_NAME" "$PROJECT_DIR"

  # Prune old images
  docker image prune -f

  # Run the container
  docker run --name "$CONTAINER_NAME" "$IMAGE_NAME"

  # Ensure the build directory exists before deleting
  if [[ -d "$PROJECT_DIR/ubuntu20/build" ]]; then
      rm -rf "$PROJECT_DIR/ubuntu20/build"
  fi
  mkdir -p "$PROJECT_DIR/ubuntu20"

  # Copy build artifacts
  docker cp "$CONTAINER_NAME:/app/build" "$PROJECT_DIR/ubuntu20/build"

  # Clean up the container
  docker rm "$CONTAINER_NAME"
  ```

- This ensures that the `GfmEngineTest` executable runs on systems with older GLIBC versions.
