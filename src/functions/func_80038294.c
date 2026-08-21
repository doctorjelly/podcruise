/* Independently written from scratchpad spec specs/func_80038294.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk_00[0x1C];
    f32 unk_1C[8];
} Object80038294;

extern s32 func_80017DAC(const void *object);
extern s32 D_800A3FE8;

s32 func_80038294(Object80038294 *object) {
    f32 ceiling;
    s32 limit;
    s32 index;

    limit = func_80017DAC(object);
    if (limit <= 0) {
        return -1;
    }
    if (D_800A3FE8 != 0) {
        ceiling = 10.0f;
        if (object->unk_1C[0] > ceiling) {
            return -1;
        }
        index = 1;
        while (index < 8 && object->unk_1C[index] != -1.0f &&
               object->unk_1C[index] < ceiling) {
            index++;
        }
        index--;
        if (index >= limit) {
            return -1;
        }
        return index;
    }
    return 0;
}
