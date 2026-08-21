/* Recovered from specification $S/specs/func_80037E9C.md */
#include "podcruise/types.h"

typedef struct Node80037E9C {
    u8 pad00[0x18];
    struct Node80037E9C **unk18;
    s16 unk1C;
    s16 unk1E;
    f32 unk20;
    f32 unk24;
    f32 unk28;
} Node80037E9C;

typedef struct Env80037E9C {
    u8 pad00[0x90];
    f32 unk90[3];
    u8 pad9C[0x04];
    f32 unkA0;
    f32 unkA4;
    f32 unkA8;
    u8 padAC[0x158 - 0xAC];
    u32 unk158;
    u32 unk15C;
} Env80037E9C;

extern Env80037E9C *D_80112C94;
extern s32 D_800A3FE8;
extern s16 D_800A3FD8;

extern f32 func_800153C0(f32 *);
extern f32 func_800154D0(f32 *);
extern void func_80015538(f32 *, f32 *, f32 *);
extern void func_800155C0(f32 *, f32, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern s32 func_80017DAC(Node80037E9C *);
extern u32 func_800182FC(Node80037E9C *, s32);
extern void func_80033EEC(f32 *);
extern void func_8003423C(f32 *);
extern void func_800344C8(void);
extern void func_80038388(Node80037E9C *);

void func_80037E9C(Node80037E9C *node) {
    s32 pushed;
    s32 count;
    f32 out[4][3];
    f32 mtx[4][3];
    f32 delta[3];
    f32 temp[3];
    f32 scale;
    s32 i;
    Node80037E9C *child;

    if (D_800A3FE8 != 0) {
        if (node->unk1E == 0) {
            func_8003423C(out[0]);
        } else {
            func_8003423C(mtx[0]);
            out[3][0] = mtx[3][0];
            out[3][1] = mtx[3][1];
            out[3][2] = mtx[3][2];
            delta[0] = mtx[3][0] - D_80112C94->unkA0;
            delta[1] = mtx[3][1] - D_80112C94->unkA4;
            delta[2] = mtx[3][2] - D_80112C94->unkA8;
            func_800154D0(delta);
            if (node->unk1E == 1) {
                func_800155C0(temp, node->unk20, mtx[0]);
                func_800155EC(temp, temp, node->unk24, mtx[1]);
                func_800155EC(out[2], temp, node->unk28, mtx[2]);
                scale = func_800154D0(out[2]);
                func_80015538(out[0], delta, out[2]);
                func_800154D0(out[0]);
                func_80015538(out[1], out[2], out[0]);
            } else {
                out[1][0] = delta[0];
                out[1][1] = delta[1];
                out[1][2] = delta[2];
                if (node->unk1E == 2) {
                    scale = func_800153C0(mtx[2]);
                    func_80015538(out[0], out[1], D_80112C94->unk90);
                    func_800154D0(out[0]);
                    func_80015538(out[2], out[0], out[1]);
                } else if (node->unk1E == 3) {
                    func_800155C0(temp, node->unk20, mtx[0]);
                    func_800155EC(temp, temp, node->unk24, mtx[1]);
                    func_800155EC(temp, temp, node->unk28, mtx[2]);
                    scale = func_800154D0(temp);
                    func_80015538(out[0], out[1], temp);
                    func_800154D0(out[0]);
                    func_80015538(out[2], out[0], out[1]);
                }
            }
            out[0][0] = out[0][0] * scale;
            out[0][1] = out[0][1] * scale;
            out[0][2] = out[0][2] * scale;
            out[1][0] = out[1][0] * scale;
            out[1][1] = out[1][1] * scale;
            out[1][2] = out[1][2] * scale;
            out[2][0] = out[2][0] * scale;
            out[2][1] = out[2][1] * scale;
            out[2][2] = out[2][2] * scale;
        }
        if (node->unk1C == 1) {
            out[3][0] = D_80112C94->unkA0;
            out[3][1] = D_80112C94->unkA4;
            out[3][2] = D_80112C94->unkA8;
        }
    } else {
        out[0][0] = 1.0f;
        out[0][1] = 0.0f;
        out[0][2] = 0.0f;
        out[1][0] = 0.0f;
        out[1][1] = 1.0f;
        out[1][2] = 0.0f;
        out[2][0] = 0.0f;
        out[2][1] = 0.0f;
        out[2][2] = 1.0f;
        out[3][0] = 0.0f;
        out[3][1] = 0.0f;
        out[3][2] = 0.0f;
    }

    D_800A3FD8 = D_800A3FD8 + 1;
    if (D_800A3FD8 > 0x20) {
        pushed = 1;
    } else {
        pushed = 0;
        func_80033EEC(out[0]);
    }

    count = func_80017DAC(node);
    for (i = 0; i < count; i++) {
        child = node->unk18[i];
        if (child != 0) {
            if ((func_800182FC(child, 2) & D_80112C94->unk158) == D_80112C94->unk158) {
                if ((func_800182FC(child, 2) & D_80112C94->unk15C) != 0) {
                    func_80038388(child);
                }
            }
        }
    }

    if (pushed == 0) {
        func_800344C8();
    }
    D_800A3FD8 = D_800A3FD8 - 1;
}
