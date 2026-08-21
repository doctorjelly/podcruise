/* Recovered from specification specs/func_8003D110.md (batch 10). */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} PcGfx;

extern PcGfx *D_801217B0;
extern u32 D_800A4960;
extern u32 D_800A48D0;
extern u32 D_80114540;
extern u32 D_80114544;
extern u32 D_80114548;
extern u32 D_8011454C;
extern s16 D_8011447C;
extern u32 D_800D697C;
extern u8 D_800A3C80[];

#define PC_CMD(a, b) { PcGfx *g_ = D_801217B0++; g_->w0 = (u32)(a); g_->w1 = (u32)(b); }

void func_8003D110(void) {
    D_800A4960 = 0;
    D_80114548 = 0;
    D_8011454C = 0;
    D_80114540 = 0x140;
    D_80114544 = 0xF0;

    PC_CMD(0xE7000000, 0)
    PC_CMD(0xE3000A01, 0)
    PC_CMD(0xD7000002, 0x80008000)
    PC_CMD(0xE2001E01, 0)
    PC_CMD(0xE3000C00, 0)
    PC_CMD(0xE3001201, 0)
    PC_CMD(0xE3001402, 0xC00)
    PC_CMD(0xE3000D01, 0)
    PC_CMD(0xE3000F00, 0)
    PC_CMD(0xE3001001, 0)
    PC_CMD(0xE200001C, 0x0F0A7008)
    PC_CMD(0xDC38000E, (unsigned long)D_800A3C80)
    PC_CMD(0xDB0C0000, 0x00010000)

    if ((D_800D697C & 0x800) == 0) {
        PC_CMD(0xE3001801, D_8011447C)
        PC_CMD(0xE3001A01, 0x30)
    } else {
        PC_CMD(0xE3001801, 0xC0)
        PC_CMD(0xE3001A01, 0x30)
    }
    D_800A48D0 = 0;
}
