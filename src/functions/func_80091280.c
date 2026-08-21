/* Implements specs/func_80091280.md (two-stage retry then block compare). */
#include "podcruise/types.h"

typedef struct Unk80091280 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 unk0C[0x59];
    /* 0x65 */ u8 unk65;
} Unk80091280;

extern s32 func_80091FD0(Unk80091280 *object, s32 mode);
extern s32 func_80092050(s32 first, s32 second, s32 mode, u8 *buffer);
extern s32 func_80096AD0(u8 *left, u8 *right, s32 length);

s32 func_80091280(Unk80091280 *object) {
    u8 buffer[0x20];
    s32 result;

    if (object->unk65 != 0) {
        result = func_80091FD0(object, 0);
        if (result == 2) {
            result = func_80091FD0(object, 0);
        }
        if (result != 0) {
            return result;
        }
    }

    result = func_80092050(object->unk04, object->unk08, 1, buffer);
    if (result != 0) {
        if (result != 2) {
            return result;
        }
        result = func_80092050(object->unk04, object->unk08, 1, buffer);
        if (result != 0) {
            return result;
        }
    }

    if (func_80096AD0(object->unk0C, buffer, 0x20) != 0) {
        return 2;
    }
    return 0;
}
