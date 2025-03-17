# Installing Clang-Format 20 on Linux Mint

## Step 1: Find the Correct LLVM APT Repository

Linux Mint is based on Ubuntu, so you'll need to find the corresponding repository for your version.  
Visit **[https://apt.llvm.org/](https://apt.llvm.org/)** and look for the correct repository URL based on your system.

Once you have the correct version, add the repository:

```bash
echo "deb http://apt.llvm.org/<your-version>/ llvm-toolchain-<your-version>-20 main" | sudo tee /etc/apt/sources.list.d/llvm.list
```

Replace `<your-version>` with the correct Ubuntu codename from the LLVM site.

## Step 2: Add the LLVM GPG Key

Download and add the GPG key to verify package authenticity:

```bash
wget -O - https://apt.llvm.org/llvm-snapshot.gpg.key | sudo apt-key add -
```

## Step 3: Update and Install Clang-Format 20

Run:

```bash
sudo apt update
sudo apt install clang-format-20
```

## Step 4: Verify Installation

Check if Clang-Format 20 is installed:

```bash
clang-format-20 --version
```

Expected output:

```
clang-format version 20.x.x
```