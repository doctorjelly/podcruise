/* Independently written from scratchpad spec specs/func_800319F4.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u16 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
} PcRequest;

extern PcRequest D_800A2870[];
extern s32 D_800A290C[];
extern s16 D_800DB8A8[][14];

extern void func_800314DC(s32 index, u16 value, s32 arg2, s32 arg3);

void func_800319F4(s32 arg0, s32 arg1) {
    if (arg1 >= 13) {
        while (1) {
        }
    }

    if (arg1 < D_800A290C[arg0]) {
        return;
    }
    if (arg1 == D_800A290C[arg0]) {
        if (D_800A2870[arg1].unk04 != 0) {
            return;
        }
        if (D_800DB8A8[arg0][0] != 0) {
            return;
        }
    }

    D_800A290C[arg0] = arg1;
    func_800314DC(arg0, D_800A2870[arg1].unk00, D_800A2870[arg1].unk04,
                  D_800A2870[arg1].unk08);
}
