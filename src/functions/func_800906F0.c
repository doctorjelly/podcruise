/* Independently written from $S/specs/func_800906F0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ long long unk08;
    /* 0x10 */ long long unk10;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
} Entry;

extern Entry **D_800A7FC0;

extern void func_80093FB4(long long arg0);
extern long long func_80094028(Entry *arg0);

s32 func_800906F0(Entry *arg0, long long arg1, long long arg2, s32 arg3, s32 arg4) {
    long long result;

    arg0->unk00 = 0;
    arg0->unk04 = 0;
    arg0->unk08 = arg2;

    if (arg1 != 0) {
        arg0->unk10 = arg1;
    } else {
        arg0->unk10 = arg2;
    }

    arg0->unk18 = arg3;
    arg0->unk1C = arg4;

    result = func_80094028(arg0);
    if (D_800A7FC0[0] == arg0) {
        func_80093FB4(result);
    }
    return 0;
}
