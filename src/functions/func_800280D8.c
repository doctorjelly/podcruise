/* Independently written from scratchpad spec specs/func_800280D8.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 name[3];
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05[2];
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ u8 unk_08[3];
    /* 0x0B */ u8 unk_0B;
    /* 0x0C */ s16 unk_0C[4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ u8 unk_1C[0x10];
} Slot800280D8;

typedef struct {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ u8 unk_04;
    /* 0x005 */ u8 unk_05[3];
    /* 0x008 */ s32 unk_08;
    /* 0x00C */ u8 unk_0C[3];
    /* 0x00F */ u8 unk_0F;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ Slot800280D8 unk_14[4];
    /* 0x0C4 */ u8 unk_C4[0x32C];
} Block800280D8;

extern u8 D_800A969C[];
extern s32 D_800A25F4;
extern Block800280D8 D_80113680;
extern Slot800280D8 D_80113E60;

extern void func_8003E1EC(u8 *text, f32 duration);
extern void func_800399F0(void);

void func_800280D8(s32 arg0) {
    s32 index;

    (void)arg0;
    func_8003E1EC(D_800A969C, 3.0f);
    if (D_800A25F4 == 0) {
        D_800A25F4 = 1;
        D_80113680.unk_08 |= 0x20;
        D_80113680.unk_0C[0] = 0xFF;
        D_80113680.unk_0C[1] = 0xFF;
        D_80113680.unk_0C[2] = 0xFF;
        D_80113680.unk_10 = 0x0FFFFFFF;
        D_80113680.unk_0F = 0xF;
        D_80113E60.unk_08[0] = 0xFF;
        D_80113E60.unk_08[1] = 0xFF;
        D_80113E60.unk_08[2] = 0xFF;
        D_80113E60.unk_14 = 0x0FFFFFFF;
        D_80113E60.unk_0B = 0xF;
        for (index = 3; index >= 0; index--) {
            if (D_80113680.unk_14[index].unk_07 == -1) {
                D_80113680.unk_14[index].unk_08[0] = 0x7F;
                D_80113680.unk_14[index].unk_08[1] = 0x7F;
                D_80113680.unk_14[index].unk_08[2] = 0x7F;
                D_80113680.unk_14[index].unk_0B = 0xF;
                D_80113680.unk_14[index].unk_14 = 0x0FFFFFFF;
                D_80113680.unk_14[index].unk_04 = 1;
                D_80113680.unk_14[index].unk_07 = 0;
                D_80113680.unk_14[index].unk_18 = 40000;
                D_80113680.unk_14[index].name[0] = 0x44;
                D_80113680.unk_14[index].name[1] = 0x42;
                D_80113680.unk_14[index].name[2] = 0x47;
                break;
            }
        }
        func_800399F0();
    }
}
