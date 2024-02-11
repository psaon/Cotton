#pragma once

#include "Cotton/Meta/Details/TypeConstant.h"

#define COTTON_DEFINE_BINARY_OPERATOR_(name, op, T, U) \
    template<class T, class U>                         \
    static constexpr bool name = requires(T val1, U val2) { val1 op val2; }

#define COTTON_DEFINE_PREUNARY_OPERATOR_(name, op, T) \
    template<class T>                                 \
    static constexpr bool name = requires(T val) { op val; }

#define COTTON_DEFINE_POSTUNARY_OPERATOR_(name, op, T) \
    template<class T>                                  \
    static constexpr bool name = requires(T val) { val op; }

namespace Cotton
{
    COTTON_DEFINE_BINARY_OPERATOR_(HasAddition, +, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasSubtraction, -, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasMultiplication, *, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasDivision, /, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasModulo, %, T, U);

    COTTON_DEFINE_PREUNARY_OPERATOR_(HasPreincrement, ++, T);
    COTTON_DEFINE_PREUNARY_OPERATOR_(HasPredecrement, --, T);
    COTTON_DEFINE_POSTUNARY_OPERATOR_(HasPostincrement, ++, T);
    COTTON_DEFINE_POSTUNARY_OPERATOR_(HasPostdecrement, --, T);

    COTTON_DEFINE_BINARY_OPERATOR_(HasAddAssign, +=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasSubtractAssign, -=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasMultiplyAssign, *=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasDivideAssign, /=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasModuloAssign, %=, T, U);

    COTTON_DEFINE_BINARY_OPERATOR_(HasEqual, ==, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasNotEqual, !=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasGreaterEqual, >=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasLessEqual, <=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasGreater, >, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasLess, <, T, U);

    COTTON_DEFINE_PREUNARY_OPERATOR_(HasNegation, !, T);
    COTTON_DEFINE_BINARY_OPERATOR_(HasAnd, &&, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasOr, ||, T, U);

    COTTON_DEFINE_PREUNARY_OPERATOR_(HasBitwiseNot, ~, T);
    COTTON_DEFINE_BINARY_OPERATOR_(HasBitwiseOr, |, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasBitwiseAnd, &, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasBitwiseXor, ^, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasLeftShift, <<, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasRightShift, >>, T, U);

    COTTON_DEFINE_PREUNARY_OPERATOR_(HasDereference, *, T);
    COTTON_DEFINE_PREUNARY_OPERATOR_(HasAddress, &, T);

    COTTON_DEFINE_BINARY_OPERATOR_(HasBitwiseOrAssign, |=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasBitwiseAndAssign, &=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasBitwiseXorAssign, ^=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasLeftShiftAssign, <<=, T, U);
    COTTON_DEFINE_BINARY_OPERATOR_(HasRightShiftAssign, >>=, T, U);
}   // namespace Cotton

#undef COTTON_DEFINE_BINARY_OPERATOR_
#undef COTTON_DEFINE_PREUNARY_OPERATOR_
#undef COTTON_DEFINE_POSTUNARY_OPERATOR_
