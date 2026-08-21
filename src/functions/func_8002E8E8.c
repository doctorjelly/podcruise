/* Implements specification specs/func_8002E8E8.md (channel availability scan). */
#include "podcruise/types.h"

extern u8 D_800A26D0;
extern u8 D_800A26D4;
extern s32 D_800D7490;
extern s32 D_800D7498[];
extern u8 D_800D74B3[];

extern void func_8002E770(void);

void func_8002E8E8(void) {
    s32 selected;
    s32 none;
    s32 flags;
    s32 i;

    func_8002E770();
    flags = D_800A26D0;
    none = -1;
    selected = none;

    for (i = 0; i < 4; i++) {
        if ((flags & (1 << i)) && !(D_800D74B3[i * 4] & 8)) {
            if (selected == none) {
                selected = i;
            }
            D_800D7498[i] = 1;
        } else {
            D_800D7498[i] = 0;
        }
    }

    D_800D7490 = selected;
    if (none == selected) {
        D_800A26D4 = 0;
    }
}
