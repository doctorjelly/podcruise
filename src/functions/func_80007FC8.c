/* Implements specification specs/func_80007FC8.md (indexed handle lookup). */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0xE];
    s16 count;
    s32 items[1];
} Table80007FC8;

typedef struct {
    u8 pad0[0xC];
    Table80007FC8* table;
} Owner80007FC8;

extern s32 D_8009A2BC;

extern Owner80007FC8 *func_80007CE4(s32 handle);
extern s32 func_800894D0(s32, s32);

s32 func_80007FC8(s32 arg0) {
    Owner80007FC8* owner;
    Table80007FC8* table;
    s32 result = -1;
    s32 index;

    owner = func_80007CE4(arg0);
    if (owner == 0) {
        return -1;
    }
    index = arg0 & 0x7FFF;
    table = owner->table;
    if ((index >= 0) && (index < table->count)) {
        result = func_800894D0(D_8009A2BC, table->items[index]);
    }
    return result;
}
