/* Independently written from the specification in specs/func_80091354.md. */
#include "podcruise/types.h"

typedef struct Pc91354Object {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 pad0C[0x48];
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 pad64[1];
    /* 0x65 */ u8 unk65;
} Pc91354Object;

extern s32 D_800A7ED0;
extern u8 D_800A7ED4;
extern u8 D_8014C3D0[];

extern u16 func_80090AB0(u8 *bytes, s32 count);
extern s32 func_80091FD0(void *object, u8 value);
extern s32 func_80092050(void *arg0, s32 arg1, u16 arg2, void *arg3);
extern void *func_80092250(void *arg0, void *arg1, s32 arg2);
extern s32 func_800928F0(void *arg0, s32 arg1, u16 arg2, u8 *arg3, s32 arg4);

s32 func_80091354(object, out, mode, key)
Pc91354Object *object;
u8 *out;
u8 mode;
u8 key;
{
    s32 result;
    s32 count;
    s32 index;
    u8 *buffer;
    s32 base;

    if (mode == 0) {
        if (key == D_800A7ED4 && object->unk08 == D_800A7ED0) {
            func_80092250(D_8014C3D0, out, 0x100);
            return 0;
        }
    }

    if (object->unk65 != 0) {
        result = func_80091FD0(object, 0);
        if (result != 0) {
            return result;
        }
    }

    if (key > 0) {
        count = 1;
    } else {
        count = object->unk60;
    }

    if (mode == 1) {
        out[1] = func_80090AB0(out + count * 2, -count * 2 + 0x100);
    }

    base = key * 8;
    for (index = 0, buffer = out; index < 8; index++) {
        if (mode == 1) {
            func_800928F0(object->unk04, object->unk08, object->unk54 + base + index, buffer, 0);
            result = func_800928F0(object->unk04, object->unk08, object->unk58 + base + index, buffer, 0);
        } else {
            result = func_80092050(object->unk04, object->unk08, object->unk54 + base + index, buffer);
        }
        if (result != 0) {
            return result;
        }
        buffer += 0x20;
    }

    if (mode == 0) {
        if ((u8)func_80090AB0(out + count * 2, -count * 2 + 0x100) != out[1]) {
            buffer = out;
            for (index = 0; index < 8; index++) {
                func_80092050(object->unk04, object->unk08, object->unk58 + base + index, buffer);
                buffer += 0x20;
            }
            if ((u8)func_80090AB0(out + count * 2, -count * 2 + 0x100) != out[1]) {
                return 3;
            }
            for (index = 0, buffer = out; index != 8; index++) {
                func_800928F0(object->unk04, object->unk08, object->unk54 + base + index, buffer, 0);
                buffer += 0x20;
            }
        }
    }

    D_800A7ED4 = key;
    func_80092250(out, D_8014C3D0, 0x100);
    D_800A7ED0 = object->unk08;
    return 0;
}
