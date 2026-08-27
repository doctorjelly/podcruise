/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

typedef struct Struct80089E50 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x44];
    /* 0x50 */ s32 unk50;
    /* 0x54 */ u8 pad54[0x8];
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ u8 pad60[0x5];
    /* 0x65 */ u8 unk65;
} Struct80089E50;

typedef struct Entry80089E50 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u8 pad06[0x2a];
} Entry80089E50;

extern s32 func_80091280(Struct80089E50 *object);
extern s32 func_80091FD0(Struct80089E50 *object, u8 mode);
extern s32 func_80092050(s32 first, s32 second, u16 index, Entry80089E50 *entry);

s32 func_80089E50(Struct80089E50 *object, s32 *totalOut, s32 *usedOut) {
    Entry80089E50 entry;
    s32 index;
    s32 used;
    register s32 result;

    used = 0;
    if (!(object->unk00 & 1)) {
        return 5;
    }

    result = func_80091280(object);
    if (result != 0) {
        return result;
    }

    if (object->unk65 != 0) {
        result = func_80091FD0(object, 0);
        if (result != 0) {
            return result;
        }
    }

    for (index = 0; index < object->unk50; index++) {
        result = func_80092050(object->unk04, object->unk08,
                              (u16)(object->unk5C + index), &entry);
        if (result != 0) {
            return result;
        }
        if (entry.unk04 != 0 && entry.unk00 != 0) {
            used++;
        }
    }

    *usedOut = used;
    *totalOut = object->unk50;
    return 0;
}
