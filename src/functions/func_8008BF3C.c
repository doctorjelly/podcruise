/* Independently written from scratchpad spec specs/func_8008BF3C.md. */

#include "podcruise/types.h"

typedef struct DeviceChannel {
    /* 0x00 */ struct DeviceChannel *next;
    /* 0x04 */ u8 kind;
    /* 0x05 */ u8 latency;
    /* 0x06 */ u8 pageSize;
    /* 0x07 */ u8 releaseDuration;
    /* 0x08 */ u8 pulseWidth;
    /* 0x09 */ u8 channel;
} DeviceChannel;

extern DeviceChannel D_8014B0F0;
extern DeviceChannel D_8014B168;

void func_8008BF3C(void) {
    D_8014B0F0.latency = (u8)*(volatile u32 *)(unsigned long)0xA4600014U;
    D_8014B0F0.pulseWidth = (u8)*(volatile u32 *)(unsigned long)0xA4600018U;
    D_8014B0F0.pageSize = (u8)*(volatile u32 *)(unsigned long)0xA460001CU;
    D_8014B0F0.releaseDuration = (u8)*(volatile u32 *)(unsigned long)0xA4600020U;
    D_8014B0F0.channel = 0;

    D_8014B168.latency = (u8)*(volatile u32 *)(unsigned long)0xA4600024U;
    D_8014B168.pulseWidth = (u8)*(volatile u32 *)(unsigned long)0xA4600028U;
    D_8014B168.pageSize = (u8)*(volatile u32 *)(unsigned long)0xA460002CU;
    D_8014B168.releaseDuration = (u8)*(volatile u32 *)(unsigned long)0xA4600030U;
    D_8014B168.channel = 1;
}
