/* Recovered from specification $S/specs/func_80011BDC.md */
#include "podcruise/types.h"

extern s32 D_800A68A0;

extern void func_80008F28(void);
extern void func_8002E034(void);
extern void func_80087CC0(void *destination, s32 count);
extern s32 func_8008A710(void *source, void *destination);

void func_80011BDC(u8 *source, u8 *destination, s32 count) {
    u32 buffer;
    s32 counter;
    u8 *cursor;
    u8 *out;
    u8 *in;

    counter = 0;
    if (D_800A68A0 == 0) {
        func_8002E034();
        D_800A68A0 = 1;
    }
    func_80087CC0(destination, count);
    cursor = destination;
    while (count >= 4) {
        if (counter++ > 100) {
            func_80008F28();
            counter = 0;
        }
        func_8008A710(source, &buffer);
        *(u32 *)cursor = buffer;
        cursor += 4;
        source += 4;
        count -= 4;
    }
    if (count > 0) {
        func_8008A710(source, &buffer);
        out = cursor;
        in = (u8 *)&buffer;
        while (count > 0) {
            *out++ = *in++;
            count--;
        }
    }
}
