/* Independently written from scratchpad spec specs/func_8000E8C4.md. */

#include "podcruise/types.h"

typedef struct Object8000E8C4 {
    u8 unk_00[0x14];
    s32 unk_14;
    void **unk_18;
} Object8000E8C4;

extern u32 func_80017DA4(const void *object);
extern s32 func_80017DAC(const void *object);

u32 func_8000E8C4(Object8000E8C4 *object) {
    volatile Object8000E8C4 *view;
    u32 *entry;
    s32 index;
    u32 value;

    if (object != 0) {
        if (func_80017DA4(object) == 0x3064) {
            view = object;
            for (index = 0; index < view->unk_14; index++) {
                entry = (u32 *)object->unk_18[index];
                value = *entry;
                if (value != 0) {
                    return value;
                }
            }
        } else if ((func_80017DA4(object) & 0x4000) != 0) {
            for (index = 0; index < func_80017DAC(object); index++) {
                value = func_8000E8C4(object->unk_18[index]);
                if (value != 0) {
                    return value;
                }
            }
        }
    }
    return 0;
}
