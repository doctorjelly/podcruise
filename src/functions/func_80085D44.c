/* Implements specification specs/func_80085D44.md (recovered behavior). */
#include "podcruise/types.h"

extern s32 D_8009B7D0;
extern s32 D_8009B7D8;
extern s32 D_800A6780;
extern s32 D_800A68A0;
extern s32 D_800A68A4;
extern s32 D_800A6948;
extern s32 D_800D76F0;
extern s32 D_800D9DB4;

extern void func_800118F8(void);
extern void func_80084D44(s32, s32);
extern f32 func_80085AB4(void);
extern s32 func_8008C770(void);

void func_80085D44(void) {
    s32 saved;

    saved = D_800A68A4;
    while (func_8008C770() == D_800D9DB4) {
    }
    if ((D_8009B7D8 & 0x200) && (D_8009B7D0 > 0) && ((D_800D76F0 & 0x1100) == 0x1100)) {
        func_80085AB4();
    } else if (D_800A6948 == 0) {
        func_800118F8();
    }
    D_800A6948 = 0;
    func_80084D44((s16)saved, 0);
    D_800A6780 = 0;
    D_800A68A0 = 0;
}
