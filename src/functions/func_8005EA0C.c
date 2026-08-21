/* Implements the specification in specs/func_8005EA0C.md (worker scratchpad) */
#include "podcruise/types.h"

extern void *func_800305E8(s32);
extern int func_80030964(void *);
extern u32 **D_8011B1B0;
extern u32 D_8011B1B4;

void func_8005EA0C(void) {
    u32 **inner;
    u32 ***object;

    object = func_800305E8(0x92);
    func_80030964(object);
    D_8011B1B0 = object[0];

    object = func_800305E8(0x31);
    func_80030964(object);
    inner = object[0];
    D_8011B1B4 = inner[6][0];
}
