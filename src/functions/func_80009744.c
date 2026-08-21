/* Independently written from scratchpad spec specs/func_80009744.md. */

#include "podcruise/types.h"

extern s32 D_8009AEE0;
extern f32 D_8009AEE8;
extern s32 D_8009AEEC;
extern s16 D_8009AEFC[5];
extern f32 D_800A8220;

extern s32 func_8003F7B8(s32 key);

void func_80009744(s32 mode, u32 seed) {
    switch (mode) {
    case 0:
        D_8009AEE0 = mode;
        D_8009AEEC = -1;
        break;
    case 1:
        D_8009AEEC = D_8009AEFC[seed % 5];
        D_8009AEE0 = mode;
        if (func_8003F7B8(0x54657374) <= 0) {
            D_8009AEEC = 0x8F;
        }
        break;
    case 2:
        D_8009AEE0 = mode;
        D_8009AEE8 = D_800A8220;
        break;
    case 3:
        D_8009AEE0 = mode;
        D_8009AEE8 = -2.0f;
        break;
    }
}
