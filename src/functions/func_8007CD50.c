/* Specification: specs/func_8007CD50.md */
#include "podcruise/types.h"

typedef struct Node8007CD50 {
    u8 pad00[0x100];
    s32 unk100;
    u8 pad104[0x110 - 0x104];
    f32 unk110;
} Node8007CD50;

typedef struct Sub8007CD50 {
    u8 pad00[0x20];
    void *unk20;
    s16 unk24;
    s16 unk26;
} Sub8007CD50;

typedef struct Obj8007CD50 {
    u8 pad00[0xC];
    s32 unkC;
    f32 unk10;
    f32 unk14;
    u8 pad18[0x40 - 0x18];
    Node8007CD50 *unk40;
    Node8007CD50 *unk44;
    u8 pad48[0x4C - 0x48];
    Sub8007CD50 *unk4C;
    s32 unk50;
    s32 unk54;
} Obj8007CD50;

typedef struct Tag8007CD50 {
    u32 unk0;
    f32 unk4;
    f32 unk8;
} Tag8007CD50;

extern void func_8007C818(Obj8007CD50 *, void *);
extern void func_80006EB4(void *, f32);
extern s32 func_800181BC(void *, s32, s32, s32, s32);
extern void func_8003FD7C(Obj8007CD50 *);
extern s32 func_80082BE0(void);
extern void func_80070764(void *, s32);
extern void func_8007B544(void *, s32, s32, f32);
extern void func_8003FA24(u32, Tag8007CD50 *);
extern void func_8007E988(void *);
extern void func_8007C64C(Obj8007CD50 *, void *);
extern void func_80008B14(s32, s32, f32, f32, s32);
extern void func_8007CC48(Obj8007CD50 *, s32);
extern void func_8003E1EC(u8 *, f32);
extern void func_800704A8(void *, f32);

void func_8007CD50(Obj8007CD50 *obj, void *arg1, s32 arg2) {
    f32 pad0[4];
    u8 text[388];
    f32 filler[5];
    Tag8007CD50 tag;
    f32 pad2[2];

    (void)arg2;
    (void)filler;
    (void)pad2;
    (void)pad0;
    obj->unk14 = 0.0f;
    switch (obj->unk4C->unk24) {
        case 0x64:
            func_8007C818(obj, arg1);
            break;
        case 0x65:
            obj->unkC |= 1;
            if (obj->unk40 != 0) {
                obj->unk40->unk100 &= ~0x10;
                if (obj->unk10 > 3.0f) {
                    obj->unk10 = 0.0f;
                    if (obj->unk40->unk110 <= 0.0f) {
                        func_80006EB4(obj->unk40, 20.0f);
                    } else {
                        func_80006EB4(obj->unk40, -20.0f);
                    }
                }
            }
            break;
        case 0x66:
            func_8007C818(obj, arg1);
            break;
        case 0x67:
            if (obj->unk4C != 0) {
                if (obj->unk4C->unk20 != 0) {
                    func_800181BC(obj->unk4C->unk20, 2, -4, 0x10, 3);
                }
                func_800181BC(obj->unk4C->unk20, 0, -3, 0x10, 3);
                obj->unk4C->unk26 |= 1;
                obj->unkC &= ~1;
                func_8003FD7C(obj);
            }
            break;
        case 0x68:
            if ((f32)func_80082BE0() / 2147483648.0f < 0.5) {
                func_80070764(arg1, 1);
            } else {
                func_80070764(arg1, 2);
            }
            break;
        case 0x69:
            obj->unkC |= 1;
            obj->unk4C->unk26 |= 1;
            func_8007B544(obj->unk4C->unk20, 0, 0x10000000, 0.6f);
            tag.unk0 = 0x5368616B;
            tag.unk4 = 0.05f;
            tag.unk8 = 4.0f;
            func_8003FA24(0x634D616E, &tag);
            obj->unk10 = 0.0f;
            break;
        case 0x6A:
            func_8007E988(arg1);
            break;
        case 0x6C:
            func_8007C64C(obj, arg1);
            break;
        case 0xC9:
        case 0xCA:
            func_8007C818(obj, arg1);
            break;
        case 0xCB:
            if (!(obj->unkC & 1)) {
                obj->unk10 = 100.0f;
            }
            obj->unkC |= 1;
            if (obj->unk10 > 3.0f) {
                obj->unk10 = 0.0f;
                func_80008B14(0x30, 7, 0.25f, 1.0f, 0);
                func_8007E988(arg1);
            }
            break;
        case 0xD4:
            func_8007C818(obj, arg1);
            break;
        case 0xD5:
            if (obj->unk4C != 0) {
                obj->unk4C->unk26 |= 1;
                tag.unk0 = 0x5368616B;
                tag.unk4 = 0.25f;
                tag.unk8 = 8.0f;
                func_8003FA24(0x634D616E, &tag);
                obj->unkC |= 1;
                obj->unkC &= ~4;
                obj->unk54 = 0;
                obj->unk50 = 0;
                obj->unk10 = 0.0f;
            }
            break;
        case 0x12D:
            break;
        case 0x130:
            if (obj->unk44 != 0) {
                func_80006EB4(obj->unk44, 1.0f);
            }
            if (obj->unk40 != 0) {
                func_80006EB4(obj->unk40, 1.0f);
            }
            obj->unk4C->unk26 |= 1;
            obj->unkC &= ~1;
            func_8003FD7C(obj);
            break;
        case 0x132:
            if (obj->unk4C != 0) {
                obj->unk4C->unk26 |= 1;
                tag.unk0 = 0x5368616B;
                tag.unk4 = 0.25f;
                tag.unk8 = 8.0f;
                func_8003FA24(0x634D616E, &tag);
                obj->unkC |= 1;
                obj->unkC &= ~4;
                obj->unk54 = 0;
                obj->unk50 = 0;
                obj->unk10 = 0.0f;
            }
            break;
        case 0x133:
            obj->unkC |= 1;
            if (obj->unk4C->unk20 != 0) {
                if (obj->unk10 > 3.0f) {
                    obj->unk10 = 0.0f;
                    func_8007B544(obj->unk4C->unk20, 0x10, 0, 1.0f);
                }
            }
            break;
        case 0x138:
            obj->unkC |= 1;
            obj->unk4C->unk26 |= 1;
            func_8007B544(obj->unk4C->unk20, 0, 0x10000000, 0.6f);
            tag.unk0 = 0x5368616B;
            tag.unk4 = 0.05f;
            tag.unk8 = 4.0f;
            func_8003FA24(0x634D616E, &tag);
            obj->unk10 = 0.0f;
            break;
        case 0x13A:
            func_8007CC48(obj, 0);
            break;
        case 0x1F5:
            func_8007CC48(obj, 5);
            break;
        case 0x384:
            func_8003E1EC(text, 3.0f);
            func_800704A8(arg1, 0.0f);
            break;
    }
}
