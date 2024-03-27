#pragma once

#include <cstdlib>
#include "Cotton/Debug/SourceLocation.h"

namespace Cotton
{
    struct PanicInfo
    {
        const char* message;
        SourceLocation location;
    };

    using PanicHookType = void (*)(const PanicInfo&);

    // Implemented by every supported platform.
    void DefaultPanicHook(const PanicInfo& panic_info);

    class PanicSettings
    {
    public:
        static void SetHook(PanicHookType hook);
        static PanicHookType GetHook();

        // Atomic version of SetHook.
        // static void UpdateHook(PanicHookType hook);

    public:
        static void EnableHook();
        static void DisableHook();

        static bool IsHookEnabled();

    private:
        static PanicHookType hook_;
        static bool hook_enabled_;
    };

    [[noreturn]]
    inline void Panic(const char* message, SourceLocation loc = SourceLocation())
    {
        PanicHookType hook = PanicSettings::GetHook();
        if (PanicSettings::IsHookEnabled())
            hook({ .message = message, .location = loc });

        std::abort();
    }

}   // namespace Cotton
