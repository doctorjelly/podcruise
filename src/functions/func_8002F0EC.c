/* Implements the specification in scratchpad specs/func_8002F0EC.md */
#include "podcruise/types.h"

extern s32 D_800A26F4;
extern s32 D_800A26F8;

extern s32 func_8000DA6C(void);
extern void func_8003FA24(s32, s32 *);

void func_8002F0EC(void) {
    s32 message[4];

    if (D_800A26F8 == 0) {
        D_800A26F4 = 0;
        message[0] = 0x50617773;
        message[1] = -1;
        message[2] = func_8000DA6C();
        func_8003FA24(0x416C6C21, message);
    }
}
