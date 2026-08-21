/* Recovered per specs/func_8000A984.md (boundary corrected: real entry is func_8000A920). */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[0x14];
    s32 flags;
    u8 unk18[8];
} Slot8000A920;

extern s32 D_8009B778;
extern u8 D_8009B77F;
extern u8 D_8009B783;
extern Slot8000A920 D_800D2190[];

void func_8000A920(id, enable)
s16 id;
s32 enable;
{
    if (id == -0xC9) {
        if (enable) {
            D_8009B778 = 1;
        } else {
            D_8009B778 = 0;
        }
    } else if (id == -0x67) {
        if (enable) {
            D_8009B77F = 0xFF;
        } else {
            D_8009B77F = 0;
        }
    } else if (id == -0x68) {
        if (enable) {
            D_8009B783 = 0xFF;
        } else {
            D_8009B783 = 0;
        }
    } else if (id >= 0) {
        if (enable) {
            D_800D2190[id].flags |= 0x20;
        } else {
            D_800D2190[id].flags &= ~0x20;
        }
    }
}
