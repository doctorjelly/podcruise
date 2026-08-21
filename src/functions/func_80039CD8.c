/* Independently written from scratchpad spec specs/func_80039CD8.md. */

#include "podcruise/types.h"

typedef struct {
    s32 unk00[7];
    s32 unk1C;
    s32 unk20[3];
    s32 unk2C;
    s32 unk30[4];
    s32 unk40;
} Entry80039CD8;

extern Entry80039CD8 D_80114488;
extern Entry80039CD8 D_801144D8;
extern s32 D_8011453C;

void func_80039CD8(s32 arg0) {
    if (arg0 != 0) {
        if (D_80114488.unk1C != 0) {
            D_8011453C = D_80114488.unk1C;
            D_80114488.unk1C = 0;
        }
    } else {
        D_80114488.unk1C = D_8011453C;
        D_80114488.unk2C = D_801144D8.unk2C;
        D_80114488.unk40 = D_801144D8.unk40;
    }
}
