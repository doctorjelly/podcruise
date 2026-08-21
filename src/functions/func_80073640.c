/* Specification: $S/specs/func_80073640.md */
#include "podcruise/types.h"

extern void func_80006E60(u32, u32);
extern void func_80006E74(u32, f32);

void func_80073640(u32 *list) {
    while (*list != 0) {
        func_80006E60(*list, 0x10000000);
        func_80006E74(*list, 0.0f);
        list++;
    }
}
