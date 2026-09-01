/* Specification: $S/specs/func_8002F4D0.md */
#include "podcruise/types.h"

extern u32 D_800D6960[];
extern u8 D_800D7750[];
extern u8 D_800D7A00[];
extern void func_800183C0(void);
extern void func_80088150(s32);
extern void func_8008B580(void);
extern void func_8008B810(void *, s32, void *, void *, void *, s32);
extern void func_8008B960(void *);
extern void func_8002F550(void *);

void func_8002F4D0(void) {
    func_8008B580();
    func_80088150(0x5622);
    func_800183C0();
    D_800D6960[7] |= 0x40;
    func_8008B810(D_800D7750, 1, func_8002F550, 0, D_800D7A00, 10);
    func_8008B960(D_800D7750);
}
