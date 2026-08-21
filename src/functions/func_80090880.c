/* Recovered from specification $S/specs/func_80090880.md */
#include "podcruise/types.h"

extern u8 D_800A7ED4;
extern u8 D_8014D720[];

extern void func_80087E80(void *, s32 *, s32);
extern s32 func_800907D0(s32, u8 *);
extern void func_8009094C(void *);
extern void func_80090A0C(void *, u8 *);

s32 func_80090880(void *arg0, void *arg1) {
    s32 fallback;
    s32 scratch;
    u8 status[4];

    D_800A7ED4 = 0xFA;
    func_8009094C(arg1);
    func_800907D0(1, D_8014D720);
    func_80087E80(arg0, &scratch, 1);
    fallback = func_800907D0(0, D_8014D720);
    func_80087E80(arg0, &scratch, 1);
    func_80090A0C(arg1, status);
    if ((status[2] & 1) && (status[2] & 2)) {
        return 2;
    }
    if (status[3] != 0 || (status[2] & 1) == 0) {
        return 1;
    }
    if (status[2] & 4) {
        return 4;
    }
    return fallback;
}
