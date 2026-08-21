/* Independently written from scratchpad spec specs/func_80094E44.md. */

#include "podcruise/types.h"

/* Twelve-byte serial-bus command record: three header bytes, one address byte
   and an eight-byte payload window that this request leaves for the reply. */
typedef struct {
    u8 unk00;
    u8 unk01;
    u8 unk02;
    u8 unk03;
    u8 unk04[8];
} SerialCommand;

/* Sixty-four byte serial command block: fifteen command words plus a status
   word that starts the transfer once it is written. */
typedef struct {
    u32 unk00[15];
    u32 unk3C;
} SerialBlock;

extern SerialBlock D_8014C530;

void func_80094E44(u8 arg0) {
    /* The original frame reserves four bytes above the command record; the
       recovered code never reads them. */
    u8 unk14[4];
    SerialCommand command;
    u8 *cursor;
    s32 index;

    (void)unk14;

    cursor = (u8 *)&D_8014C530;
    D_8014C530.unk3C = 1;

    command.unk00 = 2;
    command.unk01 = 8;
    command.unk02 = 4;
    command.unk03 = arg0;

    for (index = 0; index < 4; index++) {
        *cursor++ = 0;
    }

    *(SerialCommand *)cursor = command;
    cursor += sizeof(SerialCommand);
    *cursor = 0xFE;
}
