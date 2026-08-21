/* Independently written from scratchpad spec specs/func_80093DB0.md. */

#include "podcruise/types.h"
typedef struct TimerNode {
    struct TimerNode *unk00;
    struct TimerNode *unk04;
    u64 unk08;
    u64 unk10;
    void *unk18;
    void *unk1C;
} TimerNode;

/* The original translation unit owned this counter, so it is written here as a
   tentative definition; the recovered accesses only match when the assembler
   can pair the two halves of the 64-bit store against one symbol. */
u64 D_8014C510;

extern s32 D_8014C518;
extern s32 D_8014C51C;
extern TimerNode *D_800A7FC0;

void func_80093DB0(void) {
    D_8014C510 = 0;
    D_8014C518 = 0;
    D_8014C51C = 0;

    D_800A7FC0->unk04 = D_800A7FC0;
    D_800A7FC0->unk00 = D_800A7FC0->unk04;
    D_800A7FC0->unk10 = 0;
    D_800A7FC0->unk08 = D_800A7FC0->unk10;
    D_800A7FC0->unk18 = 0;
    D_800A7FC0->unk1C = 0;
}
