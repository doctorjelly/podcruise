/* Independently written from scratchpad spec specs/func_8007C074.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00[8];
    /* 0x20 */ f32 *unk20;
} Holder8007C074;

typedef struct {
    /* 0x00 */ s32 unk00[4];
    /* 0x10 */ f32 unk10[8];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
} Node8007C074;

typedef struct {
    /* 0x00 */ u8 unk00[0x25];
    /* 0x25 */ u8 unk25;
} Shade8007C074;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ void *unk48;
    /* 0x4C */ Holder8007C074 *unk4C;
    /* 0x50 */ Node8007C074 *unk50;
    /* 0x54 */ Shade8007C074 *unk54;
} Obj8007C074;

extern void func_800155EC(f32 *out, f32 *a, f32 t, f32 *b);
extern void func_80017B7C(void *object, f32 first, f32 second, f32 third);
extern void func_80017BA8(void *destination, const void *source);
extern void func_80017C18(const f32 *source, f32 *destination);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void *D_8011C910[];

void func_8007C074(Obj8007C074 *obj) {
    f32 fade;
    Node8007C074 *node;
    Shade8007C074 *shade;
    s32 slot;
    f32 matrix[16];
    f32 rate;

    if (obj->unk0C & 1) {
        if (obj->unk08 == 0x134) {
            if (obj->unk4C->unk20 == 0) {
                return;
            }
            func_80017C18(obj->unk4C->unk20, matrix);
            if (obj->unk48 == 0) {
                return;
            }
            if (obj->unk48 != 0) {
                func_800181BC(obj->unk48, 2, 3, 0x10, 2);
            }
            func_80017BA8(obj->unk48, matrix);
            return;
        }
        if (obj->unk08 == 0xD0) {
            if (obj->unk4C->unk20 == 0) {
                return;
            }
            func_80017C18(obj->unk4C->unk20, matrix);
            if (obj->unk48 == 0) {
                return;
            }
            if (obj->unk48 != 0) {
                func_800181BC(obj->unk48, 2, 3, 0x10, 2);
            }
            func_80017BA8(obj->unk48, matrix);
            return;
        }
        if (obj->unk08 == 0x64 || obj->unk08 == 0x66 || obj->unk08 == 0xC9 ||
            obj->unk08 == 0xCA || obj->unk08 == 0xD4 || obj->unk08 == 0xD5 ||
            obj->unk08 == 0x132 || obj->unk08 == 0x13A || obj->unk08 == 0x1F5) {
            rate = 20.0f;
            if (obj->unk08 == 0x64) {
                slot = 0;
            } else if (obj->unk08 == 0x66) {
                rate = 0.0f;
                slot = 0;
            } else if (obj->unk08 == 0xC9) {
                slot = 0;
            } else if (obj->unk08 == 0xCA) {
                slot = 1;
            } else if (obj->unk08 == 0xD4) {
                slot = 0;
            } else if (obj->unk08 == 0xD5) {
                slot = 3;
            } else if (obj->unk08 == 0x132) {
                slot = 1;
            } else if (obj->unk08 == 0x13A) {
                slot = 0;
            } else if (obj->unk08 == 0x1F5) {
                slot = 5;
            }
            if (obj->unk54 != 0) {
                shade = obj->unk54;
                if (2.0f < obj->unk10) {
                    fade = 0.0f;
                } else {
                    fade = (2.0f - obj->unk10) * 0.5f;
                }
                shade->unk25 = (u8)(u32)(fade * 255.0f);
            }
            node = obj->unk50;
            if (node == 0) {
                return;
            }
            obj->unk24 = node->unk30;
            obj->unk28 = node->unk34;
            obj->unk2C = node->unk38;
            if (obj->unk08 == 0x66) {
                func_800155EC(&obj->unk24, &obj->unk24, 12.0f, node->unk10);
            }
            func_80017B7C(D_8011C910[slot], obj->unk24, obj->unk28, obj->unk2C + rate);
        }
    }
}
