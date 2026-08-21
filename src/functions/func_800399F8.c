/* Specification: $S/specs/func_800399F8.md */
#include "podcruise/types.h"

extern u8 D_80113E64;
extern u8 D_80113E65;
extern void func_800398B8(void);
extern void func_80039984(s32, s32);

void func_800399F0(void) {
    if (D_80113E64 == 1) {
        func_80039984(D_80113E65, 0);
    }
    func_800398B8();
}
