/* Independently written from the specification in specs/func_8004E0A0.md
   (per-slot control request refresh). */

#include "podcruise/types.h"

extern u32 D_800A4B94[4];
extern u32 D_800A4BA4[4];
extern s32 D_800A5208[4];
extern s32 D_800A5218[4];
extern u32 D_800A4BD8;
extern u32 D_800D76F0[4];

extern void func_8004E488(s32 index, s32 enable, u32 mask);

void func_8004E0A0(s32 index) {

    D_800A4BA4[index] = 0;
    if (D_800A4BD8 != 0) {
        func_8004E488(index, D_800D76F0[index] & 0x1, 0x1);
        func_8004E488(index, D_800D76F0[index] & 0x2, 0x2);
        func_8004E488(index, D_800D76F0[index] & 0x4, 0x4);
        func_8004E488(index, D_800D76F0[index] & 0x8, 0x8);
        func_8004E488(index, D_800D76F0[index] & 0x10, 0x10);
        func_8004E488(index, D_800D76F0[index] & 0x20, 0x20);
        func_8004E488(index, D_800D76F0[index] & 0x40, 0x40);
        func_8004E488(index, D_800D76F0[index] & 0x80, 0x80);
        func_8004E488(index, D_800D76F0[index] & 0x100, 0x100);
        func_8004E488(index, D_800D76F0[index] & 0x200, 0x200);
        func_8004E488(index, D_800D76F0[index] & 0x400, 0x400);
        func_8004E488(index, D_800D76F0[index] & 0x800, 0x800);
        func_8004E488(index, D_800D76F0[index] & 0x1000, 0x1000);
        func_8004E488(index, D_800D76F0[index] & 0x2000, 0x2000);
        func_8004E488(index, D_800D76F0[index] & 0x4000, 0x4000);
        func_8004E488(index, D_800D76F0[index] & 0x8000, 0x8000);
        func_8004E488(index, D_800D76F0[index] & 0x10000, 0x10000);
        func_8004E488(index, D_800D76F0[index] & 0x20000, 0x20000);
        func_8004E488(index, D_800D76F0[index] & 0x40000, 0x40000);
        func_8004E488(index, D_800D76F0[index] & 0x80000, 0x80000);
        func_8004E488(index, D_800D76F0[index] & 0x100000, 0x100000);
        func_8004E488(index, D_800D76F0[index] & 0x200000, 0x200000);
        func_8004E488(index, D_800D76F0[index] & 0x400000, 0x400000);
        func_8004E488(index, D_800D76F0[index] & 0x800000, 0x800000);

        if (D_800A4B94[index] & 0x40000) { D_800A5208[index] = 0; } else if (D_800A4B94[index] & 0x10000) { D_800A5208[index] = -1; } else if (D_800A4B94[index] & 0x20000) { D_800A5208[index] = 1; }

        if (D_800A4B94[index] & 0x80000) {
            D_800A5218[index] = 0;
        } else if (D_800A4B94[index] & 0x4000) {
            D_800A5218[index] = -1;
        } else if (D_800A4B94[index] & 0x8000) {
            D_800A5218[index] = 1;
        }

        if ((D_800A4BA4[index] & 0x100000) && (D_800A5208[index] == -1)) {
            D_800A4B94[index] |= 0x10000;
        }
        if ((D_800A4BA4[index] & 0x200000) && (D_800A5208[index] == 1)) {
            D_800A4B94[index] |= 0x20000;
        }
        if ((D_800A4BA4[index] & 0x400000) && (D_800A5218[index] == -1)) {
            D_800A4B94[index] |= 0x4000;
        }
        if ((D_800A4BA4[index] & 0x800000) && (D_800A5218[index] == 1)) {
            D_800A4B94[index] |= 0x8000;
        }
    }
}
