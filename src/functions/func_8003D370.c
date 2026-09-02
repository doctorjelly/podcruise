/* Independently written from specs/func_8003D370.md. */

#include "podcruise/types.h"
typedef struct { u32 command; u32 payload; } PcDisplayWord;
extern PcDisplayWord *D_801217B0;
extern u32 D_800A4960;
void func_8003D370(void) {
    PcDisplayWord *g;
    u32 d;
    PcDisplayWord *h;

    d = D_800A4960; (void)d;
    h = D_801217B0; (void)h;
    g = D_801217B0++; g->command = 0xD7000000; g->payload = 0x80008000;
    g = D_801217B0++; g->command = 0xFCFFFFFF; g->payload = 0xFFFE793C;
    g = D_801217B0++; g->command = 0xE2001D00; g->payload = 0;
    if (D_800A4960 & 1) {
        g = D_801217B0++; g->command = 0xE200001C; g->payload = 0x0F0A4000;
    }
    if (D_800A4960 & 4) {
        g = D_801217B0++; g->command = 0xE2001E01; g->payload = 0;
    }
}
