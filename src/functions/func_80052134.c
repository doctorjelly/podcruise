/* Independently written from specs/functions/func_80052134.md. */

#include "podcruise/types.h"

typedef struct {
    u8 pad00[0xE0];
    f32 unkE0;
    u8 padE4[4];
    f32 unkE8;
} Track80052134;

typedef struct {
    u8 pad00[0x78];
    s32 unk78;
    u8 pad7C[8];
    Track80052134 *unk84;
} Racer80052134;

f32 func_80052134(Racer80052134 *racer) {
    Track80052134 *track;
    f32 position;
    f32 origin;
    f32 offset;
    f32 result;

    track = racer->unk84;
    position = track->unkE8;
    origin = track->unkE0;

    if (position < origin) {
        offset = -(position - origin);
    } else {
        offset = position - origin;
    }
    if (offset > 0.5f) {
        offset = 1.0f - offset;
    }

    result = ((f32)racer->unk78 + position) - offset;
    if (result < 0.0f) {
        result = 0.0f;
    }
    return result;
}
