#pragma once

//* Cygwin Environment
#if defined(__CYGWIN__)
    #define COTTON_ENV_CYGWIN 1
    #define COTTON_OS_POSIX   1
#endif

//* Apple's family of operating systems.
#if defined(__APPLE__)
    #include <TargetConditionals.h>

    /*
     * iOS
     * TARGET_OS_IOS is defined to 1 when targeting iPhone OS
     */
    #if (defined(TARGET_OS_IOS) && TARGET_OS_IOS) || defined(__IPHONE__)
        #define COTTON_OS_IPHONE     1
        #define COTTON_OS_KERNEL_XNU 1

        #define COTTON_OS_POSIX 1
        #define COTTON_OS_NAME  "iOS"

    /*
     * OSX
     * TARGET_OS_OSX is defined to 1 when generating code for OSX.
     */
    #elif (defined(TARGET_OS_OSX) && TARGET_OS_OSX) || defined(__MACH__)
        #define COTTON_OS_OSX        1
        #define COTTON_OS_KERNEL_XNU 1

    #else
        #error Cannot determine operating system.
    #endif

//* Family of operating systems which use the linux kernel.
#elif defined(__linux__)
    #define COTTON_OS_LINUX        1
    #define COTTON_OS_KERNEL_LINUX 1

    #define COTTON_OS_POSIX 1

    /*
     * Android Mobile OS
     * __ANDROID__ is defined by GCC and Clang
     */
    #if defined(__ANDROID__)
        #define COTTON_OS_ANDROID 1
        #define COTTON_OS_NAME    "Android"

    /*
     * GNU/Linux OS
     * Family of operating systems which use the linux kernel
     * and the GNU system utilities.
     */
    #elif defined(__gnu_linux__)
        #define COTTON_OS_GNU_LINUX 1
        #define COTTON_OS_NAME      "GNU/Linux"

    #else
        #define COTTON_OS_NAME "Linux"
    #endif

    /*
     * BSD Environment
     * BSD is defined in the <sys/param.h> header file
     * _SYSTYPE_BSD is defined by DEC C/C++ compiler
     */
    #if __has_include(<sys/param.h>)
        #include <sys/param.h>
    #endif

#elif defined(BSD) || defined(_SYSTYPE_BSD)
    #define COTTON_OS_BSD        1
    #define COTTON_OS_KERNEL_BSD 1

    #define COTTON_OS_POSIX 1

    //* Family of BSD operating systems.
    //* FreeBSD OS
    #if defined(__FreeBSD__)
        #define COTTON_OS_FREEBSD 1
        #define COTTON_OS_NAME    "FreeBSD"

    //* OpenBSD OS
    #elif defined(__OpenBSD__)
        #define COTTON_OS_OPENBSD 1
        #define COTTON_OS_NAME    "OpenBSD"

    //* NetBSD OS
    #elif defined(__NetBSD__)
        #define COTTON_OS_NETBSD 1
        #define COTTON_OS_NAME   "NetBSD"

    //* DragonFlyBSD OS
    #elif defined(__DragonFly__)
        #define COTTON_OS_DRAGONFLY 1
        #define COTTON_OS_NAME      "DragonFlyBSD"

    #else
        #define COTTON_OS_NAME "BSD"
    #endif

/*
 * Windows OS
 * __TOS_WIN__ is defined by the XL C/C++ compiler
 */
#elif defined(_WIN32) || defined(_WIN64) || defined(__TOS_WIN__)
    #define COTTON_OS_WINDOWS 1
    #define COTTON_OS_NAME    "Windows"

    #define COTTON_OS_KERNEL_NT 1

/*
 * IBM AIX OS
 * __TOS_AIX__ is defined by the XL C/C++ compiler
 */
#elif defined(_AIX) || defined(__TOS_AIX__)
    #define COTTON_OS_AIX  1
    #define COTTON_OS_NAME "IBM AIX"

    #define COTTON_OS_POSIX 1

