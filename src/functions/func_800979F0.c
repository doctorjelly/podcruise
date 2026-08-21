/* Independently written from scratchpad spec specs/func_800979F0.md. */

#include "podcruise/types.h"

typedef struct DeviceChannel {
    /* 0x00 */ struct DeviceChannel *next;
    /* 0x04 */ u8 kind;
    /* 0x05 */ u8 latency;
    /* 0x06 */ u8 pageSize;
    /* 0x07 */ u8 releaseDuration;
    /* 0x08 */ u8 pulseWidth;
    /* 0x09 */ u8 channel;
    /* 0x0A */ u8 unused[2];
    /* 0x0C */ u32 baseAddress;
} DeviceChannel;

extern DeviceChannel *D_800A7BA0[];

s32 func_800979F0(DeviceChannel *handle, u32 offset, u32 value) {
    register u32 status;
    register s32 domain;
    DeviceChannel *current;

    status = *(volatile u32 *)(unsigned long)0xA4600010U;
    while (status & 3) {
        status = *(volatile u32 *)(unsigned long)0xA4600010U;
    }

    domain = handle->channel;
    if (D_800A7BA0[domain] != handle) {
        current = D_800A7BA0[domain];
        if (domain == 0) {
            if (current->latency != handle->latency) {
                *(volatile u32 *)(unsigned long)0xA4600014U = handle->latency;
            }
            if (current->pageSize != handle->pageSize) {
                *(volatile u32 *)(unsigned long)0xA460001CU = handle->pageSize;
            }
            if (current->releaseDuration != handle->releaseDuration) {
                *(volatile u32 *)(unsigned long)0xA4600020U = handle->releaseDuration;
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
                *(volatile u32 *)(unsigned long)0xA4600030U = handle->releaseDuration;
            }
            if (current->pulseWidth != handle->pulseWidth) {
                *(volatile u32 *)(unsigned long)0xA4600028U = handle->pulseWidth;
            }
        }
        D_800A7BA0[domain] = handle;
    }

    *(volatile u32 *)(unsigned long)((handle->baseAddress | offset) | 0xA0000000U) = value;
    return 0;
}
