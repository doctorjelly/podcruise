/* Independently written from scratchpad spec specs/func_800910D4.md. */

#include "podcruise/types.h"

typedef struct Descriptor {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u8 unk1A;
    /* 0x1B */ u8 unk1B;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u16 unk1E;
} Descriptor;

typedef struct Device {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ Descriptor unk0C;
    /* 0x2C */ u8 unk2C[0x20];
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
    /* 0x54 */ s32 unk54;
    /* 0x58 */ s32 unk58;
    /* 0x5C */ s32 unk5C;
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 unk64;
    /* 0x65 */ u8 unk65;
} Device;

extern s32 func_80090B24(Descriptor *descriptor, u16 *first, u16 *second);
extern s32 func_80090C20(Device *device, Descriptor *source, Descriptor *target);
extern s32 func_80090F70(Device *device, Descriptor *descriptor);
extern s32 func_80091FD0(Device *device, s32 mode);
extern s32 func_80092050(s32 handleA, s32 handleB, u16 selector, void *context);
extern void func_80092250(void *source, void *target, s32 length);

s32 func_800910D4(Device *device) {
    u16 first;
    u16 second;
    Descriptor primary;
    Descriptor *chosen;
    Descriptor secondary;
    s32 result;

    if (device->unk65 != 0) {
        result = func_80091FD0(device, 0);
        if (result != 0) {
            return result;
        }
    }

    result = func_80092050(device->unk04, device->unk08, 1, &primary);
    if (result != 0) {
        return result;
    }

    func_80090B24(&primary, &first, &second);
    chosen = &primary;

    if (primary.unk1C != first || primary.unk1E != second) {
        result = func_80090F70(device, &primary);
        if (result == 10) {
            result = func_80090C20(device, &primary, &secondary);
            if (result != 0) {
                return result;
            }
            chosen = &secondary;
        } else if (result != 0) {
            return result;
        }
    }

    if ((chosen->unk18 & 1) == 0) {
        result = func_80090C20(device, chosen, &secondary);
        if (result != 0) {
            return result;
        }
        if ((secondary.unk18 & 1) == 0) {
            return 11;
        }
        chosen = &secondary;
    }

    func_80092250(chosen, &device->unk0C, 0x20);
    device->unk4C = chosen->unk1B;
    device->unk64 = chosen->unk1A;
    device->unk60 = device->unk64 * 2 + 3;
    device->unk58 = device->unk64 * 8 + 8;
    device->unk50 = 0x10;
    device->unk54 = 8;
    device->unk5C = device->unk58 + device->unk64 * 8;

    result = func_80092050(device->unk04, device->unk08, 7, &device->unk2C);
    if (result != 0) {
        return result;
    }
    return 0;
}
