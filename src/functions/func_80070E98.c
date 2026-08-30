/* Independently written from specs/functions/recovered/func_80070E98.md. */
#include "podcruise/types.h"

typedef struct {
    u8 pad00[0x50];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    u8 pad5C[4];
    u32 unk60;
    u32 unk64;
    u8 pad68[0x44];
    u8 unkAC[0x1DC];
    f32 unk288[6];
    u32 unk2A0[6];
    u8 pad2B8[0x54];
    f32 unk30C;
    u8 pad310[0x34];
    s32 unk344;
    u8 pad348[0x78];
    f32 unk3C0[16];
    f32 unk400[16];
} Obj80070E98;

extern f32 D_800AD850;
extern f32 D_800AD854;
extern f64 D_800AD858;
extern f64 D_800AD860;
extern f32 D_800AD868;
extern f32 D_800AD86C;
extern f64 D_800AD870;
extern f64 D_800AD878;
extern f32 D_800AD880;

extern void func_80008BC4(s32, s32, f32, f32, void *, s32, s32, f32, f32);
extern void func_8003B184(void *, void *, f32);
extern void *func_80065810(s32, s32, f32, f32 *, f32);
extern void func_800704A8(void *, f32);
extern void func_80070BBC(void *, void *, s32);
extern void func_80075648(void *, s32, f32 *, f32);
extern s32 func_80082BE0(void);

void func_80070E98(Obj80070E98 *obj, s32 arg1) {
    f32 spare0[17];
    f32 position[3];
    f32 matrixA[16];
    f32 matrixB[16];
    f32 spare1[16];
    s32 index;
    s32 kind;
    void *source;
    f32 limit;
    f32 value;

    (void)arg1;
    (void)spare0;
    (void)spare1;

    if (obj->unk60 & 0x4000) {
        return;
    }
    obj->unk60 |= 0x4000;
    obj->unk64 &= ~0x8000;
    obj->unk64 &= ~0x10000;

    position[0] = obj->unk50;
    position[1] = obj->unk54;
    position[2] = obj->unk58;

    source = obj->unkAC;
    func_8003B184(source, matrixA, 0.005f);
    func_80070BBC(obj, matrixA, 0);
    func_800704A8(obj, 0.0f);
    func_8003B184(source, matrixB, -0.01f);

    func_80065810(3, 0, 2.0f, position, 1.0f);
    func_80065810(3, 0, 2.2f, position, 3.0f);

    if (obj->unk344 == 0) {
        func_80075648(obj, -1, position, 0.2f);
    } else if (obj->unk64 & 0x10000) {
        func_80075648(obj, -1, obj->unk3C0, 0.2f);
    } else if (obj->unk64 & 0x8000) {
        func_80075648(obj, -1, obj->unk400, 0.2f);
    } else if (((f32)func_80082BE0() / (f32)2147483648.0) < 0.5) {
        func_80075648(obj, -1, obj->unk3C0, 0.2f);
    } else {
        func_80075648(obj, -1, obj->unk400, 0.2f);
    }

    value = (f32)func_80082BE0() / (f32)2147483648.0;
    if (value < D_800AD850) {
        kind = 0x34;
    } else if (value < D_800AD854) {
        kind = 0x35;
    } else {
        kind = 0x36;
    }
    func_80008BC4(kind, 7,
                  (f32)((f64)((f32)func_80082BE0() / (f32)2147483648.0) * D_800AD858 + D_800AD860),
                  1.0f, position, 0, 0, 10.0f, 500.0f);

    value = (f32)func_80082BE0() / (f32)2147483648.0;
    if (value < D_800AD868) {
        kind = 0x34;
    } else if (value < D_800AD86C) {
        kind = 0x35;
    } else {
        kind = 0x36;
    }
    func_80008BC4(kind, 7,
                  (f32)((f64)((f32)func_80082BE0() / (f32)2147483648.0) * D_800AD870 + D_800AD878),
                  1.0f, position, 0, 0, 10.0f, 500.0f);

    limit = D_800AD880;
    for (index = 0; index < 6; index++) {
        obj->unk2A0[index] &= ~8;
        if (limit < obj->unk288[index]) {
            obj->unk288[index] = limit;
        }
    }

    if (obj->unk60 & 0x100) {
        obj->unk30C = 1.0f;
    } else {
        obj->unk30C = 5.0f;
    }
}