//* GNU or GNU/Hurd OS
#elif defined(__gnu_hurd__)
    #define COTTON_OS_GNU_HURD    1
    #define COTTON_OS_KERNEL_HURD 1

    #define COTTON_OS_POSIX 1
    #define COTTON_OS_NAME  "GNU/Hurd"

//* Haiku OS
#elif defined(__HAIKU__)
    #define COTTON_OS_HAIKU 1
    #define COTTON_OS_NAME  "Haiku"

    #define COTTON_OS_POSIX 1

//* QNX OS
#elif defined(__QNX__) || defined(__QNXNTO__)
    #define COTTON_OS_QNX  1
    #define COTTON_OS_NAME "QNX"

    #define COTTON_OS_POSIX 1

/*
 * Serenity OS
 * __serenity__ is defined by GCC and Clang
 */
#elif defined(__serenity__)
    #define COTTON_OS_SERENITY 1
    #define COTTON_OS_NAME     "SerenityOS"

//* Solaris OS
#elif (defined(sun) || defined(__sun)) && (defined(__SVR4) || defined(__svr4__))
    #define COTTON_OS_SOLARIS 1
    #define COTTON_OS_NAME    "Solaris"

#else
    #error Cannot determine operating system.
#endif

//* !APPLE
#if !defined(COTTON_OS_IPHONE)
    #define COTTON_OS_IPHONE 0
#endif

#if !defined(COTTON_OS_OSX)
    #define COTTON_OS_OSX 0
#endif

#if !defined(COTTON_OS_KERNEL_XNU)
    #define COTTON_OS_KERNEL_XNU 0
#endif

//* !LINUX
#if !defined(COTTON_OS_LINUX)
    #define COTTON_OS_LINUX 0
#endif

#if !defined(COTTON_OS_KERNEL_LINUX)
    #define COTTON_OS_KERNEL_LINUX 0
#endif

#if !defined(COTTON_OS_ANDROID)
    #define COTTON_OS_ANDROID 0
#endif

#if !defined(COTTON_OS_GNU_LINUX)
    #define COTTON_OS_GNU_LINUX 0
#endif

//* !BSD
#if !defined(COTTON_OS_BSD)
    #define COTTON_OS_BSD 0
#endif

#if !defined(COTTON_OS_KERNEL_BSD)
    #define COTTON_OS_KERNEL_BSD 0
#endif

#if !defined(COTTON_OS_FREEBSD)
    #define COTTON_OS_FREEBSD 0
#endif

#if !defined(COTTON_OS_OPENBSD)
    #define COTTON_OS_OPENBSD 0
#endif

#if !defined(COTTON_OS_NETBSD)
    #define COTTON_OS_NETBSD 0
#endif

#if !defined(COTTON_OS_DRAGONFLY)
    #define COTTON_OS_DRAGONFLY 0
#endif

//* !WINDOWS
#if !defined(COTTON_OS_WINDOWS)
    #define COTTON_OS_WINDOWS 0
#endif

#if !defined(COTTON_OS_KERNEL_NT)
    #define COTTON_OS_KERNEL_NT 0
#endif

//* !AIX
#if !defined(COTTON_OS_AIX)
    #define COTTON_OS_AIX 0
#endif

//* !GNU/HURD
#if !defined(COTTON_OS_GNU_HURD)
    #define COTTON_OS_GNU_HURD 0
#endif

#if !defined(COTTON_OS_KERNEL_HURD)
    #define COTTON_OS_KERNEL_HURD 0
#endif

//* !HAIKU
#if !defined(COTTON_OS_HAIKU)
    #define COTTON_OS_HAIKU 0
#endif

//* !QNX
#if !defined(COTTON_OS_QNX)
    #define COTTON_OS_QNX 0
#endif

//* !SERENITY
#if !defined(COTTON_OS_SERENITY)
    #define COTTON_OS_SERENITY 0
#endif

//* !SOLARIS
#if !defined(COTTON_OS_SOLARIS)
    #define COTTON_OS_SOLARIS 0
#endif

//* Miscellaneous
#if !defined(COTTON_OS_POSIX)
    #define COTTON_OS_POSIX 0
#endif
