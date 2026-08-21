/* Independently written from scratchpad spec specs/func_80095820.md. */

#include "podcruise/types.h"

typedef struct Unk80095820 {
    char unk_00[0x10];
    u32 unk_10;
} Unk80095820;

extern Unk80095820 *D_8014D7D4;
extern u32 D_800A7B50;
extern void func_800958D4(void);

void func_80095820(void) {
    Unk80095820 *entry;
    u32 stat;

    entry = D_8014D7D4 + 1;
    stat = *(volatile u32 *)(unsigned long)0xA4600010U;
    while ((stat & 3) != 0) {
        stat = *(volatile u32 *)(unsigned long)0xA4600010U;
    }
    *(volatile u32 *)(unsigned long)0xA5000510U = entry->unk_10 | 0x10000000U;
    stat = *(volatile u32 *)(unsigned long)0xA4600010U;
    while ((stat & 3) != 0) {
        stat = *(volatile u32 *)(unsigned long)0xA4600010U;
    }
    *(volatile u32 *)(unsigned long)0xA5000510U = entry->unk_10;
    func_800958D4();
    *(volatile u32 *)(unsigned long)0xA4600010U = 2;
    D_800A7B50 |= 0x00100401U;
}
