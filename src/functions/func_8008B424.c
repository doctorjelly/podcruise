/* Recovered from specs/func_8008B424.md (worker specification). */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 status;
    /* 0x04 */ void *queue;
    /* 0x08 */ s32 channel;
    /* 0x0C */ u8 pad0C[0x65 - 0x0C];
    /* 0x65 */ u8 activebank;
    /* 0x66 */ u8 pad66[2];
} Pack;

extern s32 func_80091FD0(Pack *pack, s32 bank);
extern s32 func_80092050(void *queue, s32 channel, s32 address, u8 *buffer);
extern s32 func_8008B318(s32 channel, u8 *entry);
extern u8 D_80149DC0[1][64];

#define ERRCK(fn) ret = fn; if (ret == 2) ret = 4; if (ret != 0) return ret;

s32 func_8008B424(void *queue, Pack *pack, s32 channel) {
    s32 ret;
    u8 buffer[32];

    pack->queue = queue;
    pack->channel = channel;
    pack->activebank = 0xFF;
    pack->status = 0;

    ret = func_80091FD0(pack, 0xFE);
    if (ret == 2) {
        ret = func_80091FD0(pack, 0x80);
    }
    if (ret != 0) {
        return ret;
    }

    ERRCK(func_80092050(queue, channel, 0x400, buffer))
    if (buffer[31] == 0xFE) {
        return 11;
    }

    ret = func_80091FD0(pack, 0x80);
    if (ret == 2) {
        ret = 4;
    }
    if (ret != 0) {
        return ret;
    }

    ERRCK(func_80092050(queue, channel, 0x400, buffer))
    if (buffer[31] != 0x80) {
        return 11;
    }

    if (!(pack->status & 8)) {
        func_8008B318(channel, D_80149DC0[channel]);
    }
    pack->status = 8;
    return 0;
}
