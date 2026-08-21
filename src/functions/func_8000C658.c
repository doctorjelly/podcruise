/* Independently written from specs/func_8000C658.md. */

#include "podcruise/types.h"

extern s32 D_8009B7DC;
extern s32 D_8009B7F4[];
extern s32 D_8009B800;
extern s32 D_800D5718[];
extern s32 D_800D578C;

void func_8000C658(void) {
    D_8009B7F4[D_8009B800] = D_8009B7DC;
    if (D_800D578C > 0) {
        D_800D578C = D_800D578C - 1;
    }
    D_8009B800 = D_800D5718[D_800D578C];
    D_8009B7DC = D_8009B7F4[D_8009B800];
}
