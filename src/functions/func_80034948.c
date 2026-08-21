/* Independently written from scratchpad spec specs/func_80034954.md. */

#include "podcruise/types.h"

extern s16 *func_80033E08(void);
extern void func_800344F4(s16 *destination, f32 source[4][4]);
extern void func_80034650(s16 *destination, f32 source[4][3]);

extern s32 D_800A3FF0;
extern f32 D_80112E60[4][4];
extern f32 D_80112EA0[][4][3];
extern s16 *D_801134D0;
extern s16 *D_801134D4;

void func_80034948(void) {
    f32 (*source)[3];

    source = D_80112EA0[D_800A3FF0];
    D_801134D0 = func_80033E08();
    func_80034650(D_801134D0, source);
    D_801134D4 = func_80033E08();
    func_800344F4(D_801134D4, D_80112E60);
}
