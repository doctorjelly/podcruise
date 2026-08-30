/* Independently written from specs/functions/recovered/func_80008F6C.md. */

#include "podcruise/types.h"

extern s16 D_8009A6F0[];
extern s16 D_8009A758[];
extern s16 D_8009A7A4[];
extern s16 D_8009A818[];
extern s16 D_8009A824[];
extern s16 D_8009A8F4[];
extern s16 D_8009AA48[];
extern s16 D_8009AB1C[];

s32 func_80008F6C(s32 group, s32 owner, s32 detail) {
    s32 value;

    if (detail == -1) {
        return -1;
    }

    switch (group) {
    case 0:
        if ((owner < 0) || (owner >= 23)) {
            return -1;
        }
        if ((detail <= 0) || ((u32)detail >= 51)) {
            return -1;
        }
        value = D_8009A6F0[detail];
        break;
    case 1:
        if ((owner < 0) || (owner >= 23)) {
            return -1;
        }
        if ((detail <= 0) || ((u32)detail >= 38)) {
            return -1;
        }
        value = D_8009A758[detail];
        break;
    case 2:
        if ((detail <= 0) || ((u32)detail >= 57)) {
            return -1;
        }
        value = D_8009A7A4[detail];
        break;
    case 3:
        if ((detail <= 0) || ((u32)detail >= 5)) {
            return -1;
        }
        value = D_8009A818[detail];
        break;
    case 4:
        if ((detail <= 0) || ((u32)detail >= 104)) {
            return -1;
        }
        value = D_8009A824[detail];
        break;
    case 5:
        if ((detail <= 0) || ((u32)detail >= 169)) {
            return -1;
        }
        value = D_8009A8F4[detail];
        break;
    case 6:
        if ((detail <= 0) || ((u32)detail >= 105)) {
            return -1;
        }
        value = D_8009AA48[detail];
        break;
    case 7:
        if ((detail <= 0) || ((u32)detail >= 168)) {
            return -1;
        }
        value = D_8009AB1C[detail];
        break;
    default:
        return -1;
    }

    group <<= 24;
    value = (value | group) | (owner << 16);
    return value | 0x8000;
}
