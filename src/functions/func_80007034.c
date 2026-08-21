/* Recovery evidence: specs/functions/recovered/medium_system_tranche.md. */

#include "podcruise/types.h"

typedef struct PcBootObject {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
} PcBootObject;

extern s32 func_80006FE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800880AC(void *arg0, PcBootObject *arg1);
extern void func_800880E0(void *arg0, void *arg1, s32 arg2);

extern s32 D_800980C0;
extern s32 func_80097FF0;
extern s32 D_8009A2D0[];
extern s32 D_800A8180;
extern s32 D_800A818C;
extern s32 D_800A8198;
extern s32 D_800AFA60;
extern s32 D_800AFA64;
extern s32 D_800AFA6C;
extern s32 D_800AFA70;
extern s16 D_800AFABC;
extern s32 D_800AFE8C;
extern s32 D_800AFE90;
extern s32 D_800AFE94;
extern s32 D_800B0498;
extern s32 D_800B04B0;

void func_80007034(PcBootObject *object) {
    s32 *slot;
    f32 span;

    span = ((f32)object->unk18 * 3.0f) / 60.0f;
    D_800AFE90 = (s32)span;
    if ((f32)D_800AFE90 < span) {
        D_800AFE90 = D_800AFE90 + 1;
    }
    if ((D_800AFE90 & 0xF) != 0) {
        D_800AFE90 = (D_800AFE90 & ~0xF) + 0x10;
    }
    D_800AFE8C = D_800AFE90 - 0x10;
    D_800AFE94 = D_800AFE90 + 0x60;
    func_800880AC(&D_800AFA70, object);

    slot = &D_800AFA60;
    do {
        *slot = func_80006FE4((s32)(unsigned long)&D_800A8180, object->unk14, 1, 0x5DC0);
        slot++;
    } while (slot < &D_800AFA64);

    slot = &D_800AFA64 - 1;
    do {
        slot[1] = func_80006FE4((s32)(unsigned long)&D_800A818C, object->unk14, 1, 8);
        *(s32 *)(unsigned long)slot[1] = func_80006FE4((s32)(unsigned long)&D_800A8198, object->unk14, 1,
                                        D_800AFE94 * 4);
        *(s16 *)(unsigned long)(slot[1] + 4) = 0;
        D_8009A2D0[3] = (s32)(unsigned long)&D_800980C0 - (s32)(unsigned long)&func_80097FF0;
        slot++;
    } while (slot != &D_800AFA6C);

    func_800880E0(&D_800B0498, &D_800B04B0, 0x40);
    D_800AFABC = 0;
}
