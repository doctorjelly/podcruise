/* Independently written from specs/functions/recovered/func_8007ACEC.md. */
#include "podcruise/vector_math.h"

typedef struct {
    u8 unk00[0x18];
    s32 *unk18;
} KindACEC;

typedef struct {
    void *entries[65];
} TableACEC;

typedef struct {
    u8 unk00[0x60];
    s32 unk60;
    u8 unk64[0x300 - 0x64];
    s32 unk300;
    u8 unk304[0x30C - 0x304];
    f32 unk30C;
    u8 unk310[0x344 - 0x310];
    TableACEC *unk344;
    void *unk348;
    void *unk34C;
    f32 unk350[65][4][4];
    u8 unk1390[0x15D0 - 0x1390];
    f32 unk15D0[4][4];
    u8 unk1610[0x1998 - 0x1610];
    s32 unk1998;
    u8 unk199C[0x1E70 - 0x199C];
    KindACEC *unk1E70;
} ObjectACEC;

extern s32 func_80073470(void *object);
extern s32 func_80077054(void *object);
extern void func_800784F8(void *object);
extern s32 func_80079824(void *object);
extern s32 func_80076180(void *object, s32 arg1, f32 arg2, f32 arg3);
extern s32 func_80075BA8(void *object);
extern s32 func_80076B34(void *object);
extern s32 func_80073834(void *object);
extern s32 func_80075940(void *object);
extern s32 func_80073714(void *object);
extern s32 func_80074474(void *object);
extern s32 func_80074B08(void *object);
extern s32 func_80017BA8(void *destination, const void *source);
extern s32 func_80017D48(void *object, s32 value);
extern s32 func_80086A20(s32 slot, PcVec3f *ambient, PcVec3f *diffuse, PcVec3f *direction);

extern f32 D_800ADB54;

void func_8007ACEC(ObjectACEC *object) {
    s32 i;
    f32 direction[3];
    f32 diffuse[3];
    f32 ambient[3];
    f32 value;
    s32 whole;


    func_80073470(object);

    whole = object->unk60;
    if (!(whole & 0x800)) {
        func_80077054(object);
        if (*object->unk1E70->unk18 == 14) {
            func_800156DC((PcVec3fSlot *)object->unk350[1], (PcVec3fSlot *)object->unk350[5]);
            func_800156DC((PcVec3fSlot *)object->unk350[2], (PcVec3fSlot *)object->unk350[5]);
        }
        if (object->unk344 != 0) {
            func_800784F8(object);
            func_80079824(object);
            func_80076180(object, 0, -1.0f, -1.0f);
            func_80075BA8(object);
        }
        func_80076B34(object);
        if (object->unk344 != 0) {
            func_80073834(object);
            func_80075940(object);
        }
        func_80073714(object);
        func_80074474(object);
        func_80074B08(object);
    }

    if (object->unk344 == 0) {
        if (object->unk348 != 0) {
            func_80017BA8(object->unk348, object->unk15D0);
        }
        if (object->unk34C != 0) {
            if (object->unk1998 >= 101) {
                func_80017D48(object->unk34C, 1);
            } else {
                func_80017D48(object->unk34C, 0);
            }
        }
    } else {
        if (object->unk344->entries[5] != 0) {
            func_80017BA8((void *)(long)((s32 *)object->unk344)[5], object->unk350[5]);
        }
        if (object->unk344->entries[1] != 0) {
            func_80017BA8((void *)(long)((s32 *)object->unk344)[1], object->unk350[1]);
        }
        if (object->unk344->entries[2] != 0) {
            func_80017BA8((void *)(long)((s32 *)object->unk344)[2], object->unk350[2]);
        }
        if (object->unk344->entries[3] != 0) {
            func_80017BA8((void *)(long)((s32 *)object->unk344)[3], object->unk350[3]);
        }
        if (object->unk344->entries[4] != 0) {
            func_80017BA8((void *)(long)((s32 *)object->unk344)[4], object->unk350[4]);
        }
        for (i = 62; i != 65; i++) {
            if (object->unk344->entries[i] != 0) {
                func_80017BA8(object->unk344->entries[i], object->unk350[i]);
            }
        }
    }

    if ((object->unk60 & 0x2000) || (object->unk60 & 0x4000)) {
        if (object->unk300 >= 0) {
            diffuse[0] = 255.0f;
            diffuse[1] = 255.0f;
            diffuse[2] = 255.0f;
            direction[0] = 0.0f;
            direction[1] = 0.0f;
            direction[2] = -1.0f;
            value = object->unk30C * 4.0f;
            if (value < 0) {
                whole = (s32)(value - D_800ADB54);
            } else {
                whole = (s32)value;
            }
            value = value - (f32)whole;
            ambient[2] = 255.0f;
            ambient[0] = value * 255.0f;
            ambient[1] = value * 255.0f;
            diffuse[2] = ambient[2];
            diffuse[1] = ambient[1];
            diffuse[0] = ambient[0];
            func_80086A20(object->unk300, (PcVec3f *)ambient, (PcVec3f *)diffuse, (PcVec3f *)direction);
        }
    }
}
