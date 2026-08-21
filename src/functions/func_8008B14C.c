/* Implements specification specs/func_8008B14C.md (recovered behavior). */
#include "podcruise/types.h"

extern s32 func_80093A60(void);
extern void func_80093980(s32 arg0);

void func_8008B14C(s32 arg0) {
    (void)arg0;
    while (func_80093A60() != 0) {
    }
    func_80093980(0x125);
}
