/* Implements the scratchpad specification specs/func_80086CE0.md (menu widget refresh). */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 body[0x170];
} Entry80086CE0;

extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_800387F8(void *, void *);
extern void func_80038950(void *);

extern s32 D_800A6950;
extern void *D_800A6954;
extern void *D_800A6958;
extern void *D_800A695C;
extern void *D_800A6960;
extern Entry80086CE0 D_80120DF0[];
extern u8 D_801217B0[];

void func_80086CE0(s32 mode) {
    if (D_800A6950 != 0) {
        if (mode == 1) {
            if (D_800A6954 != 0) { if (D_800A6954 != 0) { func_800181BC(D_800A6954, 2, -4, 0x10, 3); } }
            if (D_800A695C != 0) { if (D_800A695C != 0) { func_800181BC(D_800A695C, 2, -4, 0x10, 3); } }
            if (D_800A6958 != 0) { if (D_800A6958 != 0) { func_800181BC(D_800A6958, 2, 3, 0x10, 2); } }
            if (D_800A6960 != 0) { if (D_800A6960 != 0) { func_800181BC(D_800A6960, 2, 3, 0x10, 2); } }
        } else {
            if (D_800A6954 != 0) { if (D_800A6954 != 0) { func_800181BC(D_800A6954, 2, 3, 0x10, 2); } }
            if (D_800A695C != 0) { if (D_800A695C != 0) { func_800181BC(D_800A695C, 2, 3, 0x10, 2); } }
            if (D_800A6958 != 0) { if (D_800A6958 != 0) { func_800181BC(D_800A6958, 2, -4, 0x10, 3); } }
            if (D_800A6960 != 0) { if (D_800A6960 != 0) { func_800181BC(D_800A6960, 2, -4, 0x10, 3); } }
        }
    }
    func_80038950(D_801217B0);
    func_800387F8(D_801217B0, &D_80120DF0[mode]);
}
