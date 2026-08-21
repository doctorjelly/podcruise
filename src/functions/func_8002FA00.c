/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */

#include "podcruise/types.h"

extern s32 D_800A2864;
extern s32 D_800A2868;
extern s32 D_800A68A0;
extern u32 D_800D9DD8[10];

extern void func_8002E034(void);
extern void func_80030574(u32 limit);
extern void func_80007E80(s32 arg0);

void func_8002FA00(s32 arg0) {
    u32 *slot;
    s32 count;

    if (arg0 <= D_800A2868) {
        if (D_800A68A0 == 0) {
            func_8002E034();
            D_800A68A0 = 1;
        }
    }
    D_800A2868 = arg0;
    D_800D9DD8[arg0] = D_800D9DD8[arg0 - 1];
    func_80030574(D_800D9DD8[arg0]);
    func_80007E80(1);
    count = D_800A2868;
    if (count < 9) {
        slot = &D_800D9DD8[9];
        do {
            *slot = 0;
            slot--;
        } while (slot > &D_800D9DD8[count]);
    }
    D_800A2864 = 0;
}
