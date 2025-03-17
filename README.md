# GfmEngine

GfmEngine is a game framework that utilizes SFML for cross-platform development.  
This repository includes SFML as a Git submodule, so you must initialize it properly after cloning.

## Cloning the Repository

Since SFML is a submodule, use the following command to **clone** the repository properly:

```sh
git clone --recursive https://github.com/Chayanon-Ninyawee/GfmEngine.git
```

If you've already cloned the repository **without** `--recursive`, run:

```sh
git submodule update --init --recursive
```

## Updating SFML Submodule

To update the SFML submodule to the latest commit from its branch:

```sh
git submodule update --remote --merge
```

## Building the Project

### Building with Docker (Ensuring Compatibility)

If you are building in **Ubuntu 22.04 or later**, the `GfmEngineTest` executable on other older Linux distro may fail to run due to GLIBC version too old.  
To ensure compatibility, you can build the project inside an **Ubuntu 20.04 Docker container**.

Run the following command:

```sh
./build-ubuntu20-docker.sh
```

This script will:
- Build a Docker image with the required dependencies.
- Compile GfmEngine inside an Ubuntu 20.04 container.
- Extract the compiled binaries for use on older systems.

For more details, see [ProblemsFixed.md](docs/ProblemsFixed.md).

---

### Building with VS Code Tasks

If you are using **VS Code**, you can build the project using the built-in task system.

1. Open **Command Palette** (`Ctrl+Shift+P`).
2. Select **Tasks: Run Task**.
3. Choose one of the available build tasks:
   - **`Build GfmEngineTest With Docker (Release)`** – Builds using the Docker-based approach. (This literally just run the shell script from above)
   - **`Build GfmEngineTest (Release)`** – Builds on your local machine (may fail on other Linux distro if their GLIBC is too old).
   - **`Build GfmEngineTest (Debug)`** – Builds on your local machine in debug mode.


## Debugging with VS Code

The repository includes a pre-configured `launch.json.in`, which automatically sets up the debugger for `GfmEngineTest`.  
However, you may need to configure CMake first before running and debugging.

### Running the Debugger:
1. Open **Run and Debug** (`Ctrl+Shift+D`).
2. Select one of the available configurations:
   - **Run GfmEngineTest (Release)** – Runs the locally built binary.
   - **Run GfmEngineTest (Debug)** – Runs and debugs the locally built binary.
3. Click **Start Running (F5)**.


## Development Notes

For a detailed log of problems encountered and fixes implemented during the development of this project, see [ProblemsFixed.md](docs/ProblemsFixed.md).  
This document is intended for contributors who want to understand the technical problems and solutions related to the project setup, dependencies, and development workflow.