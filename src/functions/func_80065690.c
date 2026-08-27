/* Independently written from scratchpad specs/func_80065690.md. */
#include "podcruise/types.h"

typedef struct Object {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ u8 pad08[0x60 - 0x08];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ u8 pad6C[0xDC - 0x6C];
    /* 0xDC */ f32 unkDC[5];
    /* 0xF0 */ s32 unkF0;
    /* 0xF4 */ s32 unkF4[5];
} Object;

extern s32 *D_8011C840;
extern void func_800181BC(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_8003FD7C(Object *object);

s32 func_80065690(Object *object, s32 *message, s32 arg2) {
    s32 i;

    (void)arg2;
    switch (message[0]) {
    case 0x4C6F6164:
        func_8003FD7C(object);
        object->unkF0 = 0;
        break;
    case 0x52536574:
        func_8003FD7C(object);
        object->unkF0 = 0;
        break;
    case 0x416C6F63:
        object->unk60 = 0;
        object->unk64 = 0;
        object->unkF0 = 0;
        object->unk68 = 0.0f;
        for (i = 0; i < 5; i++) {
            object->unkF4[i] = D_8011C840[object->unk04 * 5 + i];
            if (object->unkF4[i] != 0) {
                if (object->unkF4[i] != 0) {
                    func_800181BC(object->unkF4[i], 2, -4, 0x10, 3);
                }
            }
            object->unkDC[i] = 0.0f;
        }
        return 1;
    case 0x46726565:
        for (i = 0; i < 5; i++) {
            object->unkF4[i] = 0;
        }
        break;
    default:
        return 0;
    }
    return 1;
}
