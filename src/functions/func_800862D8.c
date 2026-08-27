/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

typedef struct Viewport {
    u8 pad0[0x20];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 pad30[0x140];
} Viewport;

extern s32 D_8009B7E8;
extern Viewport D_80120DF0[];
extern void func_80085FB0(Viewport *);
extern void func_80086178(Viewport *);

void func_800862D8(s32 index, s32 left, s32 top, s32 right, s32 bottom) {
    Viewport *viewport;

    viewport = &D_80120DF0[index];
    if (D_8009B7E8 != 0) {
        left = 0;
        right = 0x140;
        bottom = 0xF0;
        top = 0;
    }
    viewport->unk20 = left;
    viewport->unk24 = top;
    viewport->unk28 = right;
    viewport->unk2C = bottom;
    func_80086178(viewport);
    func_80085FB0(viewport);
}
