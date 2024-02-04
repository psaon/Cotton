#pragma once

namespace Cotton
{
    namespace Internal
    {
        template<class T>
        struct IsLvalueReferenceHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsLvalueReferenceHelper<T&> : BoolConstant<true>
        {
        };

        template<class T>
        struct IsRvalueReferenceHelper : BoolConstant<false>
        {
        };

        template<class T>
        struct IsRvalueReferenceHelper<T&&> : BoolConstant<true>
        {
        };

    }   // namespace Internal

    template<class T>
    static constexpr bool IsLvalueReference = Internal::IsLvalueReferenceHelper<T>::Value;

    template<class T>
    static constexpr bool IsRvalueReference = Internal::IsRvalueReferenceHelper<T>::Value;

    template<class T>
    static constexpr bool IsReference = IsLvalueReference<T> || IsRvalueReference<T>;
}   // namespace Cotton
