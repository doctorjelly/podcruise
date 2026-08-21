/* Recovered per specs/func_800078B4.md (worker specification). */
#include "podcruise/types.h"

typedef struct Slot {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
} Slot;

extern s32 D_8009A2B8;
extern f32 D_800A81C4;
extern Slot D_800D2038[];
extern Slot D_800D2138;
void func_800078B4(void) {
    s32 i;
    f32 scale;

    if (D_8009A2B8 != 0) {
        for (i = 0; i < 8; i++) {
            scale = D_800A81C4;
            if (D_800D2038[i].unk4 != 0x4E) {
                D_800D2038[i].unk18 = (s32)((f32)D_800D2038[i].unk18 * scale);
            }
            if ((f32)D_800D2038[i].unk18 < 0.0f) {
                D_800D2038[i].unk18 = 0;
            }
        }
    }
}
