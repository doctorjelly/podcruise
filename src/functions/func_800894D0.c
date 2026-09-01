/* Independently written from specs/functions/recovered/func_800894D0.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x0D];
    u8 value0D;
} Item800894D0;

typedef struct {
    u8 pad00[0x1C];
    Item800894D0 *owner1C;
    s16 state20;
    u8 pad22[2];
    f32 value24;
    s32 flags28;
    s16 angle2C;
    u8 byte2E;
    u8 byte2F;
} Slot800894D0;

typedef struct {
    u8 pad00[0x40];
    Slot800894D0 *slots40;
    s32 count44;
} Table800894D0;

s32 func_800894D0(void *arg0, void *arg1) {
    Table800894D0 *table;
    Item800894D0 *item;
    Slot800894D0 *slots;
    s32 count;
    s16 index;

    table = arg0;
    item = arg1;
    slots = table->slots40;
    index = 0;
    count = table->count44;
    for (; index < count; index++) {
        if (slots[index].owner1C == 0) {
            slots[index].owner1C = item;
            slots[index].state20 = 5;
            slots[index].flags28 = 0;
            slots[index].byte2E = 0x40;
            slots[index].byte2F = 0;
            slots[index].value24 = 1.0f;
            slots[index].angle2C = (s16)(item->value0D * 32767 / 127);
            return index;
        }
    }
    return -1;
}
