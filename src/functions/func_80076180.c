/* Specification: scratchpad specs/func_80076180.md (rumble/shake feedback drive for four HUD nodes). */
#include "podcruise/vector_math.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x60];
    /* 0x060 */ u32 unk060;
    /* 0x064 */ u32 unk064;
    /* 0x068 */ u8 pad068[0x2A0 - 0x68];
    /* 0x2A0 */ u32 unk2A0[6];
    /* 0x2B8 */ u8 pad2B8[0x330 - 0x2B8];
    /* 0x330 */ f32 unk330;
    /* 0x334 */ f32 unk334;
    /* 0x338 */ u8 pad338[0x344 - 0x338];
    /* 0x344 */ void *unk344;
    /* 0x348 */ u8 pad348[0xA50 - 0x348];
    /* 0xA50 */ PcVec3fSlot unkA50;
    /* 0xA90 */ u8 padA90[0xA90 - 0xA90];
} Owner;

typedef struct {
    /* 0x00 */ u8 pad00[0x70];
    /* 0x70 */ void *unk70;
    /* 0x74 */ void *unk74;
    /* 0x78 */ u8 pad78[0xA8 - 0x78];
    /* 0xA8 */ void *unkA8;
    /* 0xAC */ void *unkAC;
    /* 0xB0 */ u8 padB0[0xF0 - 0xB0];
    /* 0xF0 */ s32 unkF0;
} Panel;

extern u32 D_8009B7D0;
extern u32 D_8009B7D8;
extern u32 D_800D76F4;
extern f64 D_80120C00;

extern s32 func_80082BE0(void);
extern void func_8001745C(f32 *, f32, f32, f32);
extern void func_80017BA8(void *, const void *);
extern s32 func_800181BC(void *, s32, u32, s32, s32);
extern void func_8000EA4C(void *, s16, s16, s16, s16, s16, s16);
extern void func_8000E9BC(void *, s16, s16, s16, s16, s16, s16);
extern u32 func_8000E8C4(void *);
extern void func_8003E0A0(void *, f32, f32);

