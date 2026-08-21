/* Recovery evidence: specs/functions/recovered/medium_system_tranche.md. */
#include "podcruise/types.h"

typedef struct Rec80031134 {
    /* 0x000 */ u8 pad00[0x20];
    /* 0x020 */ u8 unk20[0x78 - 0x20];
    /* 0x078 */ s32 unk78;
    /* 0x07C */ u8 pad7C[0x108 - 0x7C];
    /* 0x108 */ u8 unk108[4];
} Rec80031134;

extern u8 D_800D69A0[];
extern u8 D_800D69E0[];
extern u8 D_800D6A20[];
extern u8 D_800D6A60[];
extern u8 D_800D6AA0[];
extern u8 D_800D6AE0[];
extern u8 D_800D6B20[];
extern u8 D_800D6B60[];
extern u8 D_800D6BA0[];
extern u8 D_800D6BE0[];

extern void func_8000ACC0(void);
extern void func_8000AEFC(s16, s32, void *, s32);
extern void func_8000B02C(s16, void *, s32);
extern void func_8000AF4C(s16, f32, f32, f32, f32, f32, f32);
extern void func_8000B1B0(s32);
extern s32 func_8003F7B8(s32);
extern Rec80031134 *func_8003F714(s32, s32);

void func_80031134(void) {
    s16 index;
    s32 tag;
    Rec80031134 *record;

    index = 7;
    func_8000ACC0();
    func_8000AEFC(0, 1, D_800D69A0, 0);
    func_8000AEFC(1, 1, D_800D69E0, 0);
    func_8000AEFC(2, 1, D_800D6A20, 0);
    func_8000AEFC(3, 1, D_800D6A60, 0);
    func_8000AEFC(4, 1, D_800D6AA0, 0);
    func_8000AEFC(5, 1, D_800D6AE0, 0);
    func_8000AEFC(6, 1, D_800D6B20, 0);
    func_8000AEFC(7, 1, D_800D6B60, 0);
    func_8000AEFC(8, 1, D_800D6BA0, 0);
    func_8000AEFC(9, 1, D_800D6BE0, 0);
    tag = 0x634D616E;
    for (; index < 0x20 && index - 7 < func_8003F7B8(tag); index++) {
        record = func_8003F714(tag, index - 7);
        func_8000AEFC(index, 3, record->unk20, 0);
        func_8000B02C(index, record->unk108, 0);
        func_8000AF4C(index, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
        record->unk78 = index;
    }
    func_8000B1B0(8);
}
