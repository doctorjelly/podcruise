/* Implements specification $S/specs/func_80094ED0.md */
#include "podcruise/types.h"

typedef struct ContStatus {
    u16 type;
    u8 status;
    u8 errnum;
} ContStatus;

typedef struct EepFormat {
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u8 addr;
    u8 data[8];
} EepFormat;

struct PifRam80094ED0 {
    u32 ramarray[15];
    u32 status;
};

extern struct PifRam80094ED0 D_8014C530;
extern u8 D_8014C534[12];
extern u8 D_80149CB0;

extern void func_800905F0(void);
extern void func_80090634(void);
extern s32 func_800950F4(void *, ContStatus *);
extern void func_80095048(u8 address, u8 *buffer);
extern void func_800907D0(s32 direction, void *block);
extern void func_80087E80(void *queue, void *message, s32 mode);

s32 func_80094ED0(mq, address, buffer)
void *mq;
u8 address;
u8 *buffer;
{
    s32 ret;
    int x;
    u8 *ptr = D_8014C534;
    EepFormat eepromformat;
    ContStatus sdata;

    func_800905F0();
    ret = func_800950F4(mq, &sdata);

    if (ret == 0) {
        switch (sdata.type & 0xC000) {
            case 0x8000:
                if (address >= 0x40) {
                    ret = -1;
                }
                break;
            case 0xC000:
                if ((address + 0) >= 0x100) {
                    ret = -1;
                }
                break;
            default:
                ret = 8;
        }
    }
    if (ret != 0) {
        func_80090634();
        return ret;
    }
    while (sdata.status & 0x80) {
        func_800950F4(mq, &sdata);
    }
    func_80095048(address, buffer);
    func_800907D0(1, &D_8014C530);
    func_80087E80(mq, 0, 1);
    func_800907D0(0, &D_8014C530);
    D_80149CB0 = 5;
    func_80087E80(mq, 0, 1);
    eepromformat = *(EepFormat *)ptr;
    ret = (eepromformat.rxsize & 0xC0) >> 4;
    func_80090634();
    (void)x;
    return ret;
}
