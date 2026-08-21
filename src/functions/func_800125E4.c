/* See specs/func_800125E4.md (worker specification) for behavior. */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxWord;

typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8[1];
} ItemList;

extern GfxWord *D_801217B0;

#define EMIT(a, b) { g = D_801217B0; D_801217B0 = g + 1; g->w0 = (a); g->w1 = (b); }

void func_800125E4(ItemList *list, s32 index) {
    register ItemList *l;
    GfxWord *g;

    l = list;

    if (index < list->unk4) {
        if (list->unk0 == 1 || list->unk0 == 3) {
            EMIT(0xFD900000, l->unk8[index])
            EMIT(0xF5900000, 0x07080200)
            EMIT(0xE6000000, 0)
            EMIT(0xF3000000, 0x077FF200)
            EMIT(0xF5800800, 0x00080200)
            EMIT(0xF2000000, 0x000FC1FC)
            EMIT(0xE200001C, 0x00404240)
        } else if (list->unk0 == 2) {
            EMIT(0xFD500000, l->unk8[index])
            EMIT(0xF5500000, 0x07080200)
            EMIT(0xE6000000, 0)
            EMIT(0xF3000000, 0x073FF200)
            EMIT(0xF5400800, 0x00080200)
            EMIT(0xF2000000, 0x000FC0FC)
            EMIT(0xE200001C, 0x00404240)
        } else if (list->unk0 == 0) {
            EMIT(0xFD500000, l->unk8[index])
            EMIT(0xF5500000, 0x07080200)
            EMIT(0xE6000000, 0)
            EMIT(0xF3000000, 0x073FF200)
            EMIT(0xF5400800, 0x00080200)
            EMIT(0xF5400800, 0x01180200)
            EMIT(0xF5400800, 0x02280200)
            EMIT(0xF5400800, 0x03380200)
            EMIT(0xF2000000, 0x000FC0FC)
            EMIT(0xF2000000, 0x010FC0FC)
            EMIT(0xF2000000, 0x020FC0FC)
            EMIT(0xF2000000, 0x030FC0FC)
            EMIT(0xE200001C, 0x00404240)
        }
    }
}
