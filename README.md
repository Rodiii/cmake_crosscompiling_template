# CMake Cross-Compiling Template for Raspberry PI

This template can be used in order to cross-compile for ARM or specific for the Raspberry PI. In addition, it explains how to include external dependencies for cross-compiling.

## Quick Usage
### 1. RPI-Tool: Clone RaspberryPI Tools

```
git clone https://github.com/raspberrypi/tools.git /home/<yourusername>/rpi-tools
```

### 2. Clone CMake Cross-Compiling Template

```
git clone https://github.com/Rodiii/cmake_crosscompiling_template
```

### 3. Toolchain: Modify Path to RPI Tools in toolchain-arm.cmake

In cmake_crosscompiling_template/toolchain-arm.cmake replace <path-to-raspberrypi-tools> with the path where you cloned the rpi-tools to. Please don’t use ~ here.

### 4. Build it for PI

```
mkdir build_arm
cd build_arm
cmake -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../toolchain-arm.cmake ..
make -j 8
```

## Tutorial

A complete tutorial can be found here: [Tutorial](https://rothech.com/cmake-cross-compiling-for-dummies)
