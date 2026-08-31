/* Independently written from specs/functions/recovered/func_80080498.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x50];
    /* 0x050 */ f32 unk50;
    /* 0x054 */ f32 unk54;
    /* 0x058 */ f32 unk58;
    /* 0x05C */ u8 pad05C[0xAC - 0x5C];
    /* 0x0AC */ u8 unkAC[8];
    /* 0x0B4 */ f32 unkB4;
    /* 0x0B8 */ u8 pad0B8[4];
    /* 0x0BC */ s32 unkBC;
    /* 0x0C0 */ u8 pad0C0[0xCC - 0xC0];
    /* 0x0CC */ s32 unkCC;
    /* 0x0D0 */ s32 unkD0;
    /* 0x0D4 */ u8 pad0D4[0x16C - 0xD4];
    /* 0x16C */ f32 unk16C;
    /* 0x170 */ f32 unk170;
    /* 0x174 */ f32 unk174;
} Obj;

extern f32 D_800ADC64;
extern f32 D_800ADC68;
extern f64 D_80120BF0;

extern void func_8003B02C(void *source, f32 *out);
extern f32 func_800153C0(f32 *vector);

void func_80080498(Obj *obj, f32 *arg1, s32 *arg2, s32 *arg3) {
    f32 step;
    f32 vector[3];
    s32 saved;
    f32 frame[16];
    f32 here;
    f32 there;
    f32 edge;
    s32 finished;

    *arg2 = 0;
    *arg3 = 0;
    saved = obj->unkBC;
    func_8003B02C(obj->unkAC, frame);
    /* Redundant after the dereference above; preserves IDO register allocation. */
    if (obj && obj) {
    }
    vector[0] = obj->unk50 - obj->unk16C;
    vector[1] = obj->unk54 - obj->unk170;
    vector[2] = obj->unk58 - obj->unk174;
    func_800153C0(vector);
    *arg1 = 0.0f;
    step = D_800ADC64;

    do {
        finished = 1;
        here = obj->unk50 * frame[4] + obj->unk54 * frame[5] + frame[6] * obj->unk58;
        there = obj->unk16C * frame[4] + obj->unk170 * frame[5] + frame[6] * obj->unk174;
        edge = frame[12] * frame[4] + frame[13] * frame[5] + frame[14] * frame[6];
        if (edge < here) {
            if (obj->unkCC != 0) {
                if (here - there < step) {
                    *arg1 = 0.0f;
                } else {
                    *arg1 = (f32)D_80120BF0 * (edge - there) / (here - there);
                }
            } else {
                obj->unkB4 = obj->unkB4 + step;
                func_8003B02C(obj->unkAC, frame);
                finished = 0;
                if (saved != obj->unkBC) {
                    if (obj->unkBC == 0) {
                        if (here - there < step) {
                            *arg1 = 0.0f;
                        } else {
                            *arg1 = (f32)D_80120BF0 * (edge - there) / (here - there);
                        }
                    }
                    saved = obj->unkBC;
                }
            }
            *arg2 = 1;
        }
    } while (finished == 0);

    step = D_800ADC68;
    if (*arg2 != 0) {
        return;
    }
    if (obj->unkD0 != 0) {
        return;
    }
    obj->unkB4 = obj->unkB4 - step;
    func_8003B02C(obj->unkAC, frame);

    do {
        finished = 1;
        here = obj->unk50 * frame[4] + obj->unk54 * frame[5] + frame[6] * obj->unk58;
        edge = frame[12] * frame[4] + frame[13] * frame[5] + frame[14] * frame[6];
        if (here < edge) {
            if (obj->unkD0 != 0) {
            } else {
                obj->unkB4 = obj->unkB4 - step;
                func_8003B02C(obj->unkAC, frame);
                finished = 0;
            }
            *arg3 = 1;
        }
    } while (finished == 0);

    if (obj->unkD0 != 0) {
        return;
    }
    obj->unkB4 = obj->unkB4 + step;
    func_8003B02C(obj->unkAC, frame);
}
