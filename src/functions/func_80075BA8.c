/* Recovered from specification specs/functions/func_80075BA8.md (batch_04). */
#include "podcruise/types.h"

extern void func_80008BC4(void *arg0, s16 arg1, f32 arg2, f32 arg3, void *arg4,
                          s32 arg5, s32 arg6, f32 arg7, f32 arg8);
extern void func_80017918(f32 *destination, f32 x, f32 y, f32 z, f32 *source);
extern void func_80017BA8(void *destination, const void *source);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void func_80075A3C(void *object, f32 *point, f32 *output);
extern s32 func_80082BE0(void);

extern f32 D_800A66C8;
extern f32 D_800AD9C4;
extern f32 D_800AD9C8;
extern f32 D_800AD9CC;
extern f32 D_800AD9D0;
extern f64 D_80120C00;

typedef struct {
    u8 unk000[0x4];
    s32 unk004;
    u8 unk008[0x104 - 0x8];
    void *unk104;
    void *unk108;
} Data80075BA8;

typedef struct {
    u8 unk000[0x350];
    f32 matrix[12];
    f32 vector[4];
} Part80075BA8;

typedef struct {
    u8 unk0000[0x50];
    u8 unk0050[0x10];
    s32 unk0060;
    u8 unk0064[0x344 - 0x64];
    Data80075BA8 *unk0344;
    u8 unk0348[0x1040 - 0x348];
    u8 parts[0x400];
} Object80075BA8;

void func_80075BA8(Object80075BA8 *object) {
    Part80075BA8 *part;
    f32 value;
    f32 amount;
    f32 scratch[2];

    (void)scratch;
    if (object->unk0344 != 0) {
        if (object->unk0060 & 0x10000000) {
            part = (Part80075BA8 *)&object->parts[0];
            if (object->unk0344->unk004 != 0) {
                func_80075A3C(object, part->vector, part->vector);
                func_80017918(part->matrix, 3.0f, 3.0f, 3.0f, part->matrix);
                func_80017BA8(object->unk0344->unk104, part->matrix);
            }
            object->unk0060 = object->unk0060 & ~0x10000000;
            if (object->unk0344->unk104 != 0) {
                func_800181BC(object->unk0344->unk104, 2, 3, 0x10, 2);
            }
            if ((D_80120C00 + 0.75) < D_800A66C8) {
                value = (f32)func_80082BE0() / 2147483648.0f;
                D_800A66C8 = (f32)((f64)(value * 0.25f + 0.5f) + D_80120C00);
            }
            if (D_800A66C8 < D_80120C00) {
                amount = (f32)func_80082BE0() / 2147483648.0f;
                func_80008BC4((void *)0x3C, 5, amount * D_800AD9C4 + D_800AD9C8,
                              0.6f, object->unk0050, 0, 0, 10.0f, 500.0f);
                value = (f32)func_80082BE0() / 2147483648.0f;
                D_800A66C8 = (f32)((f64)(value * 0.25f + 0.5f) + D_80120C00);
            }
        } else if (object->unk0344->unk104 != 0) {
            func_800181BC(object->unk0344->unk104, 2, -4, 0x10, 3);
        }
        if (object->unk0060 & 0x20000000) {
            part = (Part80075BA8 *)&object->parts[0x40];
            if (object->unk0344->unk004 != 0) {
                func_80075A3C(object, part->vector, part->vector);
                func_80017918(part->matrix, 2.0f, 2.0f, 2.0f, part->matrix);
                func_80017BA8(object->unk0344->unk108, part->matrix);
            }
            if (object->unk0344->unk108 != 0) {
                func_800181BC(object->unk0344->unk108, 2, 3, 0x10, 2);
            }
            object->unk0060 = object->unk0060 & ~0x20000000;
            if (D_800A66C8 < D_80120C00) {
                amount = (f32)func_80082BE0() / 2147483648.0f;
                func_80008BC4((void *)0x3C, 5, amount * D_800AD9CC + D_800AD9D0,
                              0.6f, object->unk0050, 0, 0, 10.0f, 500.0f);
                value = (f32)func_80082BE0() / 2147483648.0f;
                D_800A66C8 = (f32)((f64)(value * 0.25f + 0.5f) + D_80120C00);
            }
        } else if (object->unk0344->unk108 != 0) {
            func_800181BC(object->unk0344->unk108, 2, -4, 0x10, 3);
        }
    }
}
