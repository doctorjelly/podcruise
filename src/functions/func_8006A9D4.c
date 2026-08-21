/* Recovered from specs/functions/recovered/medium_core_tranche.md. */
#include "podcruise/types.h"

typedef struct Obj8006A9D4 {
    u8 pad00[0x60];
    s32 unk60;
    s32 unk64;
    u8 pad68[0xAC - 0x68];
    u8 unkAC[0x13C - 0xAC];
    void *unk13C;
    u8 pad140[0x154 - 0x140];
    f32 unk154;
    f32 unk158;
    f32 unk15C;
    u8 pad160[0x1998 - 0x160];
    s32 unk1998;
} Obj8006A9D4;

extern void func_8003B184(void *, void *, f32);
extern void func_800678A8();
extern void func_80069EC0(Obj8006A9D4 *, f32 *, f32 *);
extern s32 func_80033010(f32 *, f32 *, void *, void *);

f32 func_8006A9D4(Obj8006A9D4 *self, f32 *pos, s32 arg2, f32 *out);

f32 func_8006A9D4(Obj8006A9D4 *self, f32 *pos, s32 arg2, f32 *out) {
    f32 work[16];
    f32 result;
    f32 delta[3];
    f32 saved[3];
    f32 spare[3];

    (void)arg2;
    saved[0] = pos[0];
    saved[1] = pos[1];
    saved[2] = pos[2];
    result = 0.0f;
    self->unk64 &= ~0x200;
    if (!(((f32)self->unk1998 - 400.0f) / 600.0f < 1.0) &&
        !(self->unk60 & 0x20) && !(self->unk64 & 0x04000000)) {
        if ((self->unk60 & 0xF) != 2) {
            pos[2] = 0.0f;
        } else {
            func_8003B184(self->unkAC, work, 0.0f);
            pos[2] = work[14];
        }
        result = 2.0f;
        out[1] = 0.0f;
        out[0] = 0.0f;
        out[2] = 1.0f;
        if ((self->unk60 & 0xF) == 2) {
            self->unk64 |= 2;
        }
    } else if (self->unk60 & 0x20) {
        delta[0] = pos[0];
        delta[1] = pos[1];
        delta[2] = pos[2];
        func_800678A8(self, pos);
        delta[0] = pos[0] - delta[0];
        delta[1] = pos[1] - delta[1];
        delta[2] = pos[2] - delta[2];
        delta[0] = self->unk154 + delta[0];
        delta[1] = self->unk158 + delta[1];
        delta[2] = self->unk15C + delta[2];
        func_80069EC0(self, delta, out);
    } else {
        func_80033010(pos, saved, self->unk13C, spare);
    }
    return result;
}
