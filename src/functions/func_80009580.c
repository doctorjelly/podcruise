/* Specification: scratchpad specs/func_80009580.md */
#include "podcruise/types.h"

extern f32 func_8002F060(void);
extern void func_800092EC(s32, s32, s32);

extern f32 D_8009AD10[8];
extern f32 D_8009AD30[23];
extern f32 D_8009AD8C[];
extern s32 D_8009ADE8;
extern s32 D_8009ADEC;
extern s32 D_8009ADF0;
extern f64 D_80120BF0;

void func_80009580(void) {
    f32 *p;
    f32 *q;
    f32 *end;

    if (0.0f < func_8002F060()) {
        D_8009ADE8 = -1;
    }
    for (p = D_8009AD10; p < &D_8009AD10[8]; p++) {
        if (0.0f <= *p) {
            *p = *p - D_80120BF0;
            if (*p <= 0.0f) {
                if (D_8009ADE8 != -1) {
                    func_800092EC(D_8009ADEC, D_8009ADF0, D_8009ADE8);
                    D_8009ADE8 = -1;
                }
            }
        }
    }
    q = D_8009AD30; end = D_8009AD8C;
    do {
        if (0.0f <= *q) {
            *q = *q - D_80120BF0;
            if (*q <= 0.0f) {
                if (D_8009ADE8 != -1) {
                    func_800092EC(D_8009ADEC, D_8009ADF0, D_8009ADE8);
                    D_8009ADE8 = -1;
                }
            }
        }
        q++;
    } while (q != end);
}
