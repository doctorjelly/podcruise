/* Independently written from scratchpad spec specs/func_8003960C.md. */

#include "podcruise/types.h"

typedef struct {
    s32 unk00[252];
} Block8003960C;

extern Block8003960C D_80113680;
extern Block8003960C D_80113A70;

void func_8003960C(void) {
    D_80113A70 = D_80113680;
}
