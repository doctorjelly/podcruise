/* Recovered per specs/functions/func_80097B80.md (worker specification). */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[5];
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
    /* 0x08 */ u8 unk08;
    /* 0x09 */ u8 unk09;
    /* 0x0A */ u8 pad0A[2];
    /* 0x0C */ u32 unk0C;
} Struct80097B80;

extern Struct80097B80 *D_800A7BA0[];

s32 func_80097B80(Struct80097B80 *object, u32 offset, u32 *output) {
    register u32 status;
    register s32 index;
    Struct80097B80 *previous;

    status = *(volatile u32 *)(unsigned long)0xA4600010;
    while (status & 3) {
        status = *(volatile u32 *)(unsigned long)0xA4600010;
    }
    index = object->unk09;

    if (D_800A7BA0[index] != object) {
        previous = D_800A7BA0[index];
        if (index == 0) {
            if (previous->unk05 != object->unk05) {
                *(volatile u32 *)(unsigned long)0xA4600014 = object->unk05;
            }
            if (previous->unk06 != object->unk06) {
                *(volatile u32 *)(unsigned long)0xA460001C = object->unk06;
            }
            if (previous->unk07 != object->unk07) {
                *(volatile u32 *)(unsigned long)0xA4600020 = object->unk07;
            }
            if (previous->unk08 != object->unk08) {
                *(volatile u32 *)(unsigned long)0xA4600018 = object->unk08;
            }
        } else {
            if (previous->unk05 != object->unk05) {
                *(volatile u32 *)(unsigned long)0xA4600024 = object->unk05;
            }
            if (previous->unk06 != object->unk06) {
                *(volatile u32 *)(unsigned long)0xA460002C = object->unk06;
            }
            if (previous->unk07 != object->unk07) {
                *(volatile u32 *)(unsigned long)0xA4600030 = object->unk07;
            }
            if (previous->unk08 != object->unk08) {
                *(volatile u32 *)(unsigned long)0xA4600028 = object->unk08;
            }
        }
        D_800A7BA0[index] = object;
    }

    *output = *(volatile u32 *)(unsigned long)(0xA0000000 | (object->unk0C | offset));
    return 0;
}
