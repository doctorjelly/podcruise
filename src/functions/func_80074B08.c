/* Recovered from specification specs/func_80074B08.md (worker-authored). */
#include "podcruise/types.h"

typedef struct Sub80074B08 {
    /* 0x000 */ void *unk00;
    /* 0x004 */ void *unk04;
    /* 0x008 */ void *unk08;
    /* 0x00C */ u8 pad0C[0x18 - 0x0C];
    /* 0x018 */ void *unk18;
    /* 0x01C */ u8 pad1C[0x28 - 0x1C];
    /* 0x028 */ void *unk28;
    /* 0x02C */ void *unk2C;
    /* 0x030 */ u8 pad30[0xF8 - 0x30];
    /* 0x0F8 */ void *unkF8;
    /* 0x0FC */ void *unkFC;
    /* 0x100 */ u8 pad100[0x10C - 0x100];
    /* 0x10C */ void *unk10C;
    /* 0x110 */ void *unk110;
} Sub80074B08;

typedef struct Obj80074B08 {
    /* 0x000 */ u8 pad00[0x60];
    /* 0x060 */ u32 unk60;
    /* 0x064 */ u32 unk64;
    /* 0x068 */ u8 pad68[0x344 - 0x68];
    /* 0x344 */ Sub80074B08 *unk344;
} Obj80074B08;

extern void func_800181BC(void *, s32, s32, s32, s32);

void func_80074B08(Obj80074B08 *obj) {
    if ((obj->unk60 & 0x20) || (obj->unk64 & 0x04000000)) {
        if (obj->unk64 & 0x8000) {
            if (obj->unk344->unk04 != 0) {
                func_800181BC(obj->unk344->unk04, 2, -4, 0x10, 3);
            }
            if (obj->unk344->unk18 != 0) {
                func_800181BC(obj->unk344->unk18, 2, -4, 0x10, 3);
            }
            if (obj->unk344->unk28 != 0) {
                func_800181BC(obj->unk344->unk28, 2, -4, 0x10, 3);
            }
            if (obj->unk344->unkF8 != 0) {
                func_800181BC(obj->unk344->unkF8, 2, -4, 0x10, 3);
            }
            if (obj->unk344->unk10C != 0) {
                func_800181BC(obj->unk344->unk10C, 2, -4, 0x10, 3);
            }
        } else if (obj->unk64 & 0x10000) {
            if (obj->unk344->unk08 != 0) {
                func_800181BC(obj->unk344->unk08, 2, -4, 0x10, 3);
            }
            if (obj->unk344->unk18 != 0) {
                func_800181BC(obj->unk344->unk18, 2, -4, 0x10, 3);
            }
            if (obj->unk344->unk2C != 0) {
                func_800181BC(obj->unk344->unk2C, 2, -4, 0x10, 3);
            }
            if (obj->unk344->unkFC != 0) {
                func_800181BC(obj->unk344->unkFC, 2, -4, 0x10, 3);
            }
            if (obj->unk344->unk110 != 0) {
                func_800181BC(obj->unk344->unk110, 2, -4, 0x10, 3);
            }
        }
    }
}
