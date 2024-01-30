#pragma once

namespace Cotton
{
    namespace Internal
    {
        template<bool B, class True, class False>
        struct SelectTypeHelper
        {
            using Type = True;
        };

        template<class True, class False>
        struct SelectTypeHelper<false, True, False>
        {
            using Type = False;
        };
    }   // namespace Internal

    template<bool B, class True, class False>
    using SelectType = Internal::SelectTypeHelper<B, True, False>::Type;

}   // namespace Cotton
