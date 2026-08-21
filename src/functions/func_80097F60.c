/* Recovered from specification specs/func_80097F60.md (worker group42). */
#include "podcruise/types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} Struct80097F60;

Struct80097F60 func_80097F60(s32 numerator, s32 denominator) {
    Struct80097F60 result;

    result.unk0 = numerator / denominator;
    result.unk4 = numerator - denominator * result.unk0;
    if (result.unk0 < 0 && result.unk4 > 0) {
        result.unk0++;
        result.unk4 -= denominator;
    }
    return result;
}
