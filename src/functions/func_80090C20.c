/* Independently written from specs/func_80090C20.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x59];
    /* 0x65 */ u8 unk65;
} Context;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ long long unk08;
    /* 0x10 */ long long unk10;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u16 unk1E;
} Packet;

extern u32 func_8008C550(void);
extern s32 func_80090B24(u16 *values, u16 *total, u16 *complementTotal);
extern s32 func_80091FD0(Context *arg0, u8 arg1);
extern s32 func_80092050(void *arg0, s32 arg1, u16 arg2, void *arg3);
extern s32 func_800928F0(void *arg0, s32 arg1, u16 arg2, u8 *arg3, s32 arg4);

s32 func_80090C20(Context *context, Packet *source, Packet *destination) {
    s32 attempt;
    u8 high[32];
    u8 low[32];
    u8 *invert;
    u8 *walk;
    u8 *code;
    u16 codes[4];
    s32 result;

    attempt = 0;
    destination->unk00 = -1;
    destination->unk04 = func_8008C550();
    destination->unk08 = source->unk08;
    destination->unk10 = source->unk10;

    if (context->unk65 != 0) {
        result = func_80091FD0(context, 0);
        if (result != 0) {
            return result;
        }
    }

    do {
        result = func_80091FD0(context, attempt);
        if (result != 0) {
            return result;
        }
        result = func_80092050(context->unk04, context->unk08, 0, high);
        if (result != 0) {
            return result;
        }
        high[0] = attempt | 0x80;
        for (invert = &high[1]; invert < &high[32]; invert++) {
            *invert = ~*invert;
        }
        result = func_800928F0(context->unk04, context->unk08, 0, high, 0);
        if (result != 0) {
            return result;
        }
        result = func_80092050(context->unk04, context->unk08, 0, low);
        if (result != 0) {
            return result;
        }
        walk = low;
        invert = high;
        for (;;) {
            if (*walk != *invert) {
                break;
            }
            walk++;
            invert++;
            if (walk >= high) {
                break;
            }
        }
        if (walk != &low[32]) {
            break;
        }
        if (attempt > 0) {
            result = func_80091FD0(context, 0);
            if (result != 0) {
                return result;
            }
            result = func_80092050(context->unk04, context->unk08, 0, high);
            if (result != 0) {
                return result;
            }
            if (high[0] != 0x80) {
                break;
            }
        }
        attempt++;
    } while (attempt < 0x3E);

    if (context->unk65 != 0) {
        result = func_80091FD0(context, 0);
        if (result != 0) {
            return result;
        }
    }

    destination->unk1A = attempt;
    destination->unk18 = (attempt > 0 ? 1 : 0) | (source->unk18 & 0xFFFE);
    destination->unk1B = source->unk1B;
    func_80090B24((u16 *)destination, &destination->unk1C, &destination->unk1E);

    codes[0] = 1;
    codes[1] = 3;
    codes[2] = 4;
    codes[3] = 6;
    for (code = (u8 *)codes; code < (u8 *)&codes[4]; code += 2) {
        result = func_800928F0(context->unk04, context->unk08,
                               *(u16 *)code, (u8 *)destination, 1);
        if (result != 0) {
            return result;
        }
    }

    result = func_80092050(context->unk04, context->unk08, 1, high);
    if (result != 0) {
        return result;
    }

    for (attempt = 0; attempt < 32; attempt++) {
        if (high[attempt] != ((u8 *)destination)[attempt]) {
            return 0xA;
        }
    }

    return 0;
}
