/* Independently written from specs/functions/recovered/func_8006A49C.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3;

typedef struct {
    /* 0x000 */ u8 pad000[0x388];
    /* 0x388 */ f32 unk388;
    /* 0x38C */ u8 pad38C[0x3C];
    /* 0x3C8 */ f32 unk3C8;
    /* 0x3CC */ u8 pad3CC[0x3C];
    /* 0x408 */ f32 unk408;
    /* 0x40C */ u8 pad40C[0x3C];
    /* 0x448 */ f32 unk448;
} Part;

typedef struct {
    /* 0x0000 */ u8 pad0000[0x60];
    /* 0x0060 */ u32 unk60;
    /* 0x0064 */ u32 unk64;
    /* 0x0068 */ u8 pad0068[0x44];
    /* 0x00AC */ u8 unkAC[0x40];
    /* 0x00EC */ u32 unkEC;
    /* 0x00F0 */ u8 pad00F0[0x4C];
    /* 0x013C */ void *unk13C;
    /* 0x0140 */ u32 unk140;
    /* 0x0144 */ u8 pad0144[0x10];
    /* 0x0154 */ f32 unk154;
    /* 0x0158 */ f32 unk158;
    /* 0x015C */ f32 unk15C;
    /* 0x0160 */ f32 unk160;
    /* 0x0164 */ f32 unk164;
    /* 0x0168 */ f32 unk168;
    /* 0x016C */ u8 pad016C[0x18];
    /* 0x0184 */ f32 unk184;
    /* 0x0188 */ f32 unk188;
    /* 0x018C */ f32 unk18C;
    /* 0x0190 */ u8 pad0190[0xDB0];
    /* 0x0F40 */ Part unkF40;
    /* 0x138C */ u8 pad138C[0x60C];
    /* 0x1998 */ s32 unk1998;
} Racer;

typedef struct {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s32 unk08;
} Owner;

extern f32 D_800AD5AC;
extern f32 D_800AD5B0;
extern f32 D_800AD5B4;

extern void func_8003B184(void *, void *, f32);
extern f32 func_800154D0(Vec3 *);
extern s32 func_80033010(Vec3 *, Vec3 *, void *, void *);
extern f32 func_80066144(Racer *, Vec3 *, s32, f32, Vec3 *);
extern f32 func_800670CC(Racer *, Vec3 *, Vec3 *);
extern void func_800672D4(Racer *, Vec3 *, f32);
extern void func_800678A8(Racer *, Vec3 *, void *);
extern void func_800695D4(Racer *, Vec3 *, void *, f32, Vec3 *, void *, void *);
extern void func_80069A64(Racer *, Vec3 *, void *, f32, Vec3 *, void *, void *);
extern void func_80069EC0(Racer *, Vec3 *, Vec3 *);

f32 func_8006A49C(Racer *racer, Vec3 *point, void *ctx, Vec3 *out, Owner *owner) {
    u8 scratchB[0x40];
    f32 result;
    Vec3 spareA;
    Vec3 spareB;
    Vec3 delta;
    Vec3 origin;
    Vec3 spareC;
    u8 scratchA[0x40];
    u32 flags;
    u32 state;
    f32 ratio;
    Part *part;
    f32 level;

    (void)spareA; (void)spareB; (void)spareC;

    part = &racer->unkF40;
    origin.x = point->x;
    origin.y = point->y;
    origin.z = point->z;
    if (!(((f32)racer->unk1998 - 400.0f) / 600.0f < 1.0) && (racer->unk60 & 0x20) == 0 &&
            (racer->unk64 & 0x04000000) == 0) {
        flags = racer->unk60;
        state = racer->unk64;
        racer->unk64 = state | 0x20000000;
        racer->unk140 = racer->unkEC;
        if ((flags & 0xF) == 2) {
            func_8003B184(racer->unkAC, scratchB, 0.0f);
            point->z = *(f32 *)&scratchB[0x38];
        }
        result = 2.0f;
        out->x = 0.0f;
        out->y = 0.0f;
        out->z = 1.0f;
        if ((racer->unk60 & 0xF) == 2) {
            racer->unk64 |= 2;
        }
    } else {
        state = racer->unk64;
        if ((state & 0x400000) != 0 && (state & 0x800000) != 0) {
            result = point->z - racer->unk188;
            out->x = racer->unk160;
            out->y = racer->unk164;
            out->z = racer->unk168;
            racer->unk64 |= 0x20000000;
            racer->unk140 = racer->unkEC;
        } else {
            result = func_800670CC(racer, point, out);
            state = racer->unk64;
            if (state & 0x800000) {
                racer->unk64 = state | 0x400000;
            } else {
                racer->unk64 = state & ~0x400000;
            }
        }

        if (racer->unk64 & 0x400) {
            if (out->z < D_800AD5AC) {
                out->z = D_800AD5AC;
                func_800154D0(out);
            }
        }
        racer->unk160 = out->x;
        racer->unk164 = out->y;
        racer->unk168 = out->z;
        flags = racer->unk60;
        if ((flags & 0x5000) == 0) {
            if (D_800AD5B0 < racer->unk18C || D_800AD5B0 < -racer->unk18C || (flags & 0x2000) == 0) {
                if (racer->unk64 & 0x400) {
                    func_80069A64(racer, point, ctx, result, out, &spareA, &spareB);
                } else {
                    func_800695D4(racer, point, ctx, result, out, &spareA, &spareB);
                }
                flags = racer->unk60;
            }
        }
        if ((flags & 0x04000000) == 0) {
            func_800672D4(racer, point, result);
            flags = racer->unk60;
        }
        if (result < 0.0f) {
            result = 2.0f;
        }
        if ((flags & 0xF) == 2 && (flags & 0x20) == 0) {
            ratio = ((f32)racer->unk1998 - 400.0f) / 600.0f;
            if (0.0 <= ratio && ratio <= 1.0) {
                func_8003B184(racer->unkAC, scratchA, 0.0f);
                point->z = point->z + (*(f32 *)&scratchA[0x38] - point->z) *
                           (((f32)racer->unk1998 - 400.0f) / 600.0f);
            }
        }
        state = racer->unk64;
        if ((state & 0x800000) == 0) {
            if (racer->unk60 & 0x20) {
                delta.x = point->x;
                delta.y = point->y;
                delta.z = point->z;
                func_800678A8(racer, point, ctx);
                delta.x = point->x - delta.x;
                delta.y = point->y - delta.y;
                delta.z = point->z - delta.z;
                delta.x = racer->unk154 + delta.x;
                delta.y = racer->unk158 + delta.y;
                delta.z = racer->unk15C + delta.z;
                func_80069EC0(racer, &delta, out);
            } else {
                func_80033010(point, &origin, racer->unk13C, &spareC);
            }
        }
        if (((f32)racer->unk1998 - 40.0f) / 60.0f < 1.0) {
            result = func_80066144(racer, point, owner->unk08, result, out);
        } else {
            level = D_800AD5B4;
            part->unk388 = level;
            part->unk3C8 = level;
            part->unk408 = level;
            part->unk448 = level;
        }
    }
    racer->unk184 = result;
    return result;
}
