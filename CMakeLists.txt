cmake_minimum_required(VERSION 3.21)
project(Cotton LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COTTON_HEADERS
    "Include/Cotton/Core/Details/Architecture.h"
    "Include/Cotton/Core/Details/Compiler.h"
    "Include/Cotton/Core/Details/Endian.h"
    "Include/Cotton/Core/Details/OperatingSystem.h"

    "Include/Cotton/Core/FeatureChecks.h"
    "Include/Cotton/Core/Predefined.h"
)

set(COTTON_SOURCES
    "Source/Temp.cpp"
)

option(COTTON_BUILD_SHARED "Build Cotton as a shared library." OFF)

if (COTTON_BUILD_SHARED)
    add_library(Cotton STATIC ${COTTON_HEADERS} ${COTTON_SOURCES})
else()
    add_library(Cotton SHARED ${COTTON_HEADERS} ${COTTON_SOURCES})
endif()

target_include_directories(Cotton PRIVATE "Include")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(Cotton PRIVATE
        -Wall           # Enable all warnings about construction.
        -Wextra         # Enable warnings that aren't enabled by -Wall.

        -Werror         # Turn all warnings into errors.
        -pedantic       # Enable warnings about compiler extensions.

        # Enables other warnings, look at https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html for details.
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        -Wmisleading-indentation
        -Wduplicated-cond
        -Wduplicated-branches
        -Wnull-dereference
    )
endif()
