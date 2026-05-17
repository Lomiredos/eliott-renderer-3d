cmake_minimum_required(VERSION 3.20)
project(eliott-renderer-3d VERSION 1.0.0 LANGUAGES CXX)

if(TARGET eliott-renderer-3d)
    return()
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- vcpkg ---
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    if(DEFINED ENV{VCPKG_ROOT})
        set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    else()
        set(CMAKE_TOOLCHAIN_FILE "C:/Dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
    endif()
endif()

find_package(raylib CONFIG REQUIRED)

# --- Lib statique ---
add_library(eliott-renderer-3d STATIC
    src/Renderer3D.cpp
)

target_include_directories(eliott-renderer-3d PUBLIC
    include/
)

target_link_libraries(eliott-renderer-3d PUBLIC
    raylib
)
