/* Independently written from specs/functions/recovered/func_8006C708.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad000[0x288];
    f32 levels288[6];
    u32 flags2A0[6];
} Obj8006C708;

s32 func_8006C708(void *arg0) {
    Obj8006C708 *obj;
    s32 result;
    s32 index;

    obj = arg0;
    result = 0;
    for (index = 0; index < 6; index++) {
        if ((obj->flags2A0[index] & 4) != 0 ||
            (obj->flags2A0[index] & 0x10) != 0) {
            if (index < 3) {
                result |= 1;
            } else {
                result |= 2;
            }
        }
    }
    return result;
}

f32 func_8006C828(void *arg0) {
    Obj8006C708 *obj;
    f32 result;
    s32 index;

    obj = arg0;
    result = 0.0f;
    for (index = 0; index < 6; index++) {
        if (0.8 < (f64)obj->levels288[index]) {
            if (index < 3) {
                result -= 0.33f;
            } else {
                result += 0.33f;
            }
        }
    }
    return result;
}
