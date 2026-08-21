/* Independently written from specs/functions/audio_dac_rate.md. */

#include "podcruise/types.h"

#define AUDIO_INTERFACE_REGISTER(address) (*(volatile u32 *) (address))

extern s32 D_800A7B48;

s32 func_80088150(u32 arg0) {
    register u32 dacRate;
    register u8 bitRate;
    register f32 fdacRate;

    fdacRate = (f32) D_800A7B48 / (f32) arg0 + 0.5f;
    dacRate = (u32) fdacRate;
    if (dacRate < 132) {
        return -1;
    }

    bitRate = dacRate / 66;
    if (bitRate > 16) {
        bitRate = 16;
    }

    AUDIO_INTERFACE_REGISTER(0xA4500010) = dacRate - 1;
    AUDIO_INTERFACE_REGISTER(0xA4500014) = bitRate - 1;
    AUDIO_INTERFACE_REGISTER(0xA4500008) = 1;

    return D_800A7B48 / (s32) dacRate;
}
