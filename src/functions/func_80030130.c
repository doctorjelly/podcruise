/* Independently written from the specification for func_80030130. */
#include "podcruise/types.h"

extern void *func_8002FF38(s32 index);

void func_80030130(s32 unused, s32 index) {
    (void)unused;
    func_8002FF38(index);
}
