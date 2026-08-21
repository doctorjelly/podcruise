/* Independently written from the specification scratchpad specs/func_80057F48.md. */

#include "podcruise/types.h"

extern s32 func_80051FF4(void);
extern void func_8000A920(s16, s32);
extern void *D_8011B1C0;

void func_80057F48(void *arg0) {
    s32 i;

    if (func_80051FF4() == 2) {
        if (arg0 == D_8011B1C0) {
            for (i = 0; i < 6; i++) {
                func_8000A920(i + 0x1B, 0);
            }
            func_8000A920(0x21, 0);
            func_8000A920(0x22, 0);
        } else {
            for (i = 0; i < 6; i++) {
                func_8000A920(i + 0x23, 0);
            }
            func_8000A920(0x29, 0);
            func_8000A920(0x2A, 0);
        }
    } else {
        for (i = 0; i < 6; i++) {
            func_8000A920(i + 0x1B, 0);
        }
        func_8000A920(0x21, 0);
        func_8000A920(0x22, 0);
    }
}
