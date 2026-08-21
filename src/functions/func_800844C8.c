/* Independently written from scratchpad spec specs/func_800844C8.md. */

#include "podcruise/types.h"

typedef struct {
    u8 unk_00[0x1C];
    f32 unk_1C[8];
} Object800844C8;

extern s32 func_80017DAC(const void *object);

s32 func_800844C8(Object800844C8 *object) {
    f32 ceiling;
    s32 limit;
    s32 index;

    limit = func_80017DAC(object);
    if (limit <= 0) {
        return -1;
    }
    ceiling = 20.0f;
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
