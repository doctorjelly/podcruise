/* Implements specs/func_8008B1B0.md (serial-bus block write and status check). */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00[15];
    /* 0x3C */ u32 unk3C;
} SerialBlock;

typedef struct {
    /* 0x00 */ u8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06[32];
    /* 0x26 */ u8 unk26;
} SerialFrame;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ s32 unk08;
} SerialPort;

extern u8 D_80149CB0;
extern SerialBlock D_80149DC0[];

extern void func_800905F0(void);
extern void func_80090634(void);
extern void func_800907D0(s32 direction, SerialBlock *block);
extern void func_80087E80(void *queue, void *message, s32 mode);

s32 func_8008B1B0(SerialPort *port, s32 value) {
    s32 i;
    s32 result;
    u8 *frame;

    result = 0;
    frame = (u8 *)&D_80149DC0[port->unk08];
    if (!(port->unk00 & 8)) {
        return 5;
    }
    func_800905F0();
    D_80149DC0[port->unk08].unk3C = 1;
    frame += port->unk08;
    for (i = 0; i < 32; i++) {
        ((SerialFrame *)frame)->unk06[i] = value;
    }
    D_80149CB0 = 0xFE;
    func_800907D0(1, &D_80149DC0[port->unk08]);
    func_80087E80(port->unk04, 0, 1);
    func_800907D0(0, &D_80149DC0[port->unk08]);
    func_80087E80(port->unk04, 0, 1);
    result = ((SerialFrame *)frame)->unk02 & 0xC0;
    if (result == 0) {
        if (value == 0) {
            if (((SerialFrame *)frame)->unk26 != 0) {
                result = 4;
            }
        } else {
            if (((SerialFrame *)frame)->unk26 != 0xEB) {
                result = 4;
            }
        }
    }
    func_80090634();
    return result;
}
