#pragma once

namespace Cotton::Internal
{
    template<class T, T Val>
    struct TypeConstant
    {
        static constexpr T Value = Val;
    };

    template<bool Val>
    using BoolConstant = TypeConstant<bool, Val>;
}   // namespace Cotton::Internal
