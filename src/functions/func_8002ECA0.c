/* Implements specification specs/func_8002ECA0.md (controller state to flag words). */
#include "podcruise/types.h"

typedef struct {
    s16 unk00;
    s16 unk02;
    u8 unk04;
    u8 unk05;
    u8 unk06;
    u8 unk07;
    u8 unk08;
    u8 unk09;
    u8 unk0A;
    u8 unk0B;
    u8 unk0C;
    u8 unk0D;
    u8 unk0E;
    u8 unk0F;
    u8 unk10;
    u8 unk11;
    u8 unk12;
    u8 unk13;
    u8 unk14[4];
} PadState;

extern PadState D_800D74D8[4];
extern s32 D_800D76F0[4];
extern s32 D_800D7700[4];
extern s32 D_800D7710[4];
extern f32 D_800D7720[4];
extern f32 D_800D7730[4];

extern void func_8002EA28(void);

void func_8002ECA0(void) {
    s32 index;
    s32 flags;
    s32 previous;
    s32 changed;
    f32 axisX;
    f32 axisY;

    func_8002EA28();

    for (index = 0; index < 4; index++) {
        flags = 0;
        if (D_800D74D8[index].unk13) {
            flags |= 0x1;
        }
        if (D_800D74D8[index].unk12) {
            flags |= 0x2;
        }
        if (D_800D74D8[index].unk07) {
            flags |= 0x4;
        }
        if (D_800D74D8[index].unk06) {
            flags |= 0x8;
        }
        if (D_800D74D8[index].unk05) {
            flags |= 0x10;
        }
        if (D_800D74D8[index].unk04) {
            flags |= 0x20;
        }
        if (D_800D74D8[index].unk09) {
            flags |= 0x40;
        }
        if (D_800D74D8[index].unk08) {
            flags |= 0x80;
        }
        if (D_800D74D8[index].unk11) {
            flags |= 0x100;
        }
        if (D_800D74D8[index].unk10) {
            flags |= 0x200;
        }
        if (D_800D74D8[index].unk0F) {
            flags |= 0x400;
        }
        if (D_800D74D8[index].unk0E) {
            flags |= 0x800;
        }
        if (D_800D74D8[index].unk0D) {
            flags |= 0x1000;
        }
        if (D_800D74D8[index].unk0C) {
            flags |= 0x2000;
        }

        axisY = (f32)D_800D74D8[index].unk02 / 100.0f;
        if (0.3 < axisY) {
            flags |= 0x4000;
        }
        if (axisY < -0.3) {
            flags |= 0x8000;
        }

        axisX = (f32)D_800D74D8[index].unk00 / 100.0f;
        if (axisX < -0.3) {
            flags |= 0x10000;
        }
        if (0.3 < axisX) {
            flags |= 0x20000;
        }
        if (-0.2 < axisX && axisX < 0.2) {
            flags |= 0x40000;
        }
        if (-0.2 < axisY && axisY < 0.2) {
            flags |= 0x80000;
        }
        if (axisX <= -0.2 && -0.3 <= axisX) {
            flags |= 0x100000;
        }
        if (0.2 <= axisX && axisX <= 0.3) {
            flags |= 0x200000;
        }
        if (0.2 <= axisY && axisY <= 0.3) {
            flags |= 0x400000;
        }
        if (axisY <= -0.2 && -0.3 <= axisY) {
            flags |= 0x800000;
        }

        previous = D_800D76F0[index];
        changed = previous ^ flags;
        D_800D7700[index] = changed & flags;
        D_800D7710[index] = changed & previous;
        D_800D76F0[index] = flags;
        D_800D7720[index] = axisX;
        D_800D7730[index] = axisY;
    }
}
