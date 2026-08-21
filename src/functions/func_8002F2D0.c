/* Implements the specification in scratchpad specs/func_8002F2D0.md */
#include "podcruise/types.h"

extern s32 D_8009B7D8;
extern s32 D_800A26F4;
extern f32 D_800D7740;
extern f64 D_80120BF0;
extern u8 D_80000510[];
extern u8 D_800A9FB0[];

extern s32 func_8008A6B4(char *buffer, const char *format, ...);
extern void func_8003ECB0(s16 column, s16 row, const char *text);
extern void func_8002F0EC(void);
extern s16 *func_8003F800(s32 tag, s32 index);
extern void func_8005B708(void);
extern void func_8000DA78(void);

void func_8002F2D0(void) {
    char text[256];

    if ((D_8009B7D8 & 1) != 0) {
        func_8008A6B4(text, (const char *)D_800A9FB0, (const char *)D_80000510);
        func_8003ECB0(0x1E, 0xD2, text);
    }
    if (D_800A26F4 == 3) {
        if (D_800D7740 <= 0.0f) {
            func_8002F0EC();
        } else {
            D_800D7740 = (f32)((f64)D_800D7740 - (4.0 * D_80120BF0));
            if (D_800D7740 < 0.0f) {
                D_800D7740 = 0.0f;
            }
        }
    } else if (D_800A26F4 == 2) {
        D_800D7740 = (f32)((f64)D_800D7740 + (4.0 * D_80120BF0));
        if (D_800D7740 > 1.0f) {
            D_800D7740 = 1.0f;
            D_800A26F4 = 1;
        }
    }
    if ((func_8003F800(0x4A646765, 0)[3] & 0x1000) == 0) {
        func_8005B708();
    }
    func_8000DA78();
}
