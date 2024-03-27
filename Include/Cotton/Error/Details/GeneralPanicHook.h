#pragma once

#include <cstdio>
#include <cinttypes>

#include "Cotton/Core/Types.h"
#include "Cotton/Error/Panic.h"

namespace Cotton
{
    void DefaultPanicHook(const PanicInfo& info)
    {
        // Thread 1234 panicked with message 'Lorem ipsum dolor sit amet'
        // At Source/Main.cpp:42, main()
        ::std::fprintf(stderr,
                       "Thread <unknown> panicked with message '%s'\nAt %s:%" PRIu32
                       ", %s\n",
                       thread_id, info.message, info.location.FileName(),
                       info.location.Line(), info.location.FunctionName());

        ::std::flush(stderr);
    }
}   // namespace Cotton
