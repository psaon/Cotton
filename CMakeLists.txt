cmake_minimum_required(VERSION 3.21)
project(Cotton LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(COTTON_HEADERS
    "Include/Cotton/Core/Details/Architecture.h"
    "Include/Cotton/Core/Details/Compiler.h"
    "Include/Cotton/Core/Details/Endian.h"
    "Include/Cotton/Core/Details/LanguageVersion.h"
    "Include/Cotton/Core/Details/OperatingSystem.h"
    "Include/Cotton/Core/Details/SIMD.h"

    "Include/Cotton/Core/Attributes.h"
    "Include/Cotton/Core/FeatureChecks.h"
    "Include/Cotton/Core/Predefined.h"

    "Include/Cotton/Meta/Details/ArrayTransforms.h"
    "Include/Cotton/Meta/Details/Conditionals.h"
    "Include/Cotton/Meta/Details/IsProperty.h"
    "Include/Cotton/Meta/Details/IsType.h"
    "Include/Cotton/Meta/Details/IsTypeCategory.h"
    "Include/Cotton/Meta/Details/PointerTransforms.h"
    "Include/Cotton/Meta/Details/QualifierTransforms.h"
    "Include/Cotton/Meta/Details/ReferenceTransforms.h"
    "Include/Cotton/Meta/Details/SignTransforms.h"
    "Include/Cotton/Meta/Details/TypeConstant.h"

    "Include/Cotton/Meta/TypeTransforms.h"
)

set(COTTON_SOURCES
    "Source/Core/PolicyCheck.cpp"
)

set(COTTON_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(COTTON_INCLUDE_DIR "${COTTON_ROOT_DIR}/Include")
set(COTTON_TEST_DIR "${COTTON_ROOT_DIR}/Tests")

option(COTTON_BUILD_SHARED "Build Cotton as a shared library." OFF)
option(COTTON_BUILD_TESTS "Build Cotton's test executables." OFF)

option(COTTON_USE_EXTERNAL_GTEST "Use installed googletest." OFF)

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

if (COTTON_BUILD_TESTS)
    if (COTTON_USE_EXTERNAL_GTEST)
        find_package(GTest REQUIRED)
        set(COTTON_GTEST_DIR ${GTEST_ROOT})

    else()
        set(COTTON_GTEST_DIR "ThirdParty/googletest")

        if (NOT EXISTS ${COTTON_GTEST_DIR})
            message(FATAL_ERROR "Cannot find googletest dependency in ${COTTON_GTEST_DIR}.")
        endif()

        add_subdirectory("${COTTON_GTEST_DIR}")
    endif()

    add_subdirectory("Tests")
endif()
