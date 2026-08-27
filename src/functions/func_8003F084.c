/* Independently written from specs/functions/func_8003F084.md. */

#include "podcruise/types.h"

extern f32 D_800AAB98;
extern char D_800AAB50[];
extern char D_800AAB60[];

extern s32 func_8008A6B4(char *buffer, const char *format, ...);
extern void func_8003EC40(s16 x, s16 y, u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          u8 *text);

void func_8003F084(s16 x, s16 y, f32 seconds, u8 arg3, u8 arg4, u8 arg5,
                   u8 arg6, void *arg7) {
    char text[256];
    s32 wholeSeconds;
    s32 hundredths;
    s32 minutes;
    f32 minutesValue;
    f32 secondsValue;

    minutesValue = seconds / (f32)60.0;
    minutes = (s32)minutesValue;
    secondsValue = (minutesValue - (f32)minutes) * 60.0f;
    wholeSeconds = (s32)secondsValue;
    hundredths =
        (s32)(((secondsValue - (f32)wholeSeconds) + D_800AAB98) * 100.0f);
    if (hundredths == 100) {
        wholeSeconds = wholeSeconds + 1;
        hundredths = 0;
        if (wholeSeconds == 60) {
            minutes = minutes + 1;
        }
    }
    if (minutes != 0) {
        func_8008A6B4(text, D_800AAB50, arg7, minutes, wholeSeconds,
                      hundredths);
    } else {
        func_8008A6B4(text, D_800AAB60, arg7, wholeSeconds, hundredths);
    }
    func_8003EC40(x, y, arg3, arg4, arg5, arg6, (u8 *)text);
}
