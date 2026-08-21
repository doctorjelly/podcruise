/* Specification: specs/func_80067718.md (func_80067718) */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x40];
} Elem80067718;

typedef struct {
    u8 pad0[0x30];
    u8 unk30[0x30];
    u32 unk60;
    u8 pad64[0x2EC];
    Elem80067718 unk350[1];
} Obj80067718;

extern f64 D_800AD4D0;
extern f32 D_800AD4D8;

extern s32 func_80082BE0(void);
extern void func_80082440(void *, s32, s32, void *, f32);
extern void func_80017918(void *, f32, f32, f32, void *);

void func_80067718(Obj80067718 *obj, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    f32 y;
    f32 z;
    f32 scale;
    s32 idx;
    u32 flags;

    if (arg5 == 1) {
        idx = 0x41;
        flags = 0x10000000;
    } else {
        idx = 0x42;
        flags = 0x20000000;
    }
    z = arg1;
    y = arg1;
    if (D_800AD4D0 < arg1) {
        y = D_800AD4D8;
    }
    if ((f32)func_80082BE0() / (f32)2147483648.0 < 0.5) {
        scale = (f32)func_80082BE0() / (f32)2147483648.0 * 0.5f + 0.25f;
        y = y * scale;
        z = arg1 * scale;
    }
    func_80082440(&obj->unk350[idx], arg3, arg4, &obj->unk30, arg2);
    func_80017918(&obj->unk350[idx], z, y, y, &obj->unk350[idx]);
    obj->unk60 |= flags;
}
