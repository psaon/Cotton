#include <climits>
#include "Cotton/Core/Predefined.h"

#if CHAR_BIT != 8
    #error Cotton expects CHAR_BIT to be 8.
#endif

#if COTTON_VERSION_CPP < COTTON_VERSION_CPP20
    #error Cotton should be compiled in C++20 and above.
#endif
