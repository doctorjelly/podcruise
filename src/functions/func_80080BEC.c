/* Implements the specification in specs/func_80080BEC.md (per-frame object update step). */
#include "podcruise/types.h"

typedef struct Obj80080BEC {
    /* 0x0000 */ u8 unk_000[0xAC];
    /* 0x00AC */ u8 unk_0AC[0x30];
    /* 0x00DC */ f32 unk_0DC;
    /* 0x00E0 */ u8 unk_0E0[0xC];
    /* 0x00EC */ s32 unk_0EC;
    /* 0x00F0 */ s32 unk_0F0;
    /* 0x00F4 */ s32 unk_0F4;
    /* 0x00F8 */ s32 unk_0F8;
    /* 0x00FC */ s32 unk_0FC;
    /* 0x0100 */ s32 unk_100;
    /* 0x0104 */ u8 unk_104[0x8];
    /* 0x010C */ s16 unk_10C;
    /* 0x010E */ s16 unk_10E;
    /* 0x0110 */ u8 unk_110[0x4];
    /* 0x0114 */ s32 unk_114;
    /* 0x0118 */ u8 unk_118[0x1DCC];
    /* 0x1EE4 */ s32 unk_1EE4;
} Obj80080BEC;

extern void func_80080498(Obj80080BEC *, s32, s32 *, s32 *);
extern s32 func_80080408(void *);
extern f32 func_80080350(void *);
extern s32 func_8007F22C(void *, void *);
extern s32 func_8007F23C(void *, void *);
extern s32 func_800807E0(Obj80080BEC *);
extern void func_800808E0(Obj80080BEC *);
extern s32 func_80080A1C(Obj80080BEC *, s32);

s32 func_80080BEC(Obj80080BEC *obj, s32 arg1) {
    s32 flagA;
    s32 flagB;
    s32 state;
    s32 result;

    func_80080498(obj, arg1, &flagA, &flagB);

    obj->unk_0F0 = obj->unk_0EC;
    obj->unk_0EC = func_80080408(&obj->unk_0AC);
    obj->unk_0DC = func_80080350(&obj->unk_0AC);
    obj->unk_0F8 = func_8007F22C(&obj->unk_0AC, &obj->unk_0F4);
    obj->unk_100 = func_8007F23C(&obj->unk_0AC, &obj->unk_0FC);

    if (obj->unk_0F0 != obj->unk_0EC) {
        obj->unk_1EE4 = 0;
    }

    state = func_800807E0(obj);
    func_800808E0(obj);
    result = func_80080A1C(obj, (flagA != 0) || (state == 1));

    if (flagB != 0) {
        obj->unk_114 = 0;
        obj->unk_10C = obj->unk_10C + 1;
    }
    if (flagA != 0) {
        obj->unk_10C = 0;
        if (flagB == 0) {
            if (obj->unk_114 < 200) {
                obj->unk_114 = obj->unk_114 + 1;
            }
        }
    }
    obj->unk_10E = state;
    return result;
}
