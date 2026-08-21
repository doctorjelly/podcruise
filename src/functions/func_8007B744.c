/* Implements the specification in specs/func_8007B744.md */
#include "podcruise/types.h"

extern s32 *D_8011C8F0[];
extern void func_80006E60(s32, s32);
extern void func_80006E74(s32, f32);

void func_8007B744(s32 arg0) {
    s32 *list;

    list = D_8011C8F0[arg0];
    while (list[0] != 0) {
        func_80006E60(list[0], 0x10000000);
        func_80006E74(list[0], 0.0f);
        list++;
    }
}
