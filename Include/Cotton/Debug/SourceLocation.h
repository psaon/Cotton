#pragma once

#include "Cotton/Core/Types.h"
#include "Cotton/Core/FeatureChecks.h"

#if COTTON_HAS_BUILTIN(__builtin_LINE) && COTTON_HAS_BUILTIN(__builtin_FILE) && \
    COTTON_HAS_BUILTIN(__builtin_FUNCTION)
    #define COTTON_BUILTIN_LINE()     __builtin_LINE()
    #define COTTON_BUILTIN_FILE()     __builtin_FILE()
    #define COTTON_BUILTIN_FUNCTION() __builtin_FUNCTION()

#else
    #define COTTON_BUILTIN_LINE()     0
    #define COTTON_BUILTIN_FILE()     "unknown"
    #define COTTON_BUILTIN_FUNCTION() "unknown"
#endif

namespace Cotton
{
    class SourceLocation
    {
    public:
        constexpr SourceLocation(Uint32 line = COTTON_BUILTIN_LINE(),
                                 const char* file_path = COTTON_BUILTIN_FILE(),
                                 const char* func_name = COTTON_BUILTIN_FUNCTION())
            : line_(line), file_path_(file_path), func_name_(func_name)
        {
        }

        constexpr SourceLocation(const SourceLocation&) = default;
        constexpr SourceLocation(SourceLocation&&) = default;

    public:
        constexpr Uint32 Line() const { return line_; }

        constexpr const char* FileName() const { return file_path_; }
        constexpr const char* FunctionName() const { return func_name_; }

    private:
        Uint32 line_;

        const char* file_path_;
        const char* func_name_;
    };
}   // namespace Cotton
