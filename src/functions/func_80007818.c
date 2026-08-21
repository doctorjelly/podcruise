/* Specification: scratchpad specs/func_80007818.md */
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
} Entry80007818;

extern s32 D_8009A2B8;
extern s32 D_8009A2BC;
extern Entry80007818 D_800D2038[];

extern void func_80088B00(s32, s16);
extern void func_80088B20(s32);

void func_80007818(s32 index) {
    Entry80007818 *entry;
    s32 value;
    s16 narrow;

    if (D_8009A2B8 != 0) {
        entry = &D_800D2038[index];
        value = entry->unk00;
        entry->unk18 = 0;
        if (value >= 0) {
            narrow = value;
            func_80088B00(D_8009A2BC, narrow);
            func_80088B20(D_8009A2BC);
        }
    }
}
