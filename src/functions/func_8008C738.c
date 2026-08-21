/* Independently written from the specification for func_8008C738. */

#include "podcruise/types.h"
f32 func_8008C738(u64 value) {
    f32 result;

    result = (f32)(s64)value;
    if ((s64)value < 0) {
        result += 4294967296.0f;
    }
    return result;
}
