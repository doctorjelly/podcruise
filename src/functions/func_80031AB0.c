/* Recovered from the specification in specs/func_80031AB0.md (worker notes). */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
} Unk800A2870;

extern void func_800314DC(s32 slot, u16 flags, s32 first, s32 second);

extern Unk800A2870 D_800A2870[];
extern s32 D_800A290C[];
extern struct Unk800DB8A8 {
    s16 unk00;
    s16 unk02[13];
} D_800DB8A8[];

void func_80031AB0(s32 slot, s32 level, s16 flags) {
    if (level >= 13) {
        while (1) {
        }
    }
    if (level < D_800A290C[slot]) {
        return;
    }
    if (level == D_800A290C[slot]) {
        if (D_800A2870[level].unk04 != 0) {
            return;
        }
        if (D_800DB8A8[slot].unk00 != 0) {
            return;
        }
    }
    D_800A290C[slot] = level;
    func_800314DC(slot, flags, D_800A2870[level].unk04, D_800A2870[level].unk08);
}
