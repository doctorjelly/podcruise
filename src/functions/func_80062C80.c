/* Independently written from scratchpad spec specs/func_80062C80.md. */

#include "podcruise/types.h"

typedef struct {
    void *unk0;
    void *unk4;
    void *unk8;
    void *unkC;
    void *unk10;
} PcParts;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18[6];
    PcParts *unk30;
    s32 unk34[13];
    f32 unk68;
    f32 unk6C;
    f32 unk70;
    s32 unk74[16];
    s32 unkB4;
} PcObject;

typedef struct {
    f32 unk0;
    s32 unk4;
    s32 unk8;
} PcMode;

extern PcMode D_8011A240;

extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);

void func_80062C80(PcObject *object) {
    void *part;
    void *other;

    if (object->unk8 == 6) {
        return;
    }
    if (D_8011A240.unk8 != 0 && D_8011A240.unk0 == 0.0f && object->unk14 == 0x1B) {
        return;
    }

    part = object->unk30->unk0;
    if (part != 0) {
        if (part != 0) {
            func_800181BC(part, 2, -4, 0x10, 3);
        }
        if (object->unk14 != 0) {
            if (object->unkB4 != 0 && object->unk8 == 1) {
                object->unk68 = object->unk68 + (f32)object->unkB4;
                object->unkB4 = 0;
                object->unk70 = object->unk68;
            }
            if (object->unk8 == 1) {
                other = object->unk30->unkC;
                if (other != 0) {
                    if (other != 0) {
                        func_800181BC(other, 2, -4, 0x10, 3);
                    }
                }
                if (object->unk14 != 7 && object->unk14 != 8 && object->unk14 != 9) {
                    other = object->unk30->unk10;
                    if (other != 0) {
                        if (other != 0) {
                            func_800181BC(other, 2, -4, 0x10, 3);
                        }
                    }
                }
            }
            if (part != 0) {
                func_800181BC(part, 2, 3, 0x10, 2);
            }
        }
    }
}
