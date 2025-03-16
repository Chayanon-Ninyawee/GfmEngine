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

## Development Notes

For a detailed log of problems encountered and fixes implemented during the development of this project, see [ProblemsFixed.md](docs/ProblemsFixed.md).  
This document is intended for contributors who want to understand the technical problems and solutions related to the project setup, dependencies, and development workflow.