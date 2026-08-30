/* Independently written from specs/functions/recovered/func_800945C0.md. */

#include "podcruise/types.h"

typedef struct DeviceChannel800945C0 {
    /* 0x00 */ struct DeviceChannel800945C0 *next;
    /* 0x04 */ u8 kind;
    /* 0x05 */ u8 latency;
    /* 0x06 */ u8 pageSize;
    /* 0x07 */ u8 releaseDuration;
    /* 0x08 */ u8 pulseWidth;
    /* 0x09 */ u8 channel;
    /* 0x0A */ u8 unused[2];
    /* 0x0C */ u32 baseAddress;
} DeviceChannel800945C0;

extern DeviceChannel800945C0 *D_800A7BA0[];

extern u32 func_80088360(u32 address);

s32 func_800945C0(DeviceChannel800945C0 *handle, s32 direction,
                  u32 deviceOffset, u32 dramAddress, u32 size) {
    u32 status;
    s32 channel;
    DeviceChannel800945C0 *current;

    status = *(volatile u32 *)(unsigned long)0xA4600010U;
    while (status & 3) {
        status = *(volatile u32 *)(unsigned long)0xA4600010U;
    }

    channel = handle->channel;
    if (D_800A7BA0[channel] != handle) {
        current = D_800A7BA0[channel];
        if (channel == 0) {
            if (current->latency != handle->latency) {
                *(volatile u32 *)(unsigned long)0xA4600014U = handle->latency;
            }
            if (current->pageSize != handle->pageSize) {
                *(volatile u32 *)(unsigned long)0xA460001CU = handle->pageSize;
            }
            if (current->releaseDuration != handle->releaseDuration) {
                *(volatile u32 *)(unsigned long)0xA4600020U =
                    handle->releaseDuration;
            }
            if (current->pulseWidth != handle->pulseWidth) {
                *(volatile u32 *)(unsigned long)0xA4600018U = handle->pulseWidth;
            }
        } else {
            if (current->latency != handle->latency) {
                *(volatile u32 *)(unsigned long)0xA4600024U = handle->latency;
            }
            if (current->pageSize != handle->pageSize) {
                *(volatile u32 *)(unsigned long)0xA460002CU = handle->pageSize;
            }
            if (current->releaseDuration != handle->releaseDuration) {
                *(volatile u32 *)(unsigned long)0xA4600030U =
                    handle->releaseDuration;
            }
            if (current->pulseWidth != handle->pulseWidth) {
                *(volatile u32 *)(unsigned long)0xA4600028U = handle->pulseWidth;
            }
        }
        D_800A7BA0[channel] = handle;
    }

    *(volatile u32 *)(unsigned long)0xA4600000U = func_80088360(dramAddress);
    *(volatile u32 *)(unsigned long)0xA4600004U =
        (handle->baseAddress | deviceOffset) & 0x1FFFFFFFU;
    switch (direction) {
        case 0:
            *(volatile u32 *)(unsigned long)0xA460000CU = size - 1;
            break;
        case 1:
            *(volatile u32 *)(unsigned long)0xA4600008U = size - 1;
            break;
        default:
            return -1;
    }
    return 0;
}
