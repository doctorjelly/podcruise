/* Independently written from the specification for func_8008ADB0. */

#include "podcruise/types.h"

typedef struct Task8008ADB0 {
    /* 0x00 */ u8 unk00[4];
    /* 0x04 */ s32 unk04;
} Task8008ADB0;

extern u32 func_800938F0(void);

s32 func_8008ADB0(Task8008ADB0 *arg0) {
    u32 status;
    s32 result;

    status = func_800938F0();
    if ((status & 0x100) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    if ((status & 0x80) != 0) {
        arg0->unk04 |= result;
        arg0->unk04 &= ~2;
    }
    return result;
}
