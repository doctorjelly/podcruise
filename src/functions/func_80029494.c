/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

extern s32 func_80083D80(s32, f32 *, s32);
extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);

extern void *D_8011A544;
extern f32 D_800A4FCC[];
extern f32 D_800D6D90[];
extern f32 D_800D6D9C[];
extern f32 D_800D6DA8[];
extern f32 D_800D6DB4[];
extern f32 D_800D6DB8;
extern f32 D_800D6DC0[];
extern f32 D_800D6DCC[];
extern f32 D_800D6DD0;

void func_80029494(void) {
    void *owner;

    owner = D_8011A544;
    if (func_80083D80(*(s32 *)((u8 *)owner + 0x100), D_800D6D90, 0) == 0) {
        func_80015268(D_800D6D90, 0.0f, 0.0f, 0.0f);
        func_80015268(D_800D6D9C, -10.0f, -10.0f, -10.0f);
    } else {
        func_80015268(D_800A4FCC, D_800D6D90[3] + 100.0f,
                      (f32)((D_800D6D90[1] + D_800D6D90[4]) * 0.5), -157.0f);
    }
    if (func_80083D80(*(s32 *)((u8 *)owner + 0xF8), D_800D6DA8, 0) == 0) {
        func_80015288(D_800D6DA8, D_800D6D90);
        func_80015288(D_800D6DB4, D_800D6D9C);
    }
    if (func_80083D80(*(s32 *)((u8 *)owner + 0xFC), D_800D6DC0, 0) == 0) {
        func_80015288(D_800D6DC0, D_800D6D90);
        func_80015288(D_800D6DCC, D_800D6D9C);
        D_800D6DD0 = (D_800D6D90[1] + D_800D6D90[4]) * 0.5f;
        D_800D6DB8 = (D_800D6D90[1] + D_800D6D90[4]) * 0.5f;
        D_800D6D90[1] = (D_800D6D90[1] + D_800D6D90[4] * 5.0f) / 6.0f;
    }
}
