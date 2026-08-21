/* Recovered from specification specs/func_800862E0.md */
#include "podcruise/types.h"

typedef struct Slot800862E0 {
    u8 pad0[0x20];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x140];
} Slot800862E0;

extern s32 D_8009B7E8;
extern Slot800862E0 D_80120DF0[];

extern void func_80085FB0(Slot800862E0 *);
extern void func_80086178(Slot800862E0 *);

void func_800862E0(s32 index, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Slot800862E0 *slot;

    if (D_8009B7E8 != 0) {
        arg1 = 0;
        arg3 = 0x140;
        arg4 = 0xF0;
        arg2 = 0;
    }
    slot = &D_80120DF0[index];
    slot->unk20 = arg1;
    slot->unk24 = arg2;
    slot->unk28 = arg3;
    slot->unk2C = arg4;
    func_80086178(slot);
    func_80085FB0(slot);
}
