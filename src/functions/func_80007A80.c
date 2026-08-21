/* Recovered per specs/func_80007A80.md (worker specification). */
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
extern s32 D_8009A2BC;
extern Slot D_800D2038[];
extern void func_80088B00(s32, s16);
extern void func_80088B20(s32);
void func_80007A80(void) {
    s32 i;

    if (D_8009A2B8 != 0) {
        for (i = 0; i < 8; i++) {
            D_800D2038[i].unk18 = 0;
            if (D_800D2038[i].unk8 == 0) {
                if (D_800D2038[i].unk0 >= 0) {
                    func_80088B00(D_8009A2BC, D_800D2038[i].unk0);
                    func_80088B20(D_8009A2BC);
                }
            }
        }
    }
}
