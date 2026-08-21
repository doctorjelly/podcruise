/* Specification: $S/specs/func_8005F9CC.md */
#include "podcruise/types.h"

struct Func8005F9CCObject {
    u8 unk00[0x2C];
    s32 unk2C;
    s32 unk30;
    u8 unk34[0x1B4 - 0x34];
    s32 unk1B4;
};

extern s32 D_8011B1E4;
extern s32 func_8002FAFC(void);
extern s32 func_80030274(s32);
extern void func_800801B8(s32, s32);
extern void func_8005F948(struct Func8005F9CCObject *);

void func_8005F9CC(struct Func8005F9CCObject *arg0) {
    s32 start;
    s32 end;

    start = func_8002FAFC();
    arg0->unk2C = func_80030274(arg0->unk1B4);
    end = func_8002FAFC();
    D_8011B1E4 = D_8011B1E4 + end - start;
    func_800801B8(arg0->unk2C, arg0->unk30);
    func_8005F948(arg0);
}
