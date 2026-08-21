/* Specification: $S/specs/func_80060C6C.md */
#include "podcruise/types.h"

typedef struct {
    u8 pad_00[0x20];
    s16 unk_20;
} ObjectState80060C6C;

extern ObjectState80060C6C D_800D6960;
extern void *D_8011AC80;
extern s32 D_8009B7D0;
extern u32 D_8009B7D8;
extern u32 D_800D76F0;

extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void func_80086CC8(s32 first, s32 second, s32 third);

void func_80060C6C(void *arg0, u32 flags) {
    (void)arg0;
    if (flags & 4) {
        D_800D6960.unk_20 |= 2;
        if (D_8011AC80 != 0) {
            func_800181BC(D_8011AC80, 2, -4, 0x10, 3);
        }
    } else {
        D_800D6960.unk_20 &= ~2;
        if (D_8011AC80 != 0) {
            func_800181BC(D_8011AC80, 2, 3, 0x10, 2);
        }
    }
    if ((D_8009B7D8 & 0x200) && (D_8009B7D0 > 0) && ((D_800D76F0 & 0x1100) == 0x1100)) {
        D_800D6960.unk_20 |= 2;
        func_80086CC8(0, 0, 0);
    }
}
