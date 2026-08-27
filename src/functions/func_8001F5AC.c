/* Implements the specification in $S/specs/func_8001F5AC.md (per-frame race HUD / countdown state machine). */
#include "podcruise/types.h"

typedef struct Actor8001F5AC {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x4];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[0x20];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x4];
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ u8 pad40[0x1F];
    /* 0x5F */ s8 unk5F;
    /* 0x60 */ u8 pad60[0x10];
    /* 0x70 */ s8 unk70;
    /* 0x71 */ u8 pad71[0x1];
    /* 0x72 */ s8 unk72;
} Actor8001F5AC;

typedef struct Entry801198A8 {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 pad02[0x36];
} Entry801198A8;

typedef struct Entry800A2DE0 {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 pad04[0x8];
    /* 0x0C */ s32 unk0C;
} Entry800A2DE0;

typedef struct Counters80113E60 {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 unk1C;
} Counters80113E60;

typedef struct Limits8011A240 {
    /* 0x00 */ u8 pad00[0x2C];
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
} Limits8011A240;

extern s32 D_800A2198;
extern s16 D_800A219C;
extern s32 D_800A21A0;
extern s32 D_800A21A4;
extern s32 D_800A21A8;
extern s32 D_800A21B0;
extern s32 D_800A2528;
extern s32 D_800A252C;
extern Entry800A2DE0 D_800A2DE0[];
extern s32 D_800A4B94[];
extern s32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s16 D_800A4BC0;
extern s32 D_800A4BC4;
extern f32 D_800A4BC8;
extern f32 D_800A4BCC;
extern s32 D_800A4BDC;
extern s32 D_800A4BEC;
extern u8 D_800A4C0C[];
extern char D_800A8DE8[];
extern f32 D_800D6CC0;
extern s16 D_800D6CC4;
extern s32 D_800D7168;
extern Counters80113E60 D_80113E60;
extern s32 D_80113E78;
extern Entry801198A8 D_801198A8[];
extern Limits8011A240 D_8011A240;
extern s32 D_8011A270;
extern void *D_8011A5D4[];
extern f32 D_80120BF8;

