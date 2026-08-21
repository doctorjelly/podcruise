/* Independently written from scratchpad spec specs/func_80009820.md. */

#include "podcruise/types.h"

extern u8 D_8009B77F;
extern s32 D_8009AEE0;
extern f32 D_8009AEE4;
extern f32 D_8009AEE8;
extern s32 D_8009AEEC;
extern s32 D_8009AEF0;
extern s32 D_8009AEF8;
extern f32 D_8009AF20;
extern f32 D_8009AF24;
extern f32 D_800A8224;
extern f32 D_800A8228;
extern f64 D_80120BF0;

extern void func_8000787C(f32 level);
extern void func_80008B14(s32 id, s32 channel, f32 rate, f32 volume, s32 flag);
extern void func_80009744(s32 mode, s32 id);
extern f32 func_8002F060(void);

void func_80009820(void) {
    s32 pending;
    s32 armed;
    f32 scale;
    f32 level;
    f32 pad[6];
    s32 id;

    (void)pad;

    func_8000787C(1.0f - (f32)(u32)D_8009B77F / 255.0f);

    scale = 1.0f - func_8002F060() * D_800A8224;
    if (func_8002F060() > 0.0f) {
        scale = D_800A8228;
    }

    level = scale * D_8009AEE4;
    D_8009AEF8 = (s32)((f64)D_8009AEF8 + D_80120BF0);
    D_8009AF24 = (f32)((f64)D_8009AF24 + D_80120BF0);

    armed = (D_8009AEF0 == 0x22) ? 1 : 0;

    if (D_8009AF20 > 0.0f) {
        D_8009AF20 = (f32)((f64)D_8009AF20 - D_80120BF0);
        if (D_8009AF20 <= 0.0f) {
            if (armed == 0) {
                D_8009AF20 = 0.0f;
                level = 1.0f;
                func_80008B14(D_8009AEF0, 7, 0.25f, level, 0);
            }
        }
    }

    if (armed != 0) {
        if (D_8009AF20 <= 0.0f) {
            if (func_8002F060() == 0.0f) {
                if (D_8009AF24 < 9.0f) {
                    level = (9.0f - D_8009AF24) * 0.5f;
                    if (level > 1.0f) {
                        level = 1.0f;
                    }
                    func_80008B14(D_8009AEF0, 7, 0.25f, level, 1);
                } else {
                    D_8009AEF0 = -1;
                }
            }
        }
    }

    switch (D_8009AEE0) {
    case 1:
        D_8009AEE4 = 1.0f;
        id = D_8009AEEC;
        if (id >= 0) {
            func_80008B14(id, 7, 0.25f, level, 1);
            id = D_8009AEEC;
        }
        func_80009744(3, id);
        break;
    case 2:
    case 3:
        D_8009AEE4 = (f32)((f64)D_8009AEE4 + (f64)D_8009AEE8 * D_80120BF0);
        pending = 1;
        if (D_8009AEE4 <= 0.0f) {
            pending = 0;
            func_80009744(0, -1);
        }
        if (pending != 0) {
            if (D_8009AEEC >= 0) {
                func_80008B14(D_8009AEEC, 7, 0.25f, level, 1);
            }
        }
        break;
    }
}
