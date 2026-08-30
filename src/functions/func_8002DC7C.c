/* Independently written from specs/functions/recovered/func_8002DC7C.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x6C];
    s8 mode;
} PcObject8002DC7C;

typedef struct {
    s16 pad00[6];
    s16 value0;
    s16 value1;
    s16 value2;
    s16 value3;
} PcValues8002DC7C;

extern u32 D_80113688;
extern PcValues8002DC7C D_80113E60;

s32 func_8002DC7C(PcObject8002DC7C *object) {
    if (object->mode == 0) {
        if (D_80113688 & 0x20) {
            return 1;
        }
    } else {
        if ((D_80113E60.value0 == 0x3FFF) &&
            (D_80113E60.value1 == 0x3FFF) &&
            (D_80113E60.value2 == 0x3FFF) &&
            (D_80113E60.value3 == 0x00FF)) {
            return 1;
        }
    }
    return 0;
}
