/* Specification: $S/specs/func_80030298.md */
#include "podcruise/types.h"

extern s32 func_8002FAFC(void);
extern void func_8002FAC4(s32);
extern s32 func_8003FB78(s32, s32, s32);
extern void func_8003F300(s32);
extern void func_8003FA24(s32, s32 *);

void func_80030298(s32 arg0, s32 arg1) {
    s32 count;
    s32 start;
    s32 tag;

    start = func_8002FAFC();
    count = func_8003FB78(arg0, arg1, start);
    func_8003F300(arg0);
    func_8002FAC4(count + start);
    tag = 0x4C6F6164;
    func_8003FA24(arg0, &tag);
}
