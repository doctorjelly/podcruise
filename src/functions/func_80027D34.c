/* Recovered per specs/unc05_func_80027D24.md; boundary corrected to 0x80027D24. */
#include "podcruise/types.h"

extern f32 D_80119010;
extern u8 D_80113E60[];
extern s32 func_80082BE0(void);
extern void func_800399F0(void);

#define RND() ((f32)func_80082BE0() / (f32)2147483648.0)

void func_80027D24(s32 arg0, s32 arg1) {
    s32 total;
    s32 count;
    s32 i;
    s32 idx;
    s32 limit;
    s32 value;
    u8 amount;

    (void)arg0;
    (void)arg1;
    total = (s32)(D_80119010 * 255.0f);
    if (total > 0x5FA) {
        total = 0x5FA;
    }
    count = 0;
    for (i = 0; i < 7; i++) {
        if (D_80113E60[0x1D + i] > 0) {
            count++;
        }
    }
    if (count != 0) {
        amount = 25 + (s32)(RND() * 52.0f);
        while (total >= amount) {
            idx = (s32)(RND() * 7.0f);
            if (D_80113E60[0x1D + idx] > 0) {
                value = D_80113E60[0x24 + idx];
                if (amount < value) {
                    D_80113E60[0x24 + idx] = value - amount;
                } else {
                    D_80113E60[0x24 + idx] = 0;
                }
            }
            total -= amount;
            amount = 25 + (s32)(RND() * 52.0f);
        }
        for (i = 0; i < 7; i++) {
            if (D_80113E60[0x1D + i] == 0) {
                D_80113E60[0x24 + i] = 255;
            }
        }
        total = 0;
        for (i = 0; i < 7; i++) {
            total += 255 - D_80113E60[0x24 + i];
        }
        limit = D_80113E60[0x1C] * 255;
        if (limit >= total) {
            for (i = 0; i < 7; i++) {
                D_80113E60[0x24 + i] = 255;
            }
        } else {
            amount = 25 + (s32)(RND() * 52.0f);
            while (limit >= amount) {
                idx = (s32)(RND() * 7.0f);
                value = D_80113E60[0x24 + idx];
                if (value < 255) {
                    if (255 - value < amount) {
                        amount = amount + value - 255;
                        D_80113E60[0x24 + idx] = 255;
                    } else {
                        D_80113E60[0x24 + idx] = value + amount;
                    }
                    limit -= amount;
                }
                amount = 25 + (s32)(RND() * 52.0f);
            }
        }
        func_800399F0();
    }
}
