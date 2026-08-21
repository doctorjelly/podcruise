/* Independently written from scratchpad spec specs/func_8000A330.md. */

#include "podcruise/types.h"

typedef struct Entity8000A330 Entity8000A330;

extern s32 D_8009B774;
extern Entity8000A330 *D_800D3A90[];
extern void func_80009FA0(Entity8000A330 *entity, s32 mask, f32 scaleX, f32 scaleY);

void func_8000A330(s32 arg0) {
    s32 index;
    s32 mask;

    if (arg0 == 2) {
        mask = 1;
    } else if (arg0 == 1) {
        mask = 2;
    } else if (arg0 == 3) {
        mask = 0x800;
    }

    for (index = 0; index < D_8009B774; index++) {
        func_80009FA0(D_800D3A90[index], mask, 1.0f, 1.0f);
    }

    if (arg0 == 3) {
        D_8009B774 = 0;
    }
}
