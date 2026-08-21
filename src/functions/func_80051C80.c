/* Specification: scratchpad specs/func_80051C80.md */
#include "podcruise/types.h"

typedef struct Object80051C80 {
    u8 unk_00[0x8];
    u32 unk_08;
    f32 unk_0C;
    u8 unk_10[0x118];
    s32 unk_128;
} Object80051C80;

extern s32 D_800A5340[];

extern void func_80005B80(void);
extern void func_800315D8(s32 arg0);
extern void func_8003FC94(s32 arg0);

void func_80051C80(Object80051C80 *object, s32 arg1) {
    if (D_800A5340[0] == 0) {
        D_800A5340[0] = 1;
        func_80005B80();
        func_800315D8(-1);
        object->unk_08 = (object->unk_08 & ~0xF) | 6;
        object->unk_0C = 0.5f;
        object->unk_128 = arg1;
        func_8003FC94(0x54657374);
        func_8003FC94(0x546F7373);
        func_8003FC94(0x536D6F6B);
        func_8003FC94(0x54726967);
        func_8003FC94(0x43687372);
    }
}
