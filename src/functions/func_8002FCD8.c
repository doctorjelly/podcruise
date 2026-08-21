/* Implements the specification in specs/func_8002FCD8.md (worker-authored). */
#include "podcruise/types.h"

extern u8 D_800D9BF8[];
extern u8 D_800D9C10[];
extern u8 D_800D9C28[];
extern u8 D_800D9C70[];
extern u8 D_800D9C88[];
extern u8 D_800D9D50[];
extern u8 D_800D9D54[];
extern u8 D_800D9D58[];

extern void func_8000C540(void *a, void *b);
extern void func_8003A440(void);
extern void func_80087E80(void *a, s32 b, s32 c);
extern void func_800880E0(void *a, void *b, s32 count);
extern void func_8008AE30(s32 index, void *a, s32 b);
extern void func_8008C090(void *a, s32 b, s32 c);

void func_8002FCD8(void) {
    func_800880E0(D_800D9BF8, D_800D9C88, 50);
    func_80087E80(D_800D9BF8, 0, 0);
    func_800880E0(D_800D9C10, D_800D9D50, 1);
    func_8008C090(D_800D9C10, 3, 1);
    func_800880E0(D_800D9C70, D_800D9D54, 1);
    func_8008AE30(14, D_800D9C70, 1);
    func_800880E0(D_800D9C28, D_800D9D58, 16);
    func_8008AE30(5, D_800D9C28, 1);
    func_8000C540(D_800D9C28, D_800D9C10);
    func_8003A440();
}