extern s32 func_800129B8(void *arg0, s32 arg1);
extern f32 func_80014F54(f32 x, f32 y);
extern void func_80015288(f32 *arg0, void *arg1);
extern s32 func_80028320(void *arg0, s32 arg1, s32 arg2);
extern void func_80028498(void *arg0);
extern void func_80029C24(void);
extern void func_80029D38(void *arg0);
extern void func_8002A7D4(void *arg0);
extern void func_8002CC28(s32 arg0, s32 arg1, s32 arg2);
extern void func_8002D4C4(s32 arg0);
extern void func_8002D6EC(void *arg0);
extern s32 func_8002DBD8(void *arg0);
extern void func_80033590(void *arg0, f32 *arg1);
extern void func_8003EC40(s16 arg0, s16 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, void *arg6);
extern void func_800469B4(void *arg0, s32 arg1);
extern void func_80046DC4(void *arg0, f32 arg1, f32 arg2);
extern void func_8004850C(void *arg0);
extern void func_8004E4F4(void *arg0);
extern void func_800503E8(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_800511B0(void *arg0, s32 arg1);
extern void func_800519C0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80063084(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 arg5);
extern void func_80063AA0(s32 arg0, s32 arg1);
extern void func_80064B44(s32 arg0, f32 arg1, s32 arg2);
extern s32 func_8008A6B4(char *buffer, const char *format, ...);
extern void func_8001F48C(void *arg0);

void func_8001F5AC(Actor8001F5AC *arg0) {
    char text[0x104];
    f32 screen[4];
    f32 world[3];
    Entry801198A8 *entry;
    Entry800A2DE0 *player;
    s32 timer;
    s32 count;
    register s32 lines;
    f32 fade;
    f32 scale;

    fade = 20.0f;
    func_80028320(arg0, D_800A4BBC, fade);
    if (D_800A4BBC != 0) {
        D_800A4BBC = 0;
        D_800D6CC0 = -300.0f;
        D_800A219C = 0;
        if (arg0->unk3C != 0) {
            func_8004E4F4(arg0);
        }
        D_800A21A0 = 0;
        D_800D7168 = 4 - D_80113E60.unk1C;
        D_800A2528 = 0;
        if (arg0->unk10 == 0) {
            func_800503E8(arg0, 1, -1, 0);
            D_800A4BC4 = 0;
            func_800511B0(arg0, 1);
            D_800A21A8 = 1;
            entry = &D_801198A8[D_8011A270];
            player = &D_800A2DE0[entry->unk00];
            func_800519C0(arg0->unk72, player->unk03, player->unk01, entry->unk01);
            D_800A252C = D_8011A270;
        } else {
            D_800D6CC4 = 0;
            if (D_80113E60.unk18 < 1000) {
                D_800D6CC4 = 1;
            }
            if (D_800D7168 != 0) {
                D_800A2528 = 1;
            }
            if (func_8002DBD8(arg0) != 0) {
                func_800503E8(arg0, 2, -1, 0);
            }
        }
    }

    func_8001F48C(arg0);
    if (arg0->unk10 == 0) {
        if (D_800A252C != D_8011A270) {
            D_800A252C = D_8011A270;
            D_800A21A8 = 1;
            entry = &D_801198A8[D_8011A270];
            player = &D_800A2DE0[entry->unk00];
            func_800519C0(arg0->unk72, player->unk03, player->unk01, entry->unk01);
            func_80029C24();
        }
    } else {
        timer = D_800D7168;
        if (timer > 0) {
            if (D_800A4BC0 != 1) {
                D_800D7168 = timer;
                if (D_800D6CC0 == -300.0f) {
                    D_800A219C = 1;
                    D_800A4BC0 = 5;
                    D_800D7168 = timer;
                    func_80063AA0(timer + 0x33, 3);
                }
            } else {
                D_800D7168 = timer;
            }
        }
    }

    if (arg0->unk34 == 1) {
        func_80029D38(arg0);
        func_80046DC4(arg0, fade, 135.0f);
    } else {
        func_8002A7D4(arg0);
    }

    if (D_800A21A4 == 0 && D_800A219C == 0 && arg0->unk34 == 1 &&
        (D_800A4BC0 == 0 || D_800A4BC0 == 5)) {
        entry = &D_801198A8[D_8011A270];
        player = &D_800A2DE0[entry->unk00];
        func_8008A6B4(text, D_800A8DE8, player->unk0C);
        func_8003EC40(0xA0, 0x19, 0x32, 0xFF, 0xFF, 0xFF, text);
        lines = func_800129B8(text, 0);
        func_8002CC28((s32)(100.0 - (f64)lines * 0.5), 0x1A, func_800129B8(text, 0));
    }

    func_80028498(arg0);
    func_8004850C(arg0);
    D_800A21A8 = 0;
    if (arg0->unk08 == 3) {
        return;
    }

    for (count = 0; count < arg0->unk70; count++) {
        if (D_800A219C != 0) {
            continue;
        }
        if (D_800A4BA4[count] & 1) {
            func_8002D4C4(0x55);
            if (arg0->unk10 == 0) {
                if (-1 != D_8011A270) {
                    if (D_800A21A4 == 0) {
                        if (D_800A4BC0 == 0 || D_800A4BC0 == 5) {
                            D_800A21A8 = 1;
                            D_800A21A4 = 1;
                            D_800D6CC4 = 0;
                            D_800A219C = 1;
                            func_80029C24();
                        }
                    } else {
                        if (D_800D6CC4 == 0) {
                            func_80063AA0(0x1C, 0x19);
                            func_8002D6EC(arg0);
                        } else {
                            func_80063AA0(0x1C, 0x1A);
                        }
                        D_800A21A8 = 1;
                        D_800D6CC4 = 0;
                        D_800A21A4 = 0;
                        D_800A4BEC = 1;
                        D_800A219C = -1;
                    }
                }
            } else if (arg0->unk10 == 1) {
                if (D_800A2528 == 0) {
                    if (D_800D7168 > 0) {
                        D_800A2528 = 1;
                        D_800A219C = 1;
                        D_800D6CC4 = 0;
                        func_80063AA0(D_800D7168 + 0x33, 3);
                    }
                } else if (D_800D6CC4 == 1) {
                    D_800D6CC4 = 0;
                    D_800A2528 = 0;
                    D_800A219C = -1;
                    func_80063AA0(D_800D7168 + 0x33, 4);
                    if (D_800A21B0 == 2) {
                        D_800A21B0 = 0;
                        D_800A2198 = 8;
                        D_800A4BDC = -1;
                    } else {
                        D_800A2528 = 0;
                        func_800469B4(arg0, 3);
                        return;
                    }
                } else if (D_80113E78 >= 1000) {
                    func_80033590(D_8011A5D4[D_800D7168], screen);
                    func_80015288(world, D_800A4C0C);
                    world[2] = -60.0f;
                    scale = func_80014F54(screen[0] - 12.0f, -116.0f - screen[1]);
                    func_80063084(D_800D7168 + 0x33, 0xA, screen, world, scale, scale);
                    D_80113E60.unk18 -= 1000;
                    D_80113E60.unk1C += 1;
                    timer = D_800D7168 - 1;
                    if (timer <= 0) {
                        D_800D7168 = timer;
                        D_800A2528 = 0;
                        D_800A219C = -1;
                        if (D_800A21B0 == 2) {
                            D_800A21B0 = 0;
                            D_800A2198 = 8;
                            D_800A4BDC = -1;
                            break;
                        }
                        arg0->unk5F = 1;
                        func_800469B4(arg0, 3);
                        return;
                    } else {
                        D_800D7168 = timer;
                        func_80063AA0(timer + 0x33, 3);
                    }
                }
            }
        }
        if (D_800A4BA4[count] & 2) {
            func_8002D4C4(0x4D);
            if (D_800A2528 != 0) {
                D_800D6CC4 = 0;
                D_800A219C = -1;
                func_80063AA0(D_800D7168 + 0x33, 4);
                if (D_800A21B0 == 2) {
                    D_800A21B0 = 0;
                    D_800A2198 = 8;
                    D_800A4BDC = -1;
                } else {
                    D_800A2528 = 0;
                    func_800469B4(arg0, 3);
                    return;
                }
            } else if (D_800A21A4 != 0) {
                func_80063AA0(0x1C, 0x1A);
                D_800A21A8 = 1;
                D_800A21A4 = 0;
                D_800A4BEC = 1;
                D_800D6CC4 = 0;
                D_800A219C = -1;
            } else {
                D_800A21A8 = 1;
                if (D_800A21B0 == 1) {
                    D_800A2198 = 8;
                    D_800A4BDC = -1;
                    break;
                }
                func_800469B4(arg0, 3);
            }
        }
        if (arg0->unk10 == 0) {
            func_80064B44(0, 1.0f, 0);
            if (D_800A21A4 == 0) {
                if (D_800A4B94[count] & 0x20000) {
                    if (D_8011A240.unk30 < D_8011A240.unk2C - 1) {
                        D_800A4BC8 = D_800A4BC8 + 50.0 * D_80120BF8;
                        if (D_800A4BC8 > 1.5) {
                            D_800A4BC8 = 1.5f;
                        }
                        D_800A4BCC = D_800A4BCC - 5.5 * D_80120BF8;
                        if (D_800A4BCC < -1.0) {
                            D_800A4BCC = -1.0f;
                        }
                    }
                }
                if (D_800A4B94[count] & 0x10000) {
                    if (D_8011A270 > 0) {
                        D_800A4BC8 = D_800A4BC8 + 50.0 * D_80120BF8;
                        D_800A4BCC = D_800A4BCC + 5.5 * D_80120BF8;
                        if (D_800A4BC8 > 1.5) {
                            D_800A4BC8 = 1.5f;
                        }
                        if (D_800A4BCC > 1.0) {
                            D_800A4BCC = 1.0f;
                        }
                    }
                }
            }
        }
    }
}
