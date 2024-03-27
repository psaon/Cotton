#pragma once

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cinttypes>

#include <Windows.h>
#include "Cotton/Error/Panic.h"

#include "Cotton/Core/Types.h"
#include "Cotton/Core/Attributes.h"

#define COTTON_MIN(x, y) (((x) < (y)) ? (x) : (y))

namespace Cotton
{
    namespace Internal
    {
        Usize GetNextUTF8Segment(const char* message, Usize segment_size)
        {
            const char* guess = message + segment_size;
            if ((*guess & 0x80) == 0)   // ASCII character!
                return segment_size;

            // Fuck you clang-format!
            // clang-format off
            for (; (*guess & 0x40) == 0; --guess);
            // clang-format on

            return static_cast<Usize>(guess - message);
        }

        void WriteUnicode(const char* message)
        {
            constexpr Usize WideStringSize = 4096;
            wchar_t wide_buffer[WideStringSize + 1];

            const char* remaining_message = message;
            Usize msg_size = ::std::strlen(remaining_message);

            const char* const end = message + msg_size;

            while (remaining_message < end)
            {
                Usize remaining = static_cast<Usize>(end - remaining_message);
                Usize size_to_transcode = Internal::GetNextUTF8Segment(
                    remaining_message, COTTON_MIN(remaining, WideStringSize));

                int transcode_res = ::MultiByteToWideChar(
                    CP_UTF8, 0, remaining_message, static_cast<int>(size_to_transcode),
                    wide_buffer, WideStringSize);

                if (transcode_res == 0)   // If transcoding fails, stop printing..
                    break;

                wide_buffer[transcode_res] = L'\0';
                remaining_message += size_to_transcode;

                ::WriteConsoleW(::GetStdHandle(STD_ERROR_HANDLE), wide_buffer,
                                static_cast<DWORD>(transcode_res), nullptr, nullptr);
            }
        }

        inline COTTON_FORCEINLINE int Snprintf(char* to, Usize n, const PanicInfo& info)
        {
            const char* const fmt =
                "Thread %u panicked with message '%s'\nAt %s:%" PRIu32 ", %s";
            return ::std::snprintf(to, n, fmt,
                                   static_cast<unsigned int>(GetCurrentThreadId()),
                                   info.message, info.location.FileName(),
                                   info.location.Line(), info.location.FunctionName());
        }
    }   // namespace Internal

    void DefaultPanicHook(const PanicInfo& info)
    {
        Usize len = static_cast<Usize>(Internal::Snprintf(nullptr, 0, info));
        char* buffer = (char*)::std::malloc((len + 1) * sizeof(char));

        if (!buffer)
        {
            // If memory allocation fails, just print out error and get out..
            Internal::WriteUnicode("Panic function failed to allocate memory.\n");
            Internal::WriteUnicode(info.message);

            return;
        }

        Internal::Snprintf(buffer, len + 1, info);
        Internal::WriteUnicode(buffer);

        int flush_success = ::std::fflush(stderr);
        if (flush_success != 0)
        {
            Internal::WriteUnicode("Panic function failed to flush output stream.\n");
            Internal::WriteUnicode(info.message);
        }

        ::std::free(buffer);
    }
}   // namespace Cotton
