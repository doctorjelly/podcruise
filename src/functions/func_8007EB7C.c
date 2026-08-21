/* Recovered from specification scratchpad specs/func_8007EB7C.md. */

#include "podcruise/types.h"

typedef struct {
    f32 unk_00[3];
} Vec3;

extern s32 func_80082BE0(void);
extern void func_80008B14(s32 arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4);
extern void func_80008BC4(s32 arg0, s16 arg1, f32 arg2, f32 arg3, void *arg4,
                          s32 arg5, s32 arg6, f32 arg7, f32 arg8);
extern void *func_80065810(s32 arg0, s32 arg1, f32 arg2, f32 *arg3, f32 arg4);

extern f32 D_800A66E0[];
extern f32 D_800ADC38[];
extern Vec3 D_8011DC50[];
extern f64 D_80120BF0;

void func_8007EB7C(s32 arg0, s32 arg1) {
    f32 vector[3];
    Vec3 *slot;
    f32 scale;
    f32 threshold;
    f32 amount;
    f32 offset;
    s32 identifier;
    s32 wasAbove;
    s32 i;

    if (arg1 != 0) {
        for (i = 0; i < 8; i++) {
            D_800A66E0[i] = -1.0f;
        }
        return;
    }

    scale = D_800ADC38[0];
    threshold = D_800ADC38[1];
    for (i = 0; i < 8; i++) {
        if (D_800A66E0[i] > 0.0f) {
            wasAbove = threshold >= D_800A66E0[i];
            D_800A66E0[i] = (f32)(D_800A66E0[i] - D_80120BF0);
            if (!wasAbove) {
                if (D_800A66E0[i] <= threshold) {
                    identifier = 0x43;
                    amount = (f32)func_80082BE0() / 2147483648.0f * D_800ADC38[2] + D_800ADC38[3];
                    offset = (f32)func_80082BE0() / 2147483648.0f * scale + 0.5f;
                    if (arg0 == 6) {
                        identifier = 0x6E;
                        offset = (f32)func_80082BE0() / 2147483648.0f * scale + threshold;
                    }
                    func_80008B14(identifier, 7, amount, offset, 0);
                }
            }
            if (D_800A66E0[i] <= 0.0f) {
                slot = &D_8011DC50[i];
                amount = (f32)func_80082BE0() / 2147483648.0f * D_800ADC38[4] + D_800ADC38[5];
                offset = (f32)func_80082BE0() / 2147483648.0f * scale + threshold;
                func_80008BC4(0x43, 6, amount, offset, slot, 0, 0, 1000.0f, 2000.0f);
                vector[0] = slot->unk_00[0];
                vector[1] = slot->unk_00[1];
                vector[2] = slot->unk_00[2];
                func_80065810(2, 0, 5.0f, vector, 5.0f);
            }
        }
    }
}
