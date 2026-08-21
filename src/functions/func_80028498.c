/* Independently written from scratchpad spec specs/func_80028498.md. */

#include "podcruise/types.h"

typedef struct Ctx80028498 {
    /* 0x00 */ u8 pad_00[0x34];
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
} Ctx80028498;

typedef struct Ent80028498 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04[3];
    /* 0x10 */ f32 unk_10[3];
    /* 0x1C */ f32 unk_1C[3];
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ s32 unk_30[2];
} Ent80028498;

typedef struct Blk8011A240 {
    /* 0x00 */ f32 unk_00;
    /* 0x04 */ u8 pad_04[0x28];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
} Blk8011A240;

extern void func_80014CC0(f32 angle, f32 *outB, f32 *outA);
extern f32 func_80014F54(f32 x, f32 y);
extern void func_80015288(f32 *output, f32 *source);
extern void func_800155EC(f32 *output, f32 *base, f32 scale, f32 *offset);
extern void func_80015630(f32 *output, f32 first_scale, f32 *second,
                          f32 second_scale, f32 *first);
extern void func_80028D60(void);

extern s32 D_800A21A0;
extern s32 D_800A21A4;
extern s32 D_800A21A8;
extern f32 D_800A25F8;
extern f32 D_800A4BC8;
extern f32 D_800A4BCC;
extern s32 D_800A4BD0;
extern s32 D_800A4BEC;
extern f32 D_800A4C00[];
extern f32 D_800A5100[];
extern f32 D_800A5148[];
extern f32 D_80118D60[];
extern f32 D_80118D70[];
extern f32 D_80118D80[];
extern f32 D_80118D90[];
extern f32 D_80118E50[];
extern Ent80028498 D_801198A8[];
extern s8 D_8011A204[];
extern Blk8011A240 D_8011A240;
extern f32 D_80120BF8;

