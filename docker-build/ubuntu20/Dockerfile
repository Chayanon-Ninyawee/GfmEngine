# Use Ubuntu 20.04 to ensure compatibility with older GLIBC versions
FROM ubuntu:20.04

# Set non-interactive mode to prevent prompts during installation
ENV DEBIAN_FRONTEND=noninteractive

# Install system dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    wget \
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
COPY CMakeLists.txt .
COPY src/ src/
COPY include/ include/
COPY test/ test/
COPY external/ external/

# Configure and build
RUN rm -rf build && cmake -B build -G Ninja -DGFMENGINE_GENERATE_VSCODE=OFF -DGFMENGINE_GENERATE_DOCKER_SCRIPT=OFF && cmake --build build --config Release
