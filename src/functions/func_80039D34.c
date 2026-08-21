/* Specification: specs/func_80039D34.md (func_80039D34) */
#include "podcruise/types.h"

typedef struct {
    u32 words[20];
} Block80;

extern s32 D_80000300;
extern Block80 D_800A6A60;
extern Block80 D_800A6EC0;
extern Block80 D_800A7320;
extern Block80 D_80114488;
extern Block80 D_801144D8;

extern void func_80039B70(void);
extern void func_80039CD8(s32);
extern void func_8008A2F0(void *);
extern void func_8008A3B0(s32);

void func_80039D34(void) {
    Block80 *dst = &D_80114488;

    func_80039CD8(1);
    func_80039B70();
    switch (D_80000300) {
    case 0:
        *dst = D_800A6EC0;
        break;
    case 2:
        *dst = D_800A7320;
        break;
    case 1:
        *dst = D_800A6A60;
        break;
    }
    D_801144D8 = *dst;
    func_8008A2F0(dst);
    func_8008A3B0(1);
}
