/* Recovered from specification specs/func_80077054.md (pod body/engine transform update). */
#include "podcruise/types.h"

typedef f32 Matrix[4][4];

#define AT(p, off) ((void *)((u8 *)(p) + (off)))
#define FF(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define FS(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define FU(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define FP(p, off) (*(void **)((u8 *)(p) + (off)))
#define FM(p, off) ((f32 (*)[4])((u8 *)(p) + (off)))
#define RING(p, i) ((f32 (*)[4])((u8 *)(p) + (i) * 64 + 0x19BC))

extern s32 D_8009B7D0;
extern s32 D_8009B7D8;
extern s32 D_800A5998;
extern u8 D_800A5CA0[];
extern f32 D_800A6654;
extern f32 D_800A6658;
extern f32 D_800A665C;
extern s32 D_800A6950;
extern void *D_800A6954[];
extern void *D_800A695C[];
extern f32 D_800ADA68;
extern f32 D_800ADA6C;
extern s32 D_800D76F0;
extern f64 D_80120BF0;

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_80015328(f32 *, f32 *, f32 *);
extern void func_8001535C(f32 *, f32 *, f32 *);
extern f32 func_800153C0(f32 *);
extern void func_800154D0(f32 *);
extern void func_80015538(f32 *, f32 *, f32 *);
extern void func_800155C0(f32 *, f32, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_800156DC(f32 (*)[4], f32 (*)[4]);
extern void func_80017824(f32 (*)[4], f32, f32, f32, f32, f32 (*)[4]);
extern void func_80017918(void *, f32, f32, f32, f32 (*)[4]);
extern void func_80017D48(void *, s32);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern s32 func_80051FF4(void);
extern s32 func_800520C8(void *);
extern void func_80074CDC(void *);
extern f32 func_80081700(f32, f32);

void func_80077054(void *arg) {
    Matrix work;
    Matrix base;
    Matrix trailB;
    Matrix trailA;
    f32 offset[3];
    s32 isReplay;
    s32 hasWing;
    f32 pivot[3];
    f32 swing[3];
    f32 blend[3];
    s32 index;
    s32 mask;
    s32 step;
    void *entry;
    void *anchor;
    void *link;
    f32 fade;
    f32 lean;
    f32 drop;
    f32 turn;

    isReplay = 0;
    hasWing = 0;
    func_800156DC(base, FM(arg, 0x20));

    if (D_800A5998 != 0) {
        FU(arg, 0x60) = FU(arg, 0x60) | 0x80000;
    }
    mask = FS(arg, 0x60) & 0x84000;
    if (D_8009B7D8 & 0x100) {
        if (D_8009B7D0 != 0) {
            if (D_800D76F0 & 0x1000) {
                mask = 1;
            }
        }
    }

    if (D_800A6950 != 0) {
        if (func_80051FF4() == 0) {
            index = -1;
        } else {
            index = func_800520C8(FP(arg, 0x1E70));
        }
    }

    link = FP(arg, 0x344);
    if (link == 0) {
        func_80017918(AT(arg, 0x15D0), D_800ADA68, D_800ADA68, D_800ADA68, base);
        if ((mask != 0) && (FS(arg, 0x60) & 0x5800)) {
            if (FP(arg, 0x348) != 0) {
                func_800181BC(FP(arg, 0x348), 2, -4, 0x10, 3);
            }
            if (FP(arg, 0x34C) != 0) {
                func_800181BC(FP(arg, 0x34C), 2, -4, 0x10, 3);
            }
        } else {
            if (FP(arg, 0x348) != 0) {
                func_800181BC(FP(arg, 0x348), 2, 3, 0x10, 2);
            }
            if (FP(arg, 0x34C) != 0) {
                func_800181BC(FP(arg, 0x34C), 2, 3, 0x10, 2);
            }
        }
        if (D_800A6950 != 0) {
            if (index >= 0) {
                if ((FS(arg, 0x60) & 0x84000) == 0x80000) {
                    D_800A6954[index] = FP(arg, 0x348);
                    D_800A695C[index] = FP(arg, 0x34C);
                } else {
                    D_800A6954[index] = 0;
                    D_800A695C[index] = 0;
                }
            }
        }
        return;
    }

    if (mask != 0) {
        if (FP(link, 0) != 0) {
            func_800181BC(FP(link, 0), 2, -4, 0x10, 3);
        }
    } else {
        if (FP(link, 0) != 0) {
            func_800181BC(FP(link, 0), 2, 3, 0x10, 2);
        }
    }
    if (D_800A6950 != 0) {
        if ((FS(arg, 0x60) & 0x84000) == 0x80000) {
            D_800A6954[index] = FP(FP(arg, 0x344), 0);
        } else {
            D_800A6954[index] = 0;
        }
    }

    fade = 1.0f - FF(arg, 0x1A0) * D_800ADA6C;
    if (FS(arg, 0x60) & 0x6000000) {
        fade = 0.0f;
    }
    if (fade < 0.0f) {
        fade = 0.0f;
    }
    if (1.0f < fade) {
        fade = 1.0f;
    }
    fade = fade * fade;

    if (FP(FP(arg, 0x344), 0xEC) != 0) {
        func_800181BC(FP(FP(arg, 0x344), 0xEC), 2, 3, 0x10, 2);
    }
    link = FP(arg, 0x344);
    if (FS(FP(FP(arg, 0x1E70), 0x18), 0) == 0xE) {
        isReplay = 1;
    }
    if (FS(link, 0xC) != 0) {
        if (FS(link, 0x10) != 0) {
            hasWing = 1;
        }
    }
    if (FP(link, 0) != 0) {
        func_80017D48(FP(link, 0), 0);
    }

    FU(arg, 0x1E3C) = FU(arg, 0x1E3C) + 1;
    FU(arg, 0x1E3C) = FU(arg, 0x1E3C) % 18;
    FS(arg, 0x1E40) = 0x10;
    FS(arg, 0x1E44) = 0xA;
    func_800156DC(RING(arg, FU(arg, 0x1E3C)), base);

    if ((FS(arg, 0x1998) >= 0x4C) || (FP(arg, 0x344) == 0) || (isReplay != 0)) {
        func_800156DC(trailB, base);
        func_800156DC(trailA, base);
    } else {
        step = FS(arg, 0x1E3C) - FS(arg, 0x1E40);
        while (step < 0) {
            step += 18;
        }
        func_800156DC(trailB, RING(arg, step));
        step = FS(arg, 0x1E3C) - FS(arg, 0x1E44);
        while (step < 0) {
            step += 18;
        }
        func_800156DC(trailA, RING(arg, step));

        FU(arg, 0x1E3C) = FU(arg, 0x1E3C) + 1;
        FU(arg, 0x1E3C) = FU(arg, 0x1E3C) % 18;
        func_800156DC(RING(arg, FU(arg, 0x1E3C)), base);

        step = FS(arg, 0x1E3C) - FS(arg, 0x1E40);
        while (step < 0) {
            step += 18;
        }
        func_800156DC(trailB, RING(arg, step));
        step = FS(arg, 0x1E3C) - FS(arg, 0x1E44);
        while (step < 0) {
            step += 18;
        }
        func_800156DC(trailA, RING(arg, step));

        func_800155EC(trailB[0], trailB[0], 0.1f, base[0]);
        func_800155EC(trailB[1], trailB[1], 0.1f, base[1]);
        func_800155EC(trailB[2], trailB[2], 0.1f, base[2]);
        func_80015538(trailB[0], trailB[1], trailB[2]);
        func_80015538(trailB[2], trailB[0], trailB[1]);
        func_800154D0(trailB[0]);
        func_800154D0(trailB[1]);
        func_800154D0(trailB[2]);
        func_800155EC(trailA[0], trailA[0], 0.2f, base[0]);
        func_800155EC(trailA[1], trailA[1], 0.2f, base[1]);
        func_800155EC(trailA[2], trailA[2], 0.2f, base[2]);
        func_80015538(trailA[0], trailA[1], trailA[2]);
        func_80015538(trailA[2], trailA[0], trailA[1]);
        func_800154D0(trailA[0]);
        func_800154D0(trailA[1]);
        func_800154D0(trailA[2]);
    }

    step = FS(FP(FP(arg, 0x1E70), 0x18), 0);
    if (isReplay != 0) {
        func_800156DC(FM(arg, 0x490), base);
        func_80074CDC(arg);
        return;
    }

    entry = &D_800A5CA0[step * 108];
    func_80015288(offset, entry);
    func_80015328(offset, offset, AT(arg, 0x164C));
    func_800156DC(work, trailA);
    func_80015288(work[3], base[3]);
    func_800155EC(work[3], work[3], offset[0], base[0]);
    func_800155EC(work[3], work[3], offset[1], base[1]);
    func_800155EC(work[3], work[3], offset[2], base[2]);

    lean = base[1][0] * FF(arg, 0x194) + base[1][1] * FF(arg, 0x198);
    lean = FF(arg, 0x19C) * base[1][2] + lean;
    func_800155EC(work[3], work[3], (lean - FF(arg, 0x1E60)) * 50.0f, base[2]);
    FF(arg, 0x1E60) = lean;

    func_8001535C(pivot, work[3], base[3]);
    anchor = AT(arg, 0x1E48);
    func_8001535C(swing, pivot, anchor);
    drop = func_800153C0(swing);
    func_800154D0(swing);
    func_800155EC(AT(arg, 0x1E54), AT(arg, 0x1E54), drop * 20.0f * (f32)D_80120BF0,
                  swing);
    func_800155C0(AT(arg, 0x1E54), func_80081700(10.0f, (f32)D_80120BF0),
                  AT(arg, 0x1E54));
    func_800155EC(blend, anchor, (f32)D_80120BF0, AT(arg, 0x1E54));
    if ((FS(arg, 0x60) & 2) == 0) {
        func_80015288(blend, pivot);
        func_80015268(AT(arg, 0x1E54), 0.0f, 0.0f, 0.0f);
    }
    func_8001535C(work[3], work[3], pivot);
    func_80015328(work[3], work[3], blend);
    func_80015288(AT(arg, 0x1E48), blend);

    turn = FF(arg, 0x1E54) * FF(arg, 0x194) + FF(arg, 0x1E58) * FF(arg, 0x198);
    turn = (FF(arg, 0x19C) * FF(arg, 0x1E5C) + turn) * -2.0f;
    if (3.140625 < (f64)turn) {
        turn = 50.0f;
    }
    if ((f64)turn < -3.140625) {
        turn = -50.0f;
    }
    func_80017824(work, turn, 1.0f, 0.0f, 0.0f, work);

    if (isReplay != 0) {
        FF(arg, 0x19B4) = 0.0f;
    } else {
        drop = (FF(arg, 0x12C8) - work[3][2]) * fade;
        if (12.0f < drop) {
            drop = 12.0f;
        }
        if (drop < -12.0f) {
            drop = -12.0f;
        }
        drop = (f32)((f64)drop * 0.5);
        work[3][2] = work[3][2] + drop;
        FF(arg, 0x19B4) = drop;
    }

    func_800156DC(FM(arg, 0x490), work);

    anchor = (void *)((u8 *)entry + 0xC);
    func_80015288(offset, anchor);
    func_80015328(offset, offset, AT(arg, 0x161C));
    turn = -FF(arg, 0x204) / (f32)2.0;
    func_800156DC(work, base);
    func_80017824(work, turn, 0.0f, 1.0f, 0.0f, work);
    func_800155EC(work[3], work[3], offset[0], base[0]);
    func_800155EC(work[3], work[3], offset[1], base[1]);
    func_800155EC(work[3], work[3], offset[2], base[2]);
    func_800156DC(FM(arg, 0x390), work);
    if (hasWing != 0) {
        func_800155EC(work[3], work[3], D_800A6654, base[0]);
        func_800155EC(work[3], work[3], D_800A6658, base[1]);
        func_800155EC(work[3], work[3], D_800A665C, base[2]);
        func_800156DC(FM(arg, 0x410), work);
    }

    func_80015288(offset, anchor);
    offset[0] = -offset[0];
    func_80015328(offset, offset, AT(arg, 0x1628));
    turn = -FF(arg, 0x204) / (f32)2.0;
    func_800156DC(work, base);
    func_80017824(work, turn, 0.0f, 1.0f, 0.0f, work);
    func_800155EC(work[3], work[3], offset[0], base[0]);
    func_800155EC(work[3], work[3], offset[1], base[1]);
    func_800155EC(work[3], work[3], offset[2], base[2]);
    func_800156DC(FM(arg, 0x3D0), work);
    if (hasWing != 0) {
        func_800155EC(work[3], work[3], -D_800A6654, base[0]);
        func_800155EC(work[3], work[3], D_800A6658, base[1]);
        func_800155EC(work[3], work[3], D_800A665C, base[2]);
        func_800156DC(FM(arg, 0x450), work);
    }

    func_80074CDC(arg);
}
