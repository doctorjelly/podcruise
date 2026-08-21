/* Independently written from scratchpad spec specs/func_8008A150.md. */

#include "podcruise/types.h"

typedef union LinkA150 {
    u16 half;
    struct {
        u8 hi;
        u8 lo;
    } b;
} LinkA150;

typedef struct DevA150 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u8 pad04[0x60 - 0x04];
    /* 0x60 */ s32 unk60;
    /* 0x64 */ u8 unk64;
} DevA150;

extern s32 func_80091280(DevA150 *device);
extern s32 func_80091354(DevA150 *device, LinkA150 *table, u8 mode, u8 key);

s32 func_8008A150(DevA150 *device, s32 *out) {
    s32 status;
    s32 count;
    LinkA150 table[128];
    u8 page;
    s32 start;
    s32 index;

    count = 0;
    if ((device->unk00 & 1) == 0) {
        return 5;
    }
    status = func_80091280(device);
    if (status != 0) {
        return status;
    }
    for (page = 0; page < device->unk64; page++) {
        status = func_80091354(device, table, 0, page);
        if (status != 0) {
            return status;
        }
        if (page > 0) {
            start = 1;
        } else {
            start = device->unk60;
        }
        for (index = start; index < 128; index++) {
            if (table[index].half == 3) {
                count++;
            }
        }
    }
    *out = count << 8;
    return 0;
}
