/* Independently written from specs/functions/runtime_wrappers.md. */

#include "podcruise/runtime_wrappers.h"

extern void func_80007A44(void);

void func_800086F8(void) {
    func_80007A44();
}
