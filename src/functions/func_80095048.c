/* Independently written from scratchpad spec specs/func_80095048.md. */

#include "podcruise/types.h"

struct PifRam80095048 {
    u32 ramarray[15];
    u32 status;
};

struct EepromPacket80095048 {
    u8 txsize;
    u8 rxsize;
    u8 command;
    u8 address;
    u8 data[8];
};

extern struct PifRam80095048 D_8014C530;

void func_80095048(u8 address, u8 *buffer) {
    u8 *ptr = (u8 *)D_8014C530.ramarray;
    struct EepromPacket80095048 packet;
    s32 index;

    D_8014C530.status = 1;

    packet.txsize = 10;
    packet.rxsize = 1;
    packet.command = 5;
    packet.address = address;

    for (index = 0; index < 8; index++) {
        packet.data[index] = *buffer++;
    }

    for (index = 0; index < 4; index++) {
        *ptr++ = 0;
    }

    *(struct EepromPacket80095048 *)ptr = packet;
    ptr += sizeof(struct EepromPacket80095048);
    ptr[0] = 0xFE;
}
