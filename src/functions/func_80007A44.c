/* Independently written from scratchpad spec specs/func_80007A44.md. */

#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Entry800D2038;

extern s32 D_8009A2B8;
extern Entry800D2038 D_800D2038[8];

void func_80007A44(void) {
    s32 i;

    if (D_8009A2B8 != 0) {
        for (i = 0; i < 8; i++) {
            D_800D2038[i].unk18 = 0;
        }
    }
}
