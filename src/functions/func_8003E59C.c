/* Implements specs/functions/recovered/late_mismatch_audit_tranche.md. */
#include "podcruise/types.h"

extern s32 D_800A4984;
extern f32 D_800A59B0[];
extern f32 D_800AAB90;
extern f32 D_800AAB94;
extern s16 D_80118958[];
extern u8 D_80118C50[];

extern s32 func_8002F054(void);
extern s32 func_80082BE0(void);
extern void func_80011EA4(s16);
extern void func_80011F04(s16, s16, s16, s16);
extern void func_800141EC(s32);
extern void func_80014568(s16, s16, s32);
extern void func_80014C98(void);

void func_8003E59C(void) {
    f64 pad; /* reserves frame slot */
    f32 alpha1;
    f32 alpha2;
    register f32 scale;
    f32 full;
    register s32 previous;
    volatile f32 *level;
    register s32 index;
    register u32 mode;
    register s32 kind1;
    register s32 kind2;
    register u32 other;

    (void)&pad;
    kind1 = 1;
    kind2 = 2;
    other = 0x58;
    if (func_8002F054() == 0) {
        scale = (f32)2147483648.0;
        alpha1 = (f32)func_80082BE0() / scale / 2.0f + 0.5f;
        alpha2 = (f32)func_80082BE0() / scale / 2.0f + 0.5f;
    } else {
        alpha1 = D_800AAB90;
        alpha2 = D_800AAB94;
    }

    if (D_800A4984 != 0) {
        func_80011EA4(0);
        func_800141EC(0x2E);
        full = 255.0f;
        level = D_800A59B0;
        mode = 0x2E;
        func_80011F04(0, 255, 0, full * alpha1 * level[0]);
        for (index = 0, previous = 0; index < D_800A4984; index++) {
            if (previous != D_80118C50[index]) {
                previous = D_80118C50[index] & 0xFF;
                if (kind1 == previous) {
                    func_80011F04(0, 255, 255, full * level[0]);
                } else if (kind2 == previous) {
                    func_80011F04(255, 255, 0, full * alpha2 * level[0]);
                } else if (previous >= 3 || previous < 5) {
                    if (other != mode) {
                        func_800141EC(0x58);
                        mode = 0x58;
                    }
                    if (previous == 3) {
                        func_80011F04(0, 0, 255, full * level[0]);
                    } else {
                        func_80011F04(100, 255, 100, full * level[0] * alpha2);
                    }
                }
            }
            func_80014568(D_80118958[index * 2], D_80118958[index * 2 + 1], 0x70);
        }
        func_80014C98();
        D_800A4984 = 0;
    }
}