void func_80076180(Owner *owner, Panel *panel, f32 requestX, f32 requestY) {
    f32 matrix[3][4];
    void *node;
    u32 scroll;
    f32 amountX;
    f32 amountY;
    f32 twist;
    f32 brightness;
    f32 scale;
    s32 mode;
    s32 boosted;
    s32 scaleX;
    s32 scaleY;
    s32 offset;
    f32 requested;

    scaleY = 0;
    scaleX = 0;
    boosted = 0;
    if (owner == 0) {
        mode = panel->unkF0;
    } else {
        if (owner->unk344 == 0) {
            return;
        }
        panel = owner->unk344;
        mode = **(s32 **)((u8 *)owner + 0x1E70 + 0x18);
        if (owner->unk060 & 0x800000) {
            boosted = 1;
        } else if (owner->unk064 & 0x2000) {
            boosted = 1;
        }
        offset = 2 * 4;
        if (owner->unk2A0[0] & 4) {
            scaleX = 1;
        }
        if (owner->unk2A0[1] & 4) {
            scaleX = 1;
        }
        if (owner->unk2A0[2] & 4) {
            if (offset < 12) {
                scaleX = 1;
            } else {
                scaleY = 1;
            }
        }
        if (owner->unk2A0[3] & 4) {
            if (offset < 8) {
                scaleX = 1;
            } else {
                scaleY = 1;
            }
        }
        if (owner->unk2A0[4] & 4) {
            if (offset < 4) {
                scaleX = 1;
            } else {
                scaleY = 1;
            }
        }
        if (owner->unk2A0[5] & 4) {
            if (offset >= 0) {
                scaleY = 1;
            } else {
                scaleX = 1;
            }
        }
    }

    amountX = 0.0f;
    amountY = 0.0f;
    if (0.0f <= requestX) {
        amountX = requestX;
    }
    if (0.0f <= requestY) {
        amountY = requestY;
    }
    if ((D_8009B7D8 & 0x100) && D_8009B7D0 != 0 && (D_800D76F4 & 0x1000)) {
        amountX = 1.0f;
        amountY = 1.0f;
        boosted = 0;
    }

    if (owner != 0) {
        requested = *(f32 *)((u8 *)owner + 0x18C);
        amountX = requested;
        amountY = requested;
        if (owner->unk064 & 8) {
            amountX = requested * 0.5f;
            amountY = requested * 0.5f;
        }
        if (scaleX) {
            amountX = amountX * 0.2f;
        }
        if (scaleY) {
            amountY = amountY * 0.2f;
        }
        amountX = (owner->unk330 + amountX) * 0.5f;
        amountY = (owner->unk334 + amountY) * 0.5f;
        owner->unk330 = amountX;
        owner->unk334 = amountY;
    }

    node = panel->unk70;
    if (node != 0) {
        scale = ((f32)func_80082BE0() / 2147483648.0f) * 0.20000004f + 1.0f;
        brightness = 1.0f;
        if (amountX < 0.25f) {
            scale = scale * amountX;
            if (owner == 0) {
                brightness = 1.0f * amountX;
            }
        }
        twist = 0.0f;
        switch (mode) {
            case 4:
            case 6:
            case 16:
                twist = 0.0f;
                scale = 1.0f;
                brightness = ((f32)func_80082BE0() / 2147483648.0f) * 0.10000002f + 0.9f;
                break;
            case 8:
            case 10:
                twist = 0.0f;
                break;
            default:
                twist = (f32)D_80120C00 * 30.0f;
                break;
        }
        func_8001745C(&matrix[0][0], 0.0f, 0.0f, twist);
        func_800155C0((PcVec3f *)matrix[0], scale, (PcVec3f *)matrix[0]);
        func_800155C0((PcVec3f *)matrix[2], scale, (PcVec3f *)matrix[2]);
        if (owner != 0) {
            func_800156DC(&owner->unkA50, (PcVec3fSlot *)matrix);
        }
        func_80017BA8(node, matrix);
        if (node != 0) {
            func_800181BC(node, 2, 3, 0x10, 2);
        }
        func_8000EA4C(node, 0, 0, 255, 255, 255, (s16)(s32)(255.0f * brightness));
    }

    node = panel->unkA8;
    if (node != 0) {
        scale = ((f32)func_80082BE0() / 2147483648.0f) * 0.20000004f + 1.0f;
        brightness = 1.0f;
        if ((f64)amountY < 0.25) {
            scale = scale * amountY;
            if (owner == 0) {
                brightness = 1.0f * amountY;
            }
        }
        twist = 0.0f;
        switch (mode) {
            case 4:
            case 6:
            case 16:
                twist = 0.0f;
                scale = 1.0f;
                brightness = ((f32)func_80082BE0() / 2147483648.0f) * 0.10000002f + 0.9f;
                break;
            case 8:
            case 10:
                twist = 0.0f;
                break;
            default:
                twist = (f32)D_80120C00 * 30.0f;
                break;
        }
        func_8001745C(&matrix[0][0], 0.0f, 0.0f, twist);
        func_800155C0((PcVec3f *)matrix[0], scale, (PcVec3f *)matrix[0]);
        func_800155C0((PcVec3f *)matrix[2], scale, (PcVec3f *)matrix[2]);
        if (owner != 0) {
            func_800156DC(&owner->unkA50, (PcVec3fSlot *)matrix);
        }
        func_80017BA8(node, matrix);
        if (node != 0) {
            func_800181BC(node, 2, 3, 0x10, 2);
        }
        func_8000EA4C(node, 0, 0, 255, 255, 255, (s16)(s32)(255.0f * brightness));
    }

    node = panel->unk74;
    if (node != 0) {
        scroll = func_8000E8C4(node);
        func_80082BE0();
        scale = ((f32)func_80082BE0() / 2147483648.0f) * 0.25f + 1.0f;
        scale = scale * amountX;
        if (boosted) {
            scale = ((f32)func_80082BE0() / 2147483648.0f) * 0.6999998f + 3.5f;
        }
        func_8001745C(&matrix[0][0], 0.0f, 0.0f, ((f32)func_80082BE0() / 2147483648.0f) * 360.0f * 0.0f);
        func_800155C0((PcVec3f *)matrix[1], scale, (PcVec3f *)matrix[1]);
        if (owner != 0) {
            func_800156DC((PcVec3fSlot *)((u8 *)owner + 0xA90), (PcVec3fSlot *)matrix);
        }
        func_80017BA8(node, matrix);
        if (node != 0) {
            func_800181BC(node, 2, 3, 0x10, 2);
        }
        if (scroll != 0) {
            func_8000E9BC((void *)(unsigned long)scroll, 0, 0, 255, 255, 255, 255);
            func_8003E0A0((void *)(unsigned long)scroll, 0.11f, 0.0f);
        }
    }

    node = panel->unkAC;
    if (node != 0) {
        scroll = func_8000E8C4(node);
        func_80082BE0();
        scale = ((f32)func_80082BE0() / 2147483648.0f) * 0.25f + 1.0f;
        scale = scale * amountY;
        if (boosted) {
            scale = ((f32)func_80082BE0() / 2147483648.0f) * 0.6999998f + 3.5f;
        }
        func_8001745C(&matrix[0][0], 0.0f, 0.0f, ((f32)func_80082BE0() / 2147483648.0f) * 360.0f * 0.0f);
        func_800155C0((PcVec3f *)matrix[1], scale, (PcVec3f *)matrix[1]);
        if (owner != 0) {
            func_800156DC((PcVec3fSlot *)((u8 *)owner + 0xE10), (PcVec3fSlot *)matrix);
        }
        func_80017BA8(node, matrix);
        if (node != 0) {
            func_800181BC(node, 2, 3, 0x10, 2);
        }
        if (scroll != 0) {
            func_8000E9BC((void *)(unsigned long)scroll, 0, 0, 255, 255, 255, 255);
            func_8003E0A0((void *)(unsigned long)scroll, 0.11f, 0.0f);
        }
    }
}
