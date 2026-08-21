/* Recovered from specification specs/func_80028E78.md (boundary corrected from func_80028E88). */
#include "podcruise/types.h"

typedef struct Ent80028E78 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 pad0C[13];
    s32 unk40;
} Ent80028E78;

extern f32 D_800A25FC[];
extern s16 D_800A2600[];
extern s32 D_800A2198;
extern s32 D_800A4BD0;
extern s32 D_800A4BD8;
extern s32 D_800A4BDC;
extern f32 D_800A9DE8;
extern f32 D_80120BF8;

extern void func_8000A920(s32, s32);
extern void func_8000AB24(s32, s32, s32, s32, u32);
extern void func_800399F0(void);
extern void func_80039B70(void);
extern void func_80039CD8(s32);
extern void *func_8003F800(u32, s32);
extern void func_800469B4(Ent80028E78 *, s32);
extern void func_80060DE4(void *, s32);

s32 func_80028E78(Ent80028E78 *arg0) {
    f32 value;
    s32 result;
    s16 counter;
    void *entry;

    value = D_800A25FC[0];
    D_800A4BD8 = 0;
    result = 0;
    if (255.0f <= value) {
        counter = D_800A2600[0] - 1;
        D_800A2600[0] = counter;
        if (counter <= 0) {
            result = 1;
        }
        value = 255.0f;
    } else {
        value += D_800A9DE8 * D_80120BF8;
    }
    if (255.0f < value) {
        value = 255.0f;
        D_800A2600[0] = 3;
    }
    D_800A25FC[0] = value;
    func_8000AB24(-0x67, 0, 0, 0, (u32)value);
    if (result != 0) {
        D_800A25FC[0] = 0.0f;
        if (D_800A2198 != -1) {
            if (D_800A2198 == 1) {
                if (arg0->unk08 == 0x12) {
                    entry = func_8003F800(0x456C6D6F, arg0->unk40);
                    if (entry != 0) {
                        func_80060DE4(entry, 0);
                    }
                }
            }
            D_800A4BDC = 1;
            D_800A4BD0 = 0;
            func_80039CD8(1);
            func_80039B70();
            func_800399F0();
            func_800469B4(arg0, D_800A2198);
        } else {
            func_8000A920(-0x67, 0);
            D_800A4BD8 = 1;
            D_800A4BDC = 0;
            func_80039CD8(1);
            func_80039B70();
            func_800399F0();
            return 1;
        }
    }
    return 0;
}
