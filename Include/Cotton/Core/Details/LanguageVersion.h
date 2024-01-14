#pragma once

#include "Cotton/Core/Details/Compiler.h"

#if !defined(__cplusplus)
    #error Cotton expects to be compiled with a C++ compiler.
#endif

#if COTTON_COMPILER_MSVC
    #define COTTON_VERSION_CPP _MSVC_LANG
#else
    #define COTTON_VERSION_CPP __cplusplus
#endif

#define COTTON_VERSION_CPP11 201103L
#define COTTON_VERSION_CPP14 201402L
#define COTTON_VERSION_CPP17 201703L
#define COTTON_VERSION_CPP20 202002L
