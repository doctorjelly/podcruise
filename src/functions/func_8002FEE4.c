/* Specification: scratchpad specs/func_8002FEE4.md */
#include "podcruise/types.h"

extern u32 func_8002FC58(void);
extern void *func_8002FAFC(void);
extern void func_8002FAC4(void *ptr);

void *func_8002FEE4(u32 arg0) {
    void *ptr;

    if (arg0 >= func_8002FC58()) {
        return (void *)0;
    }
    ptr = func_8002FAFC();
    func_8002FAC4((void *)((u8 *)ptr + arg0));
    return ptr;
}
