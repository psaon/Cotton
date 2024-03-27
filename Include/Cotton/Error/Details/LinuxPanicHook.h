#pragma once

#if !defined(_GNU_SOURCE)
    #define _GNU_SOURCE
#endif

#include <cstdio>
#include <cstdlib>
#include <cinttypes>

#include <unistd.h>
#include <sys/types.h>

#include "Cotton/Error/Panic.h"
#include "Cotton/Debug/SourceLocation.h"

namespace Cotton
{
    namespace Internal
    {
        inline COTTON_FORCEINLINE int Snprintf(char* to, Usize n, const PanicInfo& info)
        {
            pid_t thread_id = ::gettid();
            const char* const fmt =
                "Thread %i panicked with message '%s'\nAt %s:%" PRIu32 ", %s\n";

            return ::std::snprintf(to, n, fmt, thread_id, info.message,
                                   info.location.FileName(), info.location.Line(),
                                   info.location.FunctionName());
        }
    }   // namespace Internal

    void DefaultPanicHook(const PanicInfo& info)
    {
        Usize len = static_cast<Usize>(Internal::Snprintf(nullptr, 0, info));
        char* buffer = ::std::malloc((len + 1) * sizeof(char));

        if (!buffer)
        {
            ::std::fputs("Panic function failed to allocate memory.\n", stderr);
            ::std::fputs(info.message, stderr);

            return;
        }

        Internal::Snprintf(buffer, len + 1, info);
        ::std::fputs(buffer);

        int flush_success = ::std::fflush(stderr);
        if (flush_success != 0)
        {
            ::std::fputs("Panic function failed to flush stream.\n", stderr);
            ::std::fputs(info.message, stderr);
        }

        ::std::free(buffer);
    }
}   // namespace Cotton
