/* Recovered from specification: specs/func_80028E78.md */
#include "podcruise/types.h"

typedef struct Unknown80028E78 {
    u8 pad00[0x8];
    s32 unk08;
    u8 pad0C[0x34];
    s32 unk40;
} Unknown80028E78;

extern f32 D_800A25FC;
extern s16 D_800A2600;
extern s32 D_800A2198;
extern s32 D_800A4BD0;
extern s32 D_800A4BD8;
extern s32 D_800A4BDC;
extern f32 D_800A9DE8;
extern f32 D_80120BF8;

extern s32 func_8000A920();
extern s32 func_8000AB24();
extern s32 func_800399F0();
extern s32 func_80039B70();
extern s32 func_80039CD8();
extern s32 func_8003F800();
extern s32 func_800469B4();
extern s32 func_80060DE4();

s32 func_80028E78(Unknown80028E78 *arg0) {
    f32 value;
    s16 count;
    s32 done;

    value = D_800A25FC;
    done = 0;
    D_800A4BD8 = 0;
    if (value >= 255.0f) {
        count = D_800A2600 - 1;
        D_800A2600 = count;
        if (count <= 0) {
            done = 1;
        }
        value = 255.0f;
    } else {
        value = D_800A9DE8 * D_80120BF8 + value;
    }
    if (value > 255.0f) {
        value = 255.0f;
        D_800A2600 = 3;
    }
    D_800A25FC = value;
    func_8000AB24(-103, 0, 0, 0, (u32)value);
    if (done != 0) {
        D_800A25FC = 0.0f;
        if (D_800A2198 != -1) {
            if ((D_800A2198 == 1) && (arg0->unk08 == 0x12)) {
                done = func_8003F800(0x456C6D6F, arg0->unk40);
                if (done != 0) {
                    func_80060DE4(done, 0);
                }
            }
            D_800A4BDC = 1;
            D_800A4BD0 = 0;
            func_80039CD8(1);
            func_80039B70();
            func_800399F0();
            func_800469B4(arg0, D_800A2198);
            return 0;
        }
        func_8000A920(-103, 0);
        D_800A4BD8 = 1;
        D_800A4BDC = 0;
        func_80039CD8(1);
        func_80039B70();
        func_800399F0();
        return 1;
    }
    return 0;
}
