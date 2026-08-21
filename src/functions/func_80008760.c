/* Specification: $S/specs/func_80008760.md */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    f32 unk14;
    s32 unk18;
    s16 unk1C;
    s16 unk1E;
} SlotB05;

extern u8 D_8009B77F;
extern f32 D_800A81E0;
extern SlotB05 D_800D2038[8];
extern SlotB05 D_800D2138;
extern u8 D_80113685;
extern u8 D_80113686;
extern s32 D_80113688;
extern s32 D_80120BE8;

extern s32 func_80008718(s32);

void func_80008760(s32 arg0, s16 arg1, f32 arg2, f32 arg3, s16 arg4, s32 arg5) {
    SlotB05 *slot;
    s32 pad0[2];
    s32 pad2;
    f32 scale;
    s32 pad[4];
    s32 i;
    s32 best;


    (void)pad0; (void)pad2; (void)pad;

    if (arg5 != 0) {
        scale = 1.0f - (f32)(u32)D_8009B77F / 255.0f;
    } else {
        scale = 1.0f;
    }

    if (func_80008718(arg0) != 0) {
        arg3 *= (f32)(u32)D_80113686 / 255.0f;
    } else {
        arg3 *= (f32)(u32)D_80113685 / 255.0f;
    }

    if (func_80008718(arg0) != 0) {
        arg1 = 8;
    }

    arg3 = arg3 * scale;
    if (arg3 == 0.0f) {
        return;
    }

    arg2 = arg2 * (f32)2.0;
    arg3 = arg3 * D_800A81E0;
    if ((D_80113688 & 1) == 0) {
        arg4 = 0x40;
    }

    if (arg0 < 0) {
        return;
    }

    if (arg5 != 0) {
        for (i = 0; i < 8; i++) {
            if (D_800D2038[i].unk08 != 0 && arg0 == D_800D2038[i].unk04) {
                if (!((f32)D_800D2038[i].unk18 <= arg3) && D_80120BE8 == D_800D2038[i].unk0C) {
                    return;
                }
                D_800D2038[i].unk14 = arg2;
                D_800D2038[i].unk1C = arg4;
                D_800D2038[i].unk10 = arg1;
                D_800D2038[i].unk18 = (s32)arg3;
                D_800D2038[i].unk0C = D_80120BE8;
                return;
            }
        }
    }

    best = -1;
    for (i = 0; i < 8; i++) {
        if (D_800D2038[i].unk00 == -1 && best == -1) {
            best = i;
        }
    }

    if (best == -1) {
        s32 low = arg1;
        for (i = 0; i < 8; i++) {
            if (D_800D2038[i].unk10 < low) {
                low = D_800D2038[i].unk10;
                best = i;
            }
        }
    }

    if (best != -1) {
        slot = &D_800D2038[best];
        slot->unk04 = arg0;
        slot->unk00 = -2;
        slot->unk08 = arg5;
        slot->unk0C = D_80120BE8;
        slot->unk18 = (s32)arg3;
        slot->unk10 = arg1;
        slot->unk14 = arg2;
        slot->unk1C = arg4;
    }
}
