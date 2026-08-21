/* Independently written from scratchpad spec specs/func_8003FD7C.md. */

#include "podcruise/types.h"

typedef struct Object8003FD7C {
    u8 unk00[0x6];
    s16 unk06;
} Object8003FD7C;

typedef struct Notice8003FD7C {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
} Notice8003FD7C;

extern void func_8003F99C(Object8003FD7C *object, Notice8003FD7C *notice);

void func_8003FD7C(Object8003FD7C *arg0) {
    Notice8003FD7C notice;

    if (arg0 == 0) {
        return;
    }
    if ((arg0->unk06 & 0x100) != 0) {
        return;
    }

    notice.unk00 = 0x46726565;
    func_8003F99C(arg0, &notice);
    arg0->unk06 |= 0x100;
}
