/* Implements the specification in specs/func_8001F48C.md (menu input dispatch for a two-way option). */
#include "podcruise/types.h"

typedef struct Ctx8001F48C {
    /* 0x00 */ u8 unk_00[0x10];
    /* 0x10 */ s32 unk_10;
} Ctx8001F48C;

extern s32 func_80009524(s32, s32);
extern void func_8000955C(s32, s32);
extern void func_8000953C(s32, s32);
extern void func_800092EC(s32, s32, s32);
extern void func_800093B0(s32, s32, s32, s32, s32, s32, s32);

void func_8001F48C(Ctx8001F48C *arg0) {
    if (func_80009524(0, 0x10) == 0) {
        return;
    }
    if (func_80009524(0, 0x20) == 0) {
        return;
    }
    func_8000955C(0, 0x20);
    if (arg0->unk_10 == 0) {
        if (func_80009524(0, 2) == 0) {
            func_8000953C(0, 2);
            func_800092EC(2, 0, 1);
        } else {
            func_800093B0(2, 0, 0x16, 0x17, 0x1E, 0x1F, 0x38);
        }
    } else {
        if (func_80009524(0, 8) == 0) {
            func_8000953C(0, 8);
            func_800092EC(2, 0, 0xF);
        } else {
            func_800093B0(2, 0, 0x29, 0x2E, 0x2F, 0x30, 0xC);
        }
    }
}
