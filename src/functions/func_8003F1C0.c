/* Specification: specs/func_8003F1C0.md */
#include "podcruise/types.h"

extern f32 D_800AAB9C;
extern char D_800AAB6C[];
extern char D_800AAB7C[];
extern s32 func_8008A6B4();
extern s32 func_8003EC40();

void func_8003F1C0(s32 x, s32 y, f32 seconds, s32 c1, s32 c2, s32 c3, s32 c4, char *label) {
    char buffer[256];
    s32 secondsPart;
    s32 fraction;
    s32 minutes;
    f32 minutesValue;
    f32 secondsValue;

    minutesValue = seconds / 60.0f;
    minutes = (s32)minutesValue;
    secondsValue = (minutesValue - (f32)minutes) * (f32)60.0;
    secondsPart = (s32)secondsValue;
    fraction = (s32)((secondsValue - (f32)secondsPart + D_800AAB9C) * 1000.0f);
    if (fraction == 1000) {
        secondsPart = secondsPart + 1;
        fraction = 0;
        if (secondsPart == 60) {
            minutes = minutes + 1;
        }
    }
    if (minutes != 0) {
        func_8008A6B4(buffer, D_800AAB6C, label, minutes, secondsPart, fraction);
    } else {
        func_8008A6B4(buffer, D_800AAB7C, label, secondsPart, fraction);
    }
    func_8003EC40((s16)x, (s16)y, (u8)c1, (u8)c2, (u8)c3, (u8)c4, buffer);
}
