/* Implements the specification in specs/func_80063AA0.md (tagged lookup then dispatch). */
#include "podcruise/types.h"

extern void *func_8003F800(u32 arg0, void *arg1);
extern void func_80060DE4(void *arg0, void *arg1);

void func_80063AA0(void *arg0, void *arg1) {
    void *found;

    found = func_8003F800(0x456C6D6F, arg0);
    if (found != 0) {
        func_80060DE4(found, arg1);
    }
}
