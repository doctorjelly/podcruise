/* Recovered from specification $S/specs/func_800870D0.md */
#include "podcruise/types.h"

extern f32 D_80120DF0[];
extern char D_800ADD40[];
extern char D_800ADD54[];

extern void func_8008A6B4(char *, char *, ...);
extern void func_8003ED74(s32, s32, s32, char *);
extern f32 func_80052060(void);

void func_800870D0(s32 arg0, s32 arg1) {
    char text[64];
    char text2[56];
    f32 value;

    (void)arg1;
    (void)text2;
    if (arg0 >= 2) {
        func_8008A6B4(text, D_800ADD40, (s32)D_80120DF0[132], (s32)D_80120DF0[133], (s32)D_80120DF0[134]);
        func_8003ED74(4, 0x11D, 0xD6, text);
        value = func_80052060();
        if (0.0f < value) {
            func_8008A6B4(text, D_800ADD54, value);
            func_8003ED74(4, 0x12C, 0xC2, text);
        }
    }
}
