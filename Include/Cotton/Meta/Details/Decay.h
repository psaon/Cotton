#pragma once

#include "Cotton/Meta/Details/IsArray.h"
#include "Cotton/Meta/Details/IsFunction.h"
#include "Cotton/Meta/Details/PointerTransforms.h"
#include "Cotton/Meta/Details/QualifierTransforms.h"
#include "Cotton/Meta/Details/ReferenceTransforms.h"

#include "Cotton/Meta/Details/Conditionals.h"

namespace Cotton
{
    namespace Internal
    {
        // clang-format off
        template<class T>
        struct DecayHelper
        {
        private:
            using U = RemoveReference<T>;

        public:
            using Type = SelectType<IsArray<U>,
                                    AddPointer<RemoveExtent<U>>,
                                    SelectType<IsFunction<U>,
                                               AddPointer<U>,
                                               RemoveQualifiers<U>>>;
        };
        // clang-format on
    };   // namespace Internal

    template<class T>
    using Decay = Internal::DecayHelper<T>::Type;
}   // namespace Cotton
