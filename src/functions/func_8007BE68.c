/* Independently written from $S/specs/func_8007BE68.md */
#include "podcruise/types.h"

typedef struct Obj8007BE68 {
    s32 unk00;
    s32 unk04;
    s32 kind;
    s32 flags;
    f32 unk10;
    f32 unk14;
} Obj8007BE68;

extern f64 D_80120BF0;

extern s32 func_8007B7BC(s32 group);
extern void func_8007B828(Obj8007BE68 *obj);
extern void func_8007BBEC(Obj8007BE68 *obj, s32 arg1);
extern void func_8007BDF4(Obj8007BE68 *obj);

void func_8007BE68(Obj8007BE68 *obj) {
    if (obj->flags & 1) {
        obj->unk10 = obj->unk10 + D_80120BF0;
        obj->unk14 = obj->unk14 + D_80120BF0;
        if (obj->kind == 0x64) {
            if (func_8007B7BC(0)) {
                func_8007B828(obj);
            }
        }
        if (obj->kind == 0x66) {
            if (func_8007B7BC(0)) {
                func_8007B828(obj);
            }
        }
        if (obj->kind == 0x69) {
            func_8007BDF4(obj);
        }
        if (obj->kind == 0x6C) {
            if (func_8007B7BC(2)) {
                func_8007B828(obj);
            }
        }
        if (obj->kind == 0xC9) {
            if (func_8007B7BC(0)) {
                func_8007B828(obj);
            }
        }
        if (obj->kind == 0xCA) {
            if (func_8007B7BC(1)) {
                func_8007B828(obj);
            }
        }
        if (obj->kind == 0xD4) {
            if (func_8007B7BC(0)) {
                func_8007B828(obj);
            }
        }
        if (obj->kind == 0xD5) {
            func_8007BBEC(obj, 3);
        }
        if (obj->kind == 0x132) {
            func_8007BBEC(obj, 1);
        }
        if (obj->kind == 0x138) {
            func_8007BDF4(obj);
        }
        if (obj->kind == 0x13A) {
            if (func_8007B7BC(0)) {
                func_8007B828(obj);
            }
        }
        if (obj->kind == 0x1F5) {
            if (func_8007B7BC(5)) {
                func_8007B828(obj);
            }
        }
    }
}
