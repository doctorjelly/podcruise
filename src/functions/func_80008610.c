/* Independently written from specs/functions/runtime_wrappers.md. */

#include "podcruise/runtime_wrappers.h"

extern void func_80007218(void);

void func_80008610(void) {
    func_80007218();
}
