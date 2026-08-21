/* Specification: $S/specs/func_800880B8.md (boundary corrected to 0x800880AC) */
#include "podcruise/types.h"

extern void *D_800A6990;
extern void func_800887D0(void *, void *);

void func_800880AC(void *arg0, void *arg1) {
    if (D_800A6990 == 0) {
        D_800A6990 = arg0;
        func_800887D0(arg0, arg1);
    }
}
