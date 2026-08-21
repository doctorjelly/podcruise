/* Independently written from $S/specs/func_80065810.md. */
#include "podcruise/types.h"

typedef struct Thing {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ f32 unk20[0xC];
    /* 0x50 */ f32 unk50[4];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ s32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ s32 unk6C;
    /* 0x70 */ s32 unk70;
    /* 0x74 */ f32 unk74[3];
    /* 0x80 */ f32 unk80;
    /* 0x84 */ f32 unk84;
    /* 0x88 */ f32 unk88;
    /* 0x8C */ f32 unk8C;
    /* 0x90 */ f32 unk90;
    /* 0x94 */ f32 unk94;
    /* 0x98 */ f32 unk98;
    /* 0x9C */ f32 unk9C;
    /* 0xA0 */ f32 unkA0;
    /* 0xA4 */ f32 unkA4;
    /* 0xA8 */ f32 unkA8;
    /* 0xAC */ f32 unkAC;
    /* 0xB0 */ f32 unkB0;
    /* 0xB4 */ f32 unkB4[4];
    /* 0xC4 */ f32 unkC4[4];
    /* 0xD4 */ f32 unkD4;
    /* 0xD8 */ f32 unkD8;
} Thing;

extern Thing *func_8003FBD4(s32 tag);
extern void func_80017520(f32 *matrix, f32 x, f32 y, f32 z);
extern void func_80015288(f32 *destination, f32 *source);
extern void func_80015268(f32 *output, f32 x, f32 y, f32 z);
extern void func_80016D78(f32 *vector, f32 x, f32 y, f32 z, f32 w);

extern f32 D_800AD468;
extern f32 D_800AD46C;
extern f32 D_800AD470;
extern f32 D_800AD474;
extern f32 D_800AD478;
extern f32 D_800AD47C;

Thing *func_80065810(s32 kind, s32 arg1, f32 arg2, f32 *arg3, f32 scale) {
    Thing *thing;
    s32 count;
    f32 zero;

    thing = func_8003FBD4(0x536D6F6B);
    if (thing == 0) {
        return 0;
    }

    thing->unk60 = kind;
    thing->unk64 = arg1;
    thing->unk68 = arg2;
    func_80017520(thing->unk20, scale, scale, scale);
    func_80015288(thing->unk50, arg3);

    switch (kind) {
        case 6:
            zero = 0.0f;
            count = 5;
            thing->unk70 = count;
            func_80015268(thing->unk74, zero, (f32)(count * -2.0 * scale), zero);
            thing->unk88 = scale;
            thing->unk8C = scale * 3.0f;
            thing->unk90 = scale * 10.0f;
            thing->unk94 = scale * 5.0f;
            thing->unk98 = 360.0;
            thing->unk9C = -9.0;
            thing->unkA0 = D_800AD468;
            thing->unkA4 = 0.0;
            thing->unkA8 = 3.0f;
            thing->unkAC = 1.0;
            thing->unkB0 = 0.5;
            func_80016D78(thing->unkB4, 1.0f, 1.0f, 1.0f, 1.0f);
            func_80016D78(thing->unkC4, zero, zero, zero, 1.0f);
            thing->unk80 = D_800AD46C;
            thing->unk84 = 0.5;
            thing->unkD4 = 0.0;
            thing->unkD8 = 0.0;
            break;
        case 2:
        case 3:
            zero = 0.0f;
            count = 5;
            thing->unk70 = count;
            func_80015268(thing->unk74, zero, zero, (f32)(count * 2.0 * scale));
            thing->unk88 = scale;
            thing->unk8C = scale * 5.0f;
            thing->unk94 = scale * 5.0f;
            thing->unk90 = scale * 10.0f;
            thing->unk98 = 360.0;
            thing->unk9C = -9.0;
            thing->unkA0 = D_800AD470;
            thing->unkA4 = 0.0;
            thing->unkA8 = 3.0f;
            thing->unkAC = 1.0;
            thing->unkB0 = 0.5;
            func_80016D78(thing->unkB4, 1.0f, 1.0f, 1.0f, 1.0f);
            func_80016D78(thing->unkC4, zero, zero, zero, 1.0f);
            thing->unk80 = D_800AD474;
            thing->unk84 = 0.5;
            thing->unkD4 = 0.0;
            thing->unkD8 = 0.0;
            break;
        case 8:
            zero = 0.0f;
            count = 5;
            thing->unk70 = count;
            func_80015268(thing->unk74, zero, (f32)(count * -2.0 * scale), zero);
            thing->unk88 = scale;
            thing->unk8C = scale * 3.0f;
            thing->unk90 = scale * 10.0f;
            thing->unk94 = scale * 5.0f;
            thing->unk98 = 360.0;
            thing->unk9C = -9.0;
            thing->unkA0 = D_800AD478;
            thing->unkA4 = 0.5;
            thing->unkA8 = 3.0f;
            thing->unkAC = 1.0;
            thing->unkB0 = 0.5;
            func_80016D78(thing->unkB4, 1.0f, 1.0f, 1.0f, 1.0f);
            func_80016D78(thing->unkC4, zero, zero, zero, 1.0f);
            thing->unk80 = D_800AD47C;
            thing->unk84 = 0.5;
            thing->unkD4 = 0.0;
            thing->unkD8 = 0.0;
            break;
    }

    return thing;
}
