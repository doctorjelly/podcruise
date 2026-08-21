/* Recovered from specification: specs/func_80076B34.md (worker batch 05) */
#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ f32 x;
    /* 0x4 */ f32 y;
    /* 0x8 */ f32 z;
} Vec3;

typedef struct {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ s32 *unk18;
} Ctx;

typedef struct Obj {
    /* 0x0000 */ u8 pad0[0x20];
    /* 0x0020 */ Vec3 unk20;
    /* 0x002C */ u8 pad2C[0x4];
    /* 0x0030 */ Vec3 unk30;
    /* 0x003C */ u8 pad3C[0x14];
    /* 0x0050 */ Vec3 unk50;
    /* 0x005C */ u8 pad5C[0x4];
    /* 0x0060 */ u32 unk60;
    /* 0x0064 */ u32 unk64;
    /* 0x0068 */ f32 unk68;
    /* 0x006C */ u8 pad6C[0x234];
    /* 0x02A0 */ u32 unk2A0[0x1D];
    /* 0x0314 */ struct Obj *unk314[0xC];
    /* 0x0344 */ s32 unk344;
    /* 0x0348 */ u8 pad348[0x8];
    /* 0x0350 */ Vec3 unk350;
    /* 0x035C */ u8 pad35C[0x4];
    /* 0x0360 */ Vec3 unk360;
    /* 0x036C */ u8 pad36C[0x14];
    /* 0x0380 */ f32 unk380;
    /* 0x0384 */ f32 unk384;
    /* 0x0388 */ f32 unk388;
    /* 0x038C */ u8 pad38C[0x44];
    /* 0x03D0 */ Vec3 unk3D0;
    /* 0x03DC */ u8 pad3DC[0x4];
    /* 0x03E0 */ Vec3 unk3E0;
    /* 0x03EC */ u8 pad3EC[0x14];
    /* 0x0400 */ f32 unk400;
    /* 0x0404 */ f32 unk404;
    /* 0x0408 */ f32 unk408;
    /* 0x040C */ u8 pad40C[0x1A64];
    /* 0x1E70 */ Ctx *unk1E70;
} Obj;

typedef struct {
    /* 0x00 */ u8 pad0[0x40];
} Blk;

extern void func_800155C0(Vec3 *, f32, Vec3 *);
extern void func_800155EC(Vec3 *, Vec3 *, f32, Vec3 *);
extern s32 func_8003FDCC(u32, Vec3 *, f32, s32, s32, void *, void *, Obj **);
extern Obj *func_80065810(s32, s32, f32, Vec3 *, f32);
extern void func_80065C50(Obj *, Vec3 *);
extern void func_80065C74(Obj *, Vec3 *);
extern void func_80065C98(Obj *, f32);
extern void func_80065CB0(Obj *, Obj **);
extern s32 func_80082BE0(void);

void func_80076B34(Obj *arg0) {
    s32 i;
    s32 count;
    Vec3 sp14C;
    Vec3 sp140;
    s32 sp138[2];
    Obj *sp110[10];
    u8 spF0[0x20];
    u8 sp88[0x68];
    Vec3 sp74;
    f32 rad;
    s32 index;
    Obj *target;
    Obj *b;
    Obj *tail;

    sp138[1] = 0;
    sp138[0] = 0;
    if (arg0->unk344 != 0) {
        for (i = 0; i < 6; i++) {
            if (arg0->unk2A0[i] & 8) {
                sp138[i / 3] = 1;
            }
        }
        for (i = 0; i < 2; i++) {
            b = (Obj *)((u8 *)&((Blk *)arg0)[-i] + 0x80);
            if (sp138[i] != 0 || arg0->unk314[i] != 0) {
                sp14C.x = b->unk380;
                sp14C.y = b->unk384;
                sp14C.z = b->unk388;
                func_800155EC(&sp14C, &sp14C, -2.0f, &b->unk360);
                if (arg0->unk1E70->unk18[0] == 14) {
                    func_800155EC(&sp140, &sp14C, (i == 0) ? -2.0f : 2.0f, &b->unk350);
                }
                func_800155C0(&sp140, -20.0f, &b->unk360);
                if (sp138[i] != 0) {
                    if (arg0->unk314[i] == 0) {
                        arg0->unk314[i] = func_80065810(6, 0, 1000.0f, &sp14C, 1.0f);
                        func_80065CB0(arg0->unk314[i], &arg0->unk314[i]);
                    } else if (arg0->unk314[i] != 0) {
                        func_80065C98(arg0->unk314[i], 5.0f);
                    }
                }
                if (arg0->unk314[i] != 0) {
                    func_80065C50(arg0->unk314[i], &sp14C);
                    func_80065C74(arg0->unk314[i], &sp140);
                }
            }
        }
        if ((arg0->unk60 & 0x87800) != 0 || (arg0->unk64 & 0x4000) != 0) {
            for (i = 0; i < 2; i++) {
                if (arg0->unk314[i] != 0) {
                    func_80065C98(arg0->unk314[i], 0.0f);
                }
            }
        }
    }

    tail = (Obj *)((u8 *)arg0 + 8);
    target = tail->unk314[0];
    if (target == 0) {
        return;
    }
    if (target->unk60 != 8) {
        return;
    }
    if (3.0f < target->unk68) {
        if (arg0->unk344 != 0) {
            b = (Obj *)&((Blk *)arg0)[1];
            sp14C.x = b->unk380;
            sp14C.y = b->unk384;
            sp14C.z = b->unk388;
            func_800155EC(&sp14C, &sp14C, 1.0f, &b->unk360);
            func_800155EC(&sp14C, &sp14C, 12.0f, &b->unk350);
            func_800155C0(&sp140, 10.0f, &b->unk350);
        } else {
            sp14C.x = arg0->unk50.x;
            sp14C.y = arg0->unk50.y;
            sp14C.z = arg0->unk50.z;
            func_800155EC(&sp14C, &sp14C, 1.0f, &arg0->unk30);
            func_800155EC(&sp14C, &sp14C, 15.0f, &arg0->unk20);
            func_800155C0(&sp140, 10.0f, &arg0->unk20);
        }
        func_80065C50(target, &sp14C);
        func_80065C74(target, &sp140);
        func_800155EC(&sp74, &sp14C, 0.5f, &sp140);
        rad = 8.0f;
        count = func_8003FDCC(0x54657374, &sp74, rad * rad, 0, 2, spF0, sp88, sp110);
        if (count > 0) {
            i = 0;
            do {
                if (arg0 != sp110[i] && !(sp110[i]->unk60 & 0x7800) && !(sp110[i]->unk64 & 0x2000000)) {
                    index = (s32)((f32)func_80082BE0() / 2147483648.0f * 3.0f);
                    if (sp110[i]->unk30.z * arg0->unk30.z + (arg0->unk30.y * sp110[i]->unk30.y + arg0->unk30.x * sp110[i]->unk30.x) < 0.0f) {
                        index = index + 3;
                    }
                    sp110[i]->unk2A0[index] |= 8;
                }
                i++;
            } while (i < count);
        }
        if ((arg0->unk60 & 0x87800) != 0 || (arg0->unk64 & 0x4000) != 0) {
            if (tail->unk314[0] != 0) {
                func_80065C98(tail->unk314[0], 0.0f);
            }
        }
    }
}
