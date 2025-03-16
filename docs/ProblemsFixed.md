# Problems Fixed

This document tracks various issues encountered while setting up GfmEngine with SFML and FLAC, along with the solutions applied.  
It is intended as a reference for future contributors who may run into similar problems.


### 1.1. **Missing FLAC Dependency in SFML**
**Problem:**  
CMake failed due to missing `FLAC_LIBRARY` and `FLAC_INCLUDE_DIR`.  
SFML requires FLAC for its audio module.

**Solution:**  
- Used `FetchContent` to fetch and build FLAC from source.
- Disabled `INSTALL_MANPAGES` to avoid Pandoc errors.
- Instructed SFML to use the built FLAC instead of searching for a system install.
    ```cmake
    FetchContent_Declare(
        FLAC
        GIT_REPOSITORY https://github.com/xiph/flac.git
        GIT_TAG        1.5.0  # Use the latest stable version
    )
    FetchContent_MakeAvailable(FLAC)
    ```

### 1.2. **Man Page Installation Failure Due to Missing Pandoc**
**Problem:**  
FLAC's build system attempted to generate man pages using Pandoc, which was missing.  

**Solution:**  
- Disabled man page installation in CMake:
    ```cmake
    FetchContent_Declare(
        FLAC
        GIT_REPOSITORY https://github.com/xiph/flac.git
        GIT_TAG        1.5.0  # Use the latest stable version
    )
    set(INSTALL_MANPAGES OFF CACHE BOOL "" FORCE) # Disable manpages to avoid Pandoc error
    FetchContent_MakeAvailable(FLAC)
    ```

### 1.3. **Conflicts Between SFML's `FindFLAC.cmake` and Manually Built FLAC**
**Problem:**  
SFML's `FindFLAC.cmake` attempted to create an imported target `FLAC::FLAC`, causing CMake errors.  

**Solution:**  
- Disabled SFML's FLAC search:
  ```cmake
  set(SFML_USE_SYSTEM_DEPS OFF CACHE BOOL "" FORCE)
  set(SFML_FIND_FLAC OFF CACHE BOOL "" FORCE)
  ```
- Manually linked the built FLAC library to SFML.

### 2. **IntelliSense Not Detecting SFML Headers in VS Code**
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