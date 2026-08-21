/* Specification: specs/func_80087094.md (entry corrected to 0x80087080) */
#include "podcruise/types.h"

typedef struct Rec80120DF0 {
    u8 data[368];
} Rec80120DF0;

extern Rec80120DF0 D_80120DF0[];
extern Rec80120DF0 *D_800A68B4;

extern void func_80086930(s32);
extern void func_80086EB4(s32);

void func_80087080(s32 index) {
    D_800A68B4 = &D_80120DF0[index];
    func_80086930(index);
    func_80086EB4(index);
}
