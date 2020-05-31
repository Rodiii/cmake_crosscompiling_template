set(CMAKE_TOOLCHAIN_FILE "toolchain-rpi.cmake")
SET(CMAKE_SYSTEM_NAME Linux)
SET(CMAKE_SYSTEM_VERSION 1)

# Specify the cross compiler
set(tools ${PROJECT_SOURCE_DIR}/../gcc-linaro-arm-linux-gnueabihf-tools)
SET(CMAKE_C_COMPILER ${tools}/bin/arm-linux-gnueabihf-gcc)
SET(CMAKE_CXX_COMPILER ${tools}/bin/arm-linux-gnueabihf-g++)

# Where is the target environment
SET(CMAKE_FIND_ROOT_PATH ${tools}/arm-linux-gnueabihf)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --sysroot=${CMAKE_FIND_ROOT_PATH}")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} --sysroot=${CMAKE_FIND_ROOT_PATH}")
SET(CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} --sysroot=${CMAKE_FIND_ROOT_PATH}")

set(CMAKE_PREFIX_PATH ${tools}/arm-linux-gnueabihf/lib/arm-linux-gnueabihf/cmake)

# Search for programs only in the build host directories
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# Search for libraries and headers only in the target directories
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

SET(CMAKE_ARM_COMPILATION 1)