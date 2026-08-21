/* Specification: scratchpad/specs/func_8003398C.md */
#include "podcruise/types.h"

extern void func_80006DE8(void *, f32, f32);
extern void func_80006E50(void *, u32);
extern void func_80006E60(void *, u32);
extern void func_80006E74(void *, f32);
extern void func_80006EC0(void *, f32, f32);
extern void func_80006F28(void *, f32);

void func_8003398C(void **list, f32 valueA, f32 lower, f32 upper, s32 mode, f32 valueB, f32 valueC) {
    s32 i;

    if (list != 0) {
        for (i = 0; list[i] != 0; i++) {
            func_80006DE8(list[i], lower, upper);
            if (mode != 0) {
                func_80006E50(list[i], 0x2000010);
                func_80006E60(list[i], 0x4000000);
                if (0.0f < valueC) {
                    func_80006E50(list[i], 0x40);
                    func_80006F28(list[i], valueC);
                } else {
                    func_80006E60(list[i], 0x40);
                }
            } else {
                func_80006E50(list[i], 0x4000000);
                func_80006E60(list[i], 0x2000000);
            }
            if (0.0f <= valueA) {
                if (0.0f < valueB) {
                    func_80006EC0(list[i], valueA, valueB);
                } else {
                    func_80006E74(list[i], valueA);
                }
            }
        }
    }
}
