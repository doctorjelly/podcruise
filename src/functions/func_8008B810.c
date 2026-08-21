/* Recovered from specification specs/func_8008B810.md (worker batch_03). */
#include "podcruise/types.h"

typedef struct Object8008B810 {
    /* 0x000 */ s32 unk000;
    /* 0x004 */ s32 unk004;
    /* 0x008 */ s32 unk008;
    /* 0x00C */ struct Object8008B810 *unk00C;
    /* 0x010 */ s16 unk010;
    /* 0x012 */ s16 unk012;
    /* 0x014 */ s32 unk014;
    /* 0x018 */ s32 unk018;
    /* 0x01C */ u8 pad01C[0x38 - 0x1C];
    /* 0x038 */ s64 unk038;
    /* 0x040 */ u8 pad040[0xF0 - 0x40];
    /* 0x0F0 */ s64 unk0F0;
    /* 0x0F8 */ u8 pad0F8[0x100 - 0xF8];
    /* 0x100 */ s64 unk100;
    /* 0x108 */ u8 pad108[0x118 - 0x108];
    /* 0x118 */ s32 unk118;
    /* 0x11C */ s32 unk11C;
    /* 0x120 */ u8 pad120[0x128 - 0x120];
    /* 0x128 */ s32 unk128;
    /* 0x12C */ s32 unk12C;
} Object8008B810;

extern u8 D_8008D400;
extern Object8008B810 *D_800A7BBC;
extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32 handle);

void func_8008B810(Object8008B810 *object, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    register s32 handle;
    u32 packed;

    object->unk014 = arg1;
    object->unk004 = arg5;
    object->unk000 = 0;
    object->unk008 = 0;
    object->unk11C = arg2;
    object->unk038 = arg3;
    object->unk0F0 = (s64)arg4 - 16;
    object->unk100 = (s64)(long)&D_8008D400;
    packed = 0x3FFF01;
    object->unk118 = 0xFF03;
    object->unk128 = (packed & 0x3F0000) >> 16;
    object->unk12C = 0x1000800;
    object->unk018 = 0;
    object->unk010 = 1;
    object->unk012 = 0;
    handle = func_8008CA80();
    object->unk00C = D_800A7BBC;
    D_800A7BBC = object;
    func_8008CAA0(handle);
}
