/* Implements specification specs/func_80030328.md (two-part staged copy). */
#include "podcruise/types.h"

typedef struct Region {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Region;

extern s32 D_800A2864;
extern u8 D_102ABB0[];

extern s32 func_8002FC58(void);
extern s32 func_8002FAFC(void);
extern void func_8002FAC4(s32);
extern void func_80011CDC(void *, s32, s32);

void func_80030328(Region *region, s32 *firstOut, s32 *secondOut, s32 arg3) {
    register s32 length;
    s32 needed;
    s32 destination;
    u8 *base[1];
    s32 total;
    s32 start;
    s32 free;

    (void)arg3;
    free = func_8002FC58();
    start = region->unk0;
    total = region->unk8 - start;
    needed = total + 0x80;
    if (free < needed) {
        *secondOut = 0;
        *firstOut = 0;
        D_800A2864 = 1;
    } else {
        if (region->unk4 == 0) {
            length = total;
        } else {
            length = region->unk4 - start;
        }
        destination = (func_8002FAFC() + 0x3F) & -0x40;
        start = region->unk0;
        base[0] = D_102ABB0;
        func_80011CDC(base[0] + start, destination, length);
        *firstOut = destination;
        if (region->unk4 != 0) {
            destination = (destination + length + 0x3F) & -0x40;
            length = region->unk8 - region->unk4;
            func_80011CDC(base[0] + region->unk4, destination, length);
            *secondOut = destination;
        }
        func_8002FAC4(destination + length);
    }
}
