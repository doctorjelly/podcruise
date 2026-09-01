/* Independently written from specs/functions/recovered/medium_world_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0xE0];
    /* 0x0E0 */ f32 unkE0;
    /* 0x0E4 */ f32 unkE4;
    /* 0x0E8 */ u8 padE8[0x08];
    /* 0x0F0 */ f32 unkF0;
    /* 0x0F4 */ f32 unkF4;
    /* 0x0F8 */ f32 unkF8;
    /* 0x0FC */ f32 unkFC;
    /* 0x100 */ u32 unk100;
    /* 0x104 */ s32 unk104;
    /* 0x108 */ u8 pad108[0x08];
    /* 0x110 */ f32 unk110;
    /* 0x114 */ f32 unk114;
    /* 0x118 */ s32 unk118;
    /* 0x11C */ f32 *unk11C;
} Obj80006848;

extern f64 D_80120BF0;
extern f32 D_8009A2A4;
extern s32 func_80006704(Obj80006848 *);
extern void func_80006790(Obj80006848 *, f32, f32);

void func_80006848(Obj80006848 *obj) {
    f32 upper;
    f32 lower;
    f32 step;
    f32 *keys;

    obj->unk100 = obj->unk100 & 0xBFFFFFFF;
    if (obj->unk100 & 0x01000000) {
        obj->unk100 = obj->unk100 & 0xFEFFFFFF;
    } else if (obj->unk100 & 0x20000000) {
        obj->unk100 = obj->unk100 | 0x40000000;
        obj->unkE4 = (f32)((f64)obj->unkE4 + D_80120BF0 / (f64)obj->unkE0);
        if (obj->unkE4 >= 1.0f) {
            obj->unk100 = obj->unk100 & 0xDFFFFFFF;
            obj->unk114 = obj->unk114 + (obj->unkE4 - 1.0f) * obj->unkE0 * obj->unk110 * D_8009A2A4;
        }
    } else {
        obj->unk114 = (f32)((f64)obj->unk114 + D_80120BF0 * (f64)obj->unk110 * (f64)D_8009A2A4);
    }

    if ((obj->unk100 & 0x06000000) != 0) {
        if (obj->unkF0 <= obj->unk114 && obj->unk114 <= obj->unkF4) {
            if (obj->unk100 & 0x02000000) {
                obj->unk100 = obj->unk100 & 0xFDFFFFFF;
                obj->unk100 = obj->unk100 | 0x10;
            } else {
                obj->unk100 = obj->unk100 & 0xFBFFFFFF;
                obj->unk100 = obj->unk100 & ~0x10;
            }
        } else {
            upper = step = obj->unkFC;
            lower = 0.0f;
        }
    }

    if ((obj->unk100 & 0x06000000) == 0) {
        upper = obj->unkF4;
        lower = obj->unkF0;
        step = obj->unkF8;
    }

    if (upper < obj->unk114) {
        if (!(obj->unk100 & 0x10)) {
            obj->unk114 = upper;
        } else if (obj->unk100 & 0x40) {
            func_80006790(obj, upper, lower);
        } else {
            while (upper < obj->unk114) {
                obj->unk114 = obj->unk114 - step;
                obj->unk100 |= 0x40000000;
            }
        }
        obj->unk118 = func_80006704(obj);
    } else if (obj->unk114 < lower) {
        if (!(obj->unk100 & 0x10)) {
            obj->unk114 = lower;
        } else if (obj->unk100 & 0x40) {
            func_80006790(obj, lower, upper);
        } else {
            while (obj->unk114 < lower) {
                obj->unk114 = obj->unk114 + step;
                obj->unk100 |= 0x40000000;
            }
        }
        obj->unk118 = func_80006704(obj);
    } else {
        keys = obj->unk11C;
        while (obj->unk114 < keys[obj->unk118] && obj->unk118 > 0) {
            obj->unk118 = obj->unk118 - 1;
        }
        while (keys[obj->unk118 + 1] < obj->unk114 && obj->unk118 < obj->unk104 - 2) {
            obj->unk118 = obj->unk118 + 1;
        }
    }
}
