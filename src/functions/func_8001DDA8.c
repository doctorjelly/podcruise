/* Specification: scratchpad specs/func_8001DDA8.md (pause-menu entry build and input handling). */
#include "podcruise/vector_math.h"

typedef struct {
    /* 0x00 */ s32 unk00[3];
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14[9];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C[8];
    /* 0x5C */ s8 unk5C;
    /* 0x5D */ s8 unk5D;
    /* 0x5E */ s8 unk5E;
    /* 0x5F */ s8 unk5F;
    /* 0x60 */ s32 unk60[3];
    /* 0x6C */ s8 unk6C;
    /* 0x6D */ s8 unk6D;
    /* 0x6E */ s8 unk6E;
    /* 0x6F */ s8 unk6F;
    /* 0x70 */ s8 unk70;
} Menu;

extern s32 D_800A4BBC;
extern u8 D_800A251C;
extern u8 D_800D70B8[];
extern s16 D_800A4BC0;
extern s32 D_800A4BDC;
extern s32 D_800A2198;
extern u32 D_800A4BA4[];
extern u32 D_800A4B94[];
extern u32 D_800D76F0;
extern u8 D_80113E7C;
extern s8 D_80113E67;
extern s8 D_800A21C2[];
extern f32 D_800D70C4;
extern f32 D_800D70C8;
extern f32 D_800D70CC;
extern f32 D_800D7720[];
extern f32 D_800D7730[];
extern f32 D_80120BF8;
extern PcVec3fSlot D_80118D60;
extern PcVec3f D_80118D90;
extern PcVec3fSlot D_80118DA0;
extern PcVec3f D_80118E50;
extern u8 D_80113E60[];
extern u8 D_800A8C9C[];
extern u8 D_800A8CAC[];
extern u8 D_800A8CBC[];
extern u8 D_800A8CD4[];
extern u8 D_800A8CEC[];
extern u8 D_800A8CFC[];
extern u8 D_800A8D0C[];
extern u8 D_800A8D20[];
extern u8 D_800A8D34[];
extern u8 D_800A8D44[];

extern f32 func_80014F54(f32, f32);
extern f32 func_80014D4C(f32);
extern void func_8003ECB0(s32, s32, u8 *);
extern s32 func_8008A6B4(char *, const char *, ...);
extern void func_8002BBA4(Menu *, s32, s32, s32, s32, s32, char *);
extern void func_8002D4C4(s32);
extern void func_8001745C(f32 *, f32, f32, f32);
extern f32 func_80015470(const PcVec3f *, const PcVec3f *);
extern s32 func_8002D968(u8 *, u8 *);
extern void func_8004DFEC(void);
extern void func_800469B4(Menu *, s32);
extern void func_8002DD7C(Menu *);

