/* Specification: scratchpad/specs/func_8007C4C8.md */
#include "podcruise/types.h"

typedef struct PcTrigOwner {
    u8 unk00[0x20];
    void *unk20;
    s16 unk24;
} PcTrigOwner;

typedef struct PcTrig {
    u8 unk00[6];
    s16 unk06;
    s32 unk08;
    s32 unk0C;
    u8 unk10[0x20];
    f32 unk30[3];
    void *unk3C;
    void *unk40;
    void *unk44;
    u8 unk48[4];
    PcTrigOwner *unk4C;
} PcTrig;

extern s32 func_8003F7B8(u32);
extern PcTrig *func_8003F800(u32, s32);
extern PcTrig *func_8003FBD4(u32);
extern void *func_80006D5C(void *, s32);
extern void func_80006E74(void *, f32);
extern void func_80006EB4(void *, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_80017874(f32 *);
extern s32 func_8005EEFC(void);
extern void func_80082C80(void *, f32 *, s32, f32 *);

PcTrig *func_8007C4C8(PcTrigOwner *owner) {
    PcTrig *trig;
    s32 count;
    s32 i;
    f32 workC[5];
    f32 workB[12];
    f32 matrix[16];

    count = func_8003F7B8(0x54726967);
    for (i = 0; i < count; i++) {
        trig = func_8003F800(0x54726967, i);
        if (trig != 0) {
            if (!(trig->unk06 & 0x100)) {
                if (owner == trig->unk4C) {
                    if (!(trig->unk0C & 2)) {
                        return trig;
                    }
                    return 0;
                }
            }
        }
    }
    trig = func_8003FBD4(0x54726967);
    if (trig == 0) {
        return 0;
    }
    trig->unk4C = owner;
    trig->unk3C = owner->unk20;
    trig->unk08 = owner->unk24;
    trig->unk40 = func_80006D5C(trig->unk3C, 8);
    trig->unk44 = func_80006D5C(trig->unk3C, 9);
    if (trig->unk3C != 0) {
        func_80017874(matrix);
        func_80082C80(trig->unk3C, workB, func_8005EEFC(), matrix);
        func_80015288(trig->unk30, workC);
    }
    if (trig->unk40 != 0) {
        func_80006E74(trig->unk40, 0.0f);
        func_80006EB4(trig->unk40, 0.0f);
    }
    if (trig->unk44 != 0) {
        func_80006E74(trig->unk44, 0.0f);
        func_80006EB4(trig->unk44, 0.0f);
    }
    return trig;
}
