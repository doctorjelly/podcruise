/* Recovered from specification $S/specs/func_800678A8.md */
#include "podcruise/types.h"

typedef struct Obj800678A8 {
    u8 pad00[0x40];
    f32 unk40[3];
    u8 pad4C[0xA8 - 0x4C];
    f32 unkA8;
    u8 padAC[0x13C - 0xAC];
    void *unk13C;
    u8 pad140[0x1A0 - 0x140];
    f32 unk1A0;
    u8 pad1A4[0x208 - 0x1A4];
    f32 unk208;
} Obj800678A8;

extern f32 D_800AD4DC;

extern s32 func_80004670(void *, void *, f32, f32 *, f32, f32, f32 *, f32 *, f32 *);
extern void func_80000538(void);
extern void func_80033010(void *, void *, void *, f32 *);
extern void func_80067718(Obj800678A8 *, f32, f32, f32 *, f32 *, s32);

void func_800678A8(Obj800678A8 *obj, void *arg1, void *arg2) {
    f32 sp9C;
    f32 sp90[3];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    s32 *cp;
    s32 pad64;
    s32 count;
    f32 sp54[3];
    f32 sp48[3];
    f32 mag;
    f32 base;
    f32 dot;

    mag = (obj->unk208 < 0.0f) ? -obj->unk208 : obj->unk208;
    base = obj->unkA8;
    sp9C = base - ((base * 0.75f) * mag);
    if (sp9C < 1.5f) {
        sp9C = 1.5f;
    }
    cp = &count;
    count = 0;
    if (func_80004670(obj->unk13C, arg1, sp9C, obj->unk40, 1.0f, -1.0f, sp78, sp48, sp90)) {
        count = 1;
        func_80000538();
        if (func_80004670(obj->unk13C, arg1, sp9C, obj->unk40, 1.0f, -1.0f, sp6C, sp48, sp84)) {
            *cp = *cp + 1;
            func_80000538();
        }
    }
    if (count > 0) {
        if (50.0f < obj->unk1A0) {
            dot = (obj->unk40[2] * sp78[2]) + ((sp78[0] * obj->unk40[0]) + (sp78[1] * obj->unk40[1]));
            if (dot < 0.5f) {
                if (-dot < 0.5f) {
                    func_80067718(obj, obj->unk1A0 * D_800AD4DC, 0.3f, sp90, sp78, 1);
                }
            }
        }
    }
    (void)pad64;
    func_80033010(arg1, arg2, obj->unk13C, sp54);
}