void func_8001DDA8(Menu *menu) {
    char label[48];
    f32 matrix[12];
    f32 orientation[4];
    PcVec3f vector;
    f32 previousRoll;
    s32 selection;
    s32 index;
    s32 wrapped;
    s32 moved;
    u32 flags;
    u32 held;

    selection = -1;
    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        if (menu->unk0C == 13) {
            menu->unk5F = 0;
        }
        func_8001535C(&vector, &D_80118D90, &D_80118E50);
        D_800D70C4 = func_800153C0(&vector);
        D_800D70C8 = func_80014F54(-vector.x, vector.y);
        D_800D70CC = func_80014D4C(vector.z);
        if (D_800D70C8 < 0.0f) {
            D_800D70C8 = D_800D70C8 + 360.0f;
        }
        if (360.0f < D_800D70C8) {
            D_800D70C8 = D_800D70C8 - 360.0f;
        }
        if (D_800D70CC < -90.0f) {
            D_800D70CC = D_800D70CC + 90.0f;
        }
        if (90.0f < D_800D70CC) {
            D_800D70CC = D_800D70CC - 180.0f;
        }

        D_800A251C = 0;
        do {
            D_800D70B8[D_800A251C] = 255;
            D_800A251C++;
        } while (D_800A251C < 12);

        D_800D70B8[0] = 0;
        D_800A251C = 1;
        if (menu->unk70 == 1) {
            D_800D70B8[1] = 1;
            D_800A251C = 2;
        }
        if (menu->unk6C != 0) {
            D_800D70B8[D_800A251C] = 2;
            D_800A251C++;
            D_800D70B8[D_800A251C] = 3;
            D_800A251C++;
            D_800D70B8[D_800A251C] = 4;
            D_800A251C++;
            if (D_80113E7C < 4) {
                D_800D70B8[D_800A251C] = 5;
                D_800A251C++;
            }
        }
        D_800D70B8[D_800A251C] = 6;
        D_800A251C++;
        D_800D70B8[D_800A251C] = 7;
        D_800A251C++;
    }

    func_8003ECB0(0xA0, 0x19, D_800A8C9C);

    index = 0;
    wrapped = 0;
    if ((s32)D_800A251C > 0) {
        do {
            switch (D_800D70B8[index]) {
                case 0:
                    func_8008A6B4(label, (const char *)D_800A8CAC);
                    break;
                case 1:
                    func_8008A6B4(label, (const char *)D_800A8CBC);
                    break;
                case 2:
                    func_8008A6B4(label, (const char *)D_800A8CD4);
                    break;
                case 3:
                    func_8008A6B4(label, (const char *)D_800A8CEC);
                    break;
                case 4:
                    func_8008A6B4(label, (const char *)D_800A8CFC);
                    break;
                case 5:
                    func_8008A6B4(label, (const char *)D_800A8D0C);
                    break;
                case 6:
                    func_8008A6B4(label, (const char *)D_800A8D20);
                    break;
                case 7:
                    func_8008A6B4(label, (const char *)D_800A8D34);
                    break;
            }
            func_8002BBA4(menu, 0x3C, 0x50, 0xA, menu->unk5F, wrapped, label);
            index++;
            wrapped = index & 0xFF;
            index = wrapped;
        } while (wrapped < (s32)D_800A251C);
        index = 0;
    }

    if (menu->unk70 > 0) {
        do {
            flags = D_800A4BA4[index];
            if ((flags & 0x8000) && !(D_800A4B94[index] & 0x100)) {
                menu->unk5F = menu->unk5F + 1;
                if (D_800A251C - 1 < menu->unk5F) {
                    menu->unk5F = 0;
                }
                func_8002D4C4(0x57);
                flags = D_800A4BA4[index];
            }
            held = D_800A4B94[index] & 0x100;
            if ((flags & 0x4000) && !held) {
                menu->unk5F = menu->unk5F - 1;
                if (menu->unk5F < 0) {
                    menu->unk5F = D_800A251C - 1;
                }
                func_8002D4C4(0x57);
                held = D_800A4B94[index] & 0x100;
            }
            if (held) {
                D_800A4BC0 = 0;
                previousRoll = D_800D70C4;
                moved = 0;
                if (0.1f < D_800D7720[index] || D_800D7720[index] < -0.1f) {
                    moved = 1;
                    D_800D70C8 = D_800D70C8 + 70.0f * D_80120BF8 * D_800D7720[index] * -1.5f;
                }
                if (0.1f < D_800D7730[index] || D_800D7730[index] < -0.1f) {
                    moved = 1;
                    D_800D70CC = D_800D70CC + 45.0f * D_80120BF8 * D_800D7730[index] * 1.5f;
                    if (45.0f < D_800D70CC) {
                        D_800D70CC = 45.0f;
                    }
                    if (D_800D70CC < -45.0f) {
                        D_800D70CC = -45.0f;
                    }
                }
                if (moved != 0) {
                    func_8001745C(orientation, D_800D70C8, D_800D70CC, 0.0f);
                    func_800155EC(&D_80118E50, &D_80118D90, -D_800D70C4, (PcVec3f *)matrix);
                    if (D_800D70C4 != previousRoll) {
                        D_800D70C4 = func_80015470(&D_80118D90, &D_80118E50);
                    }
                    func_800156DC(&D_80118DA0, &D_80118D60);
                }
            }
            flags = D_800A4BA4[index];
            if (flags & 2) {
                func_8002D4C4(0x4D);
                selection = 3;
                D_800A2198 = 13;
                flags = D_800A4BA4[index];
            }
            if ((flags & 1) && !(flags & 2)) {
                func_8002D4C4(0x55);
                if (menu->unk5F == 0) {
                    if (menu->unk6C != 0) {
                        if (D_80113E67 != D_800A21C2[menu->unk5D * 12]) {
                            if (D_800D76F0 & 0x100) {
                                D_800A2198 = 15;
                            }
                        }
                    }
                    D_800A4BDC = -1;
                    if (func_8002D968(D_80113E60, D_800A8D44)) {
                        if (D_800A4B94[0] & 4) {
                            func_8002DD7C(menu);
                        }
                    }
                    return;
                }
                switch (D_800D70B8[menu->unk5F]) {
                    case 1:
                        D_800A2198 = 8;
                        selection = 2;
                        menu->unk10 = 0;
                        func_8004DFEC();
                        break;
                    case 2:
                        D_800A2198 = 8;
                        selection = 2;
                        menu->unk10 = 1;
                        func_8004DFEC();
                        break;
                    case 3:
                        D_800A2198 = 7;
                        selection = 0;
                        menu->unk10 = 0;
                        break;
                    case 4:
                        D_800A2198 = 4;
                        selection = 1;
                        break;
                    case 5:
                        D_800A2198 = 7;
                        selection = 0;
                        menu->unk10 = 1;
                        break;
                    case 6:
                        D_800A2198 = 9;
                        selection = 3;
                        menu->unk6F = index;
                        break;
                    case 7:
                        menu->unk10 = 1;
                        return;
                }
            }
            index++;
            index = index & 0xFF;
        } while (index < menu->unk70);
    }

    if (selection != -1) {
        if (selection == menu->unk38) {
            func_800469B4(menu, D_800A2198);
        } else {
            D_800A4BDC = -1;
        }
    }
}
