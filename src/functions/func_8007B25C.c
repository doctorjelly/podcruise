/* Independently written from scratchpad spec specs/func_8007B25C.md. */

#include "podcruise/types.h"

extern void **D_8011C8E0;

extern void func_8003FD7C(void *object);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);

s32 func_8007B25C(void *object, u32 *message, void *arg2) {
    void *pad[21];

    (void)arg2;
    (void)pad;

    switch (message[0]) {
    case 0x4C6F6164:
        func_8003FD7C(object);
        break;
    case 0x52536574:
        func_8003FD7C(object);
        break;
    case 0x416C6F63:
        *(s32 *)((u8 *)object + 0x60) = 0;
        *(s32 *)((u8 *)object + 0x64) = 0;
        *(f32 *)((u8 *)object + 0x68) = 0.0f;
        *(void **)((u8 *)object + 0x78) =
            D_8011C8E0[*(s16 *)((u8 *)object + 0x4)];
        if (*(void **)((u8 *)object + 0x78) != 0) {
            if (*(void **)((u8 *)object + 0x78) != 0) {
                func_800181BC(*(void **)((u8 *)object + 0x78), 2, -4, 0x10, 3);
            }
        }
        break;
    case 0x46726565:
        *(void **)((u8 *)object + 0x78) = 0;
        break;
    default:
        return 0;
    }
    return 1;
}