void func_80028498(Ctx80028498 *arg0) {
    f32 work[3];
    f32 span;
    f32 outA;
    f32 outB;
    f32 blend;
    s32 i;
    s32 slot;

    span = 0.2f;
    if (D_800A4BCC < 0.0f) {
        D_800A4BCC = D_800A4BCC + D_80120BF8;
        if (D_800A4BCC > 0.0f) {
            D_800A4BCC = 0.0f;
        }
    }
    if (D_800A4BCC > 0.0f) {
        D_800A4BCC = D_800A4BCC - D_80120BF8;
        if (D_800A4BCC < 0.0f) {
            D_800A4BCC = 0.0f;
        }
    }
    if (D_800A4BC8 > 0.0f) {
        D_800A4BC8 = D_800A4BC8 - D_80120BF8;
        if (D_800A4BC8 < 0.0f) {
            D_800A4BC8 = 0.0f;
        }
    }

    for (i = 0; i < D_8011A240.unk_2C; i++) {
        if (arg0->unk_38 == 0) {
            if (i != D_8011A240.unk_30) {
                D_801198A8[i].unk_28 = func_80014F54(D_801198A8[i].unk_04[0] - 12.0f,
                                              -116.0f - D_801198A8[i].unk_04[1]) - 90.0f;
            }
            if (D_801198A8[i].unk_04[2] == 106.0f) {
                func_80014CC0((f32)((1.5 - (f64)D_800A4BC8) * 360.0), &outB,
                              &outA);
                D_801198A8[i].unk_2C = (f32)((f64)D_800A4BCC * 45.0 * (f64)outA);
            }
        }
    }

    if (D_800A21A8 != 0) {
        if (arg0->unk_38 == 0) {
            for (i = 0; i < D_8011A240.unk_2C; i++) {
                func_80014CC0((f32)(0x5A - (i - D_8011A240.unk_30) * 10), &outB,
                              &outA);
                D_801198A8[i].unk_1C[0] = 256.0f * outA + 12.0f;
                D_801198A8[i].unk_1C[2] = 106.0f;
                D_801198A8[i].unk_1C[1] = 256.0f * outB + -116.0f;
                if (i != D_8011A240.unk_30) {
                    D_801198A8[i].unk_28 =
                        func_80014F54(D_801198A8[i].unk_04[0] - 12.0f,
                                      -116.0f - D_801198A8[i].unk_04[1]) - 90.0f;
                }
                func_80014CC0((f32)((1.5 - (f64)D_800A4BC8) * 360.0), &outB,
                              &outA);
                D_801198A8[i].unk_2C = (f32)((f64)D_800A4BCC * 45.0 * (f64)outA);
                if (i == D_8011A240.unk_30) {
                    if (D_800A21A4 != 0) {
                        func_80028D60();
                        func_80015288(work, D_80118D90);
                        func_800155EC(work, work, D_800A5100[21], D_80118D60);
                        func_800155EC(work, work, D_800A5100[22], D_80118D70);
                        func_800155EC(work, work, D_800A5100[23], D_80118D80);
                        func_80015288(D_801198A8[i].unk_1C, work);
                        func_80015630(D_801198A8[i].unk_04, 0.2f, D_801198A8[i].unk_04, 0.8f,
                                      D_80118D90);
                    } else {
                        func_80015288(D_801198A8[i].unk_1C, D_800A5148);
                        D_801198A8[i].unk_2C = 0.0f;
                        D_801198A8[i].unk_28 =
                            func_80014F54(D_800A5100[18] - 12.0f,
                                          -116.0f - D_800A5100[19]) - 90.0f;
                        if (D_800A4BEC != 0) {
                            func_80015630(D_801198A8[i].unk_1C, 0.2f, D_801198A8[i].unk_1C,
                                          0.8f, D_80118D90);
                        }
                    }
                }
                func_80015288(D_801198A8[i].unk_10, D_801198A8[i].unk_04);
            }
        } else if (arg0->unk_38 == 1) {
            slot = D_8011A204[arg0->unk_34 * 3];
            D_8011A240.unk_30 = slot;
            if (slot < 0 || arg0->unk_34 - 4 < 0) {
                D_800A21A8 = 0;
                return;
            }
            if (D_800A21A4 != 0) {
                func_80028D60();
                func_80015288(work, D_80118D90);
                func_800155EC(work, work, D_800A5100[21], D_80118D60);
                func_800155EC(work, work, D_800A5100[22], D_80118D70);
                func_800155EC(work, work, D_800A5100[23], D_80118D80);
                func_80015288(D_801198A8[D_8011A240.unk_30].unk_1C, work);
                func_80015630(D_801198A8[D_8011A240.unk_30].unk_04, 0.2f,
                              D_801198A8[D_8011A240.unk_30].unk_04, 0.8f,
                              D_80118D90);
            } else {
                func_80015288(D_801198A8[slot].unk_1C,
                              &D_800A4C00[arg0->unk_34 * 8 + 3]);
                if (D_800A4BEC != 0) {
                    func_80015630(D_801198A8[D_8011A240.unk_30].unk_1C, 0.2f,
                                  D_801198A8[D_8011A240.unk_30].unk_1C, 0.8f,
                                  D_80118D90);
                }
            }
            func_80015288(D_801198A8[D_8011A240.unk_30].unk_10,
                          D_801198A8[D_8011A240.unk_30].unk_04);
        }
        D_800A21A8 = 0;
        D_800A21A0 = 1;
        D_800A25F8 = 0.0f;
    }

    if (D_800A4BD0 != 0) {
        span = 0.5f;
    }
    if (D_800A21A0 != 0 && D_800A25F8 < span) {
        D_800A25F8 = D_800A25F8 + D_80120BF8;
        if (span <= D_800A25F8) {
            D_800A25F8 = span;
            D_800A21A0 = 0;
        }
        for (i = 0; i < D_8011A240.unk_2C; i++) {
            if (arg0->unk_38 != 1 || i == D_8011A240.unk_30) {
                blend = D_800A25F8 / span;
                D_801198A8[i].unk_04[0] =
                    (D_801198A8[i].unk_1C[0] - D_801198A8[i].unk_10[0]) * blend + D_801198A8[i].unk_10[0];
                D_801198A8[i].unk_04[1] =
                    (D_801198A8[i].unk_1C[1] - D_801198A8[i].unk_10[1]) * blend + D_801198A8[i].unk_10[1];
                D_801198A8[i].unk_04[2] =
                    (D_801198A8[i].unk_1C[2] - D_801198A8[i].unk_10[2]) * blend + D_801198A8[i].unk_10[2];
            }
        }
        if (D_800A21A0 == 0 && D_800A4BEC != 0) {
            D_800A4BEC = 0;
            if (arg0->unk_38 == 0) {
                func_80015288(D_801198A8[D_8011A240.unk_30].unk_04, D_800A5148);
            } else {
                func_80015288(D_801198A8[D_8011A240.unk_30].unk_04, D_80118E50);
            }
            D_801198A8[D_8011A240.unk_30].unk_2C = 0.0f;
        }
    }
}
