/* Independently written from the specification for func_80031324. */

#include "podcruise/types.h"

typedef struct Settings {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u8 pad20[0xC];
    /* 0x2C */ s32 unk2C;
} Settings;

extern Settings D_800D6960;
extern u8 D_800AA000[];

extern void func_80011DF0(void);
extern void func_8003043C(void);
extern void func_800086F8(void);
extern void func_80030FF8(s16 arg0, s16 arg1);
extern void func_80031134(void);
extern void func_8000A920(s32 arg0, s32 arg1);
extern void func_80008540(u8 *arg0);
extern void func_800811C0(f64 arg0);
extern void func_800812E8(void);

void func_80031324(arg0, arg1)
    s16 arg0;
    s16 arg1;
{
    func_80011DF0();
    func_8003043C();
    func_800086F8();

    if ((D_800D6960.unk1C & 0x200) == 0) {
        D_800D6960.unk2C = arg0;
    }

    func_80030FF8(arg0, arg1);
    func_80031134();
    func_8000A920(-201, 0);
    func_80008540(D_800AA000);
    func_800811C0(-1.0);
    func_800812E8();
}
