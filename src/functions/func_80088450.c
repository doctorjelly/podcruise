/* Implements the specification in specs/func_80088450.md (paired setup forwarder). */
#include "podcruise/types.h"

extern void func_80088020(void *arg0);
extern void func_80088050(void *arg0, void *arg1);

void func_80088450(void *arg0, void *arg1) {
    func_80088020(arg1);
    func_80088050(arg1, (void *)((u8 *)arg0 + 0x14));
}
