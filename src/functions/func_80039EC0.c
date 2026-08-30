/* Independently written from specs/functions/recovered/func_80039EC0.md. */
#include "podcruise/types.h"

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s16 unk14;
    s16 unk16;
} DisplayMode;

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u32 unk38;
    u32 unk3C;
    u32 unk40;
    u32 unk44;
    u32 unk48;
    u32 unk4C;
} DisplayRegs;

typedef struct {
    s16 unk00;
    s16 unk02;
    s16 unk04;
    s16 unk06;
    s16 unk08;
    s16 unk0A;
    s16 unk0C;
    s16 unk0E;
} ScreenBox;

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
} RenderQueue;

extern void *func_8008C2F0(void *destination, const void *source, u32 count);
extern void *func_8003F800(u32 tag, s32 index);
extern void func_8008C090(void *queue, s32 mode, s32 flag);
extern void func_80087E80(void *queue, void *arg1, s32 flag);
extern void func_8008A2F0(void *regs);
extern void func_80039CD8(s32 arg0);
extern void func_8008C390(s32 mask);
extern void func_80039B70(void);
extern void func_80007A44(void);

extern s32 D_80000300;
extern u32 D_80000318;
extern s32 D_800A40F0;
extern s32 D_800A40F4;
extern DisplayMode D_800A4128[];
extern DisplayMode D_800A4140[];
extern DisplayMode D_800A42C0[];
extern DisplayMode D_800A4440[];
extern DisplayMode D_800A45C0[];
extern ScreenBox D_800A68B8;
extern DisplayRegs D_800A69C0[];
extern RenderQueue D_800D9C10;
extern s32 D_80113688;
extern DisplayMode D_80114470;
extern s32 D_80114478;
extern DisplayRegs D_80114488;
extern DisplayRegs D_801144D8;

void func_80039EC0(s32 arg0) {
    DisplayMode *table;
    DisplayMode *primary;
    DisplayMode *alternate;
    s32 width;
    s32 height;
    s32 field;
    s32 doubleWidth;
    s32 doubleHeight;

    if (arg0 >= 0x10) {
        while (1) {
        }
    }

    if (arg0 == D_800A40F4) {
        D_800A40F0 = 1;
        return;
    }

    if (arg0 >= 0) {
        D_800A40F4 = arg0;
    }

    if (D_80000300 == 2) {
        primary = D_800A4440;
        alternate = D_800A45C0;
    } else {
        primary = D_800A4140;
        alternate = D_800A42C0;
    }

    if (D_80000318 < 0x800000) {
        table = primary;
    } else if (D_80113688 & 0x10) {
        table = alternate;
    } else {
        table = primary;
    }

    if (D_80000318 >= 0x800000) {
        if (arg0 >= 0) {
            if (D_800A40F4 < 8) {
                table = alternate;
            }
        }
    }

    if (D_80000300 == 0) {
        table = D_800A4128;
        D_800A40F4 = 0;
        arg0 = 0;
    }

    if (arg0 >= 0) {
        func_8008C2F0(&D_80114470, &table[D_800A40F4], 0x18);
    }

    if (D_800A40F4 >= 8) {
        func_8003F800(0x48616E67, 0);
    }

    width = D_80114470.unk00;
    height = D_80114470.unk02;

    if (D_80114470.unk10 != 0) {
        D_801144D8 = D_800A69C0[D_80114470.unk14];
    } else {
        D_801144D8 = D_800A69C0[D_80114470.unk16];
    }

    D_801144D8.unk20 = (width << 10) / 640;

    if (D_80000300 != 0) {
        if (height == 0x1E0) {
            D_801144D8.unk2C &= 0xFFFF0000;
            D_801144D8.unk40 &= 0xFFFF0000;
            D_801144D8.unk08 = width << 1;
            D_801144D8.unk28 = width << 1;
            D_801144D8.unk3C = width << 2;
            field = (height << 9) / 240;
            D_801144D8.unk2C |= field;
            D_801144D8.unk40 |= field;
        } else {
            if (D_80114470.unk04 == 0x20) {
                D_80114470.unk10 = 0;
            }
            D_801144D8.unk08 = width;
            if (width == 640) {
                D_801144D8.unk28 <<= 1;
                D_801144D8.unk3C <<= 1;
                D_801144D8.unk2C &= 0xFFFF0000;
                D_801144D8.unk40 &= 0xFFFF0000;
                D_801144D8.unk2C |= 0x800;
                D_801144D8.unk40 |= 0x800;
            }
        }
    }

    doubleWidth = width << 1;
    func_8008C090(&D_800D9C10, 0, 1);
    if (D_800D9C10.unk08 >= D_800D9C10.unk10) {
        func_80087E80(&D_800D9C10, 0, 1);
    }
    func_80087E80(&D_800D9C10, 0, 1);

    D_80114488 = D_801144D8;
    D_800A40F0 = 0;
    func_8008A2F0(&D_80114488);
    func_80039CD8(1);

    doubleHeight = height << 1;
    D_800A68B8.unk0C = 0x1FF;
    D_800A68B8.unk0E = 0;
    D_800A68B8.unk0A = doubleHeight;
    D_800A68B8.unk02 = doubleHeight;
    D_800A68B8.unk08 = doubleWidth;
    D_800A68B8.unk00 = doubleWidth;
    D_800A68B8.unk04 = D_800A68B8.unk0C;
    D_800A68B8.unk06 = D_800A68B8.unk0E;

    if (D_80114478 & 0x80) {
        func_8008C390(0x80);
    }
    if (D_80114478 & 0x20) {
        func_8008C390(0x20);
    }
    if (D_80114478 & 0x02) {
        func_8008C390(0x02);
    }
    if (D_80114478 & 0x08) {
        func_8008C390(0x08);
    }
    if (D_80114478 & 0x40) {
        func_8008C390(0x40);
    }
    if (D_80114478 & 0x10) {
        func_8008C390(0x10);
    }
    if (D_80114478 & 0x01) {
        func_8008C390(0x01);
    }
    if (D_80114478 & 0x04) {
        func_8008C390(0x04);
    }

    if (D_800D9C10.unk08 >= D_800D9C10.unk10) {
        func_80087E80(&D_800D9C10, 0, 1);
    }
    func_80087E80(&D_800D9C10, 0, 1);
    func_8008C090(&D_800D9C10, 3, 1);
    func_80039B70();
    func_80007A44();
    D_800A40F0 = 1;
}
