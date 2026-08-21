/* Recovered from specification specs/func_800517D8.md */
#include "podcruise/types.h"

typedef struct Ent800517D8 {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0xAC];
    f32 unkBC;
} Ent800517D8;

extern s32 D_8011A508[];
extern s32 D_8011A768[];
extern Ent800517D8 *D_8011A9C8[];

extern Ent800517D8 *func_8003F800(u32, s32);
extern void func_80046670(s32, s32, s32, s32);
extern void func_80062EC8(Ent800517D8 *, s32, s32, s32);

void func_800517D8(s32 arg0, s32 arg1, s32 arg2, f32 arg3) {
    Ent800517D8 *entry;

    entry = func_8003F800(0x456C6D6F, arg1);
    if (entry != 0) {
        D_8011A9C8[arg1] = entry;
        func_80046670(arg0, -1, arg1, 1);
        func_80062EC8(entry, D_8011A508[arg1], D_8011A768[arg1], arg2);
        entry->unkC = arg1;
        entry->unkBC = arg3;
        if (arg2 == 1) {
            entry->unkBC = 90.0f;
        }
    }
}
