/* Implements the specification in specs/func_80091FD0.md */
#include "podcruise/types.h"

typedef struct Struct80091FD0 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x59];
    /* 0x65 */ u8 unk65;
} Struct80091FD0;

extern s32 func_800928F0(s32, s32, s32, u8 *, s32);

s32 func_80091FD0(Struct80091FD0 *arg0, u8 arg1) {
    u8 buffer[32];
    s32 i;
    s32 result;

    for (i = 0; i < 32; i++) {
        buffer[i] = arg1;
    }
    result = func_800928F0(arg0->unk04, arg0->unk08, 0x400, buffer, 0);
    if (result == 0) {
        arg0->unk65 = arg1;
    }
    return result;
}
