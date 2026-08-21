/* Specification: $S/specs/func_8008A2F0.md */
#include "podcruise/types.h"

struct Func8008A2F0Inner {
    s32 unk0;
    s32 unk4;
};

struct Func8008A2F0Block {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    struct Func8008A2F0Inner *unk8;
    s32 unkC;
};

extern struct Func8008A2F0Block *D_800A7F54;
extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);

void func_8008A2F0(struct Func8008A2F0Inner *arg0) {
    register s32 token;

    token = func_8008CA80();
    D_800A7F54->unk8 = arg0;
    D_800A7F54->unk0 = 1;
    D_800A7F54->unkC = D_800A7F54->unk8->unk4;
    func_8008CAA0(token);
}
