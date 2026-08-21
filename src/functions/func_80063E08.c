/* Independently written from the specification notes for func_80063E08. */

#include "podcruise/vector_math.h"

extern PcVec3f D_800A5100[];

void func_80063E08(u8 *record, s32 index) {
    func_80015288((PcVec3f *)(record + 0x50), &D_800A5100[index]);
    *(s32 *)(record + 0xA0) = 0;
}
