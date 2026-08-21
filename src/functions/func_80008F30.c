/* Independently written from the specification for func_80008F30 (boundary corrected to func_80008F28). */
#include "podcruise/types.h"

extern s32 D_8009A2B8;
extern void func_8002E124(void);

void func_80008F28(void) {
    if (D_8009A2B8 != 0) {
        func_8002E124();
    }
}
