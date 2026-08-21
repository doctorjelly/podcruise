/* Implements specification $S/specs/func_80094ED0.md */
#include "podcruise/types.h"

typedef struct Data12 {
    u8 b[12];
} Data12;

typedef struct Buf {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Buf;

struct PifRam80094ED0 {
    u32 ramarray[15];
    u32 status;
};

extern struct PifRam80094ED0 D_8014C530;
extern u8 D_8014C534[12];
extern u8 D_80149CB0;

extern void func_800905F0(void);
extern void func_80090634(void);
extern s32 func_800950F4(void *, u16 *);
extern void func_80095048(u8 address, u8 *buffer);
extern void func_800907D0(s32 direction, void *block);
extern void func_80087E80(void *queue, void *message, s32 mode);

s32 func_80094ED0(arg0, arg1, arg2)
void *arg0;
u8 arg1;
u8 *arg2;
{
    s32 result;
    u16 type;
    u8 *ptr;
    Data12 tmp;
    Buf buf;

    func_800905F0();
    result = func_800950F4(arg0, (u16 *)&buf);
    if (result == 0) {
        type = buf.unk0 & 0xC000;
        switch (type) {
            default:
                result = 8;
                break;
            case 0x8000:
                if (arg1 >= 0x40) {
                    result = -1;
                }
                break;
            case 0xC000:
                if ((arg1 + 0) >= 0x100) {
                    result = -1;
                }
                break;
        }
    }
    if (result != 0) {
        func_80090634();
        return result;
    }
    while ((buf.unk2 & 0x80) != 0) {
        func_800950F4(arg0, (u16 *)&buf);
    }
    func_80095048(arg1, arg2);
    func_800907D0(1, &D_8014C530);
    func_80087E80(arg0, 0, 1);
    func_800907D0(0, &D_8014C530);
    D_80149CB0 = 5;
    func_80087E80(arg0, 0, 1);
    ptr = D_8014C534;
    tmp = *(Data12 *)ptr;
    result = (tmp.b[1] & 0xC0) >> 4;
    func_80090634();
    return result;
}
