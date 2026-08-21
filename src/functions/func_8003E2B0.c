/* Recovered from specification: specs/func_8003E2B0.md (worker scratchpad) */
#include "podcruise/types.h"

extern u8 D_800A498C[];
extern s32 D_800A4A8C;
extern f32 D_800A4A90;
extern f32 D_800A4A94;
extern f32 D_800A4A98;
extern u8 D_800AAB28[];
extern f64 D_800AAB88;
extern f64 D_80120BF0;

extern void func_80011ECC(s16, s16);
extern void func_80011EE8(s16 *, s16 *);
extern void func_80011F04(s16, s16, s16, s16);
extern void func_80013DC0(u8 *);
extern s32 func_80082BE0(void);

void func_8003E2B0(void) {
    f32 level;
    s16 first;
    s16 second;
    s16 amount;

    if (D_800A4A90 > 0.0f) {
        if (D_800A498C[0] != 0) {
            level = D_800A4A90 * 4.0;
            if (level > 1.0) {
                level = 1.0f;
            }
            level = 1.0 - level;
            if (D_800A4A94 > 0.0f) {
                amount = 255.0f * D_800A4A94;
                func_80011F04(amount, 255, amount, 255);
            } else {
                func_80011F04(0, (f32)func_80082BE0() / 2147483648.0f * 55.0f + 200.0f, 0, 255);
            }
            func_80011ECC(26, 20.0f * level + 215.0f);
            func_80013DC0(D_800A498C);
            if (D_800A4A8C != 0) {
                func_80011F04(0, D_800A4A98 * D_800AAB88, 0, 255);
                func_80011EE8(&first, &second);
                func_80011ECC(first, second + 5);
                func_80013DC0(D_800AAB28);
            }
            D_800A4A94 = D_800A4A94 - D_80120BF0 * (f64)2;
            D_800A4A98 = D_800A4A98 - D_80120BF0 * (f64)2;
            if (D_800A4A98 < 0.0f) {
                D_800A4A98 = 1.0f;
            }
        }
        D_800A4A90 = D_800A4A90 - D_80120BF0;
    }
}
