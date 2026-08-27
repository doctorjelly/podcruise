/* Specification: $S/specs/func_800393DC.md (worker-authored) */
#include "podcruise/types.h"

extern void func_800392A4(void);
extern void func_800392E8(void);
extern s32 func_8008C190();
extern u8 D_800D9C28[];

s32 func_800393DC(void *arg0, u32 arg1, s32 arg2) {
    s32 result;
    s32 count;

    func_800392A4();
    count = arg2;
    if (count != (count / 8) * 8) {
        while (1) {
        }
    }
    if ((arg1 >> 3) >= 0x100U) {
        while (1) {
        }
    }
    if ((arg1 >> 3) + (u32)(count / 8) >= 0x101U) {
        while (1) {
        }
    }
    result = func_8008C190(D_800D9C28, (arg1 >> 3) & 0xFF, arg0);
    func_800392E8();
    return result;
}
