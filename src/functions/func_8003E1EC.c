/* Recovered from the specification in specs/func_8003E1EC.md (worker notes). */
#include "podcruise/types.h"

extern s32 func_8008A6B4(u8 *destination, u8 *format, u8 *text);

extern u8 D_800A498C[];
extern s32 D_800A4A8C;
extern f32 D_800A4A90;
extern f32 D_800A4A94;
extern u8 D_800AAB20[];
extern u8 D_800AAB24[];

void func_8003E1EC(u8 *text, f32 duration) {
    if (text != 0) {
        if (duration > 0.0) {
            if ((text[0] == 0x7E) && (text[1] == 0x5F)) {
                D_800A4A8C = 1;
                func_8008A6B4(D_800A498C, D_800AAB20, text + 2);
            } else {
                D_800A4A8C = 0;
                func_8008A6B4(D_800A498C, D_800AAB24, text);
            }
            D_800A4A90 = duration;
            D_800A4A94 = 1.0f;
        }
    }
}
