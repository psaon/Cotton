#include "Cotton/Error/Panic.h"

#include "Cotton/Core/Predefined.h"

#if COTTON_OS_WINDOWS
    #include "Cotton/Error/Details/WindowsPanicHook.h"
#elif COTTON_OS_LINUX
    #include "Cotton/Error/Details/LinuxPanicHook.h"
#else
    #include "Cotton/Error/Details/GeneralPanicHook.h"
#endif

namespace Cotton
{
    PanicHookType PanicSettings::hook_ = DefaultPanicHook;

    bool PanicSettings::hook_enabled_ = true;

    void PanicSettings::SetHook(PanicHookType hook) { hook_ = hook; }
    PanicHookType PanicSettings::GetHook() { return hook_; }

    void PanicSettings::EnableHook() { hook_enabled_ = true; }
    void PanicSettings::DisableHook() { hook_enabled_ = false; }

    bool PanicSettings::IsHookEnabled() { return hook_enabled_; }

}   // namespace Cotton
