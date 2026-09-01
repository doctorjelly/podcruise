/* Independently written from scratchpad spec specs/func_80027D24.md. */

#include "podcruise/types.h"

extern s32 func_80082BE0(void);
extern void func_800399F0(void);
extern f32 D_80119010;
extern u8 D_80113E60[];
extern u8 D_80113E84;
extern u8 D_80113E85;
extern u8 D_80113E86;

void func_80027D24(s32 arg0, s32 arg1) {
    s32 total;
    s32 count;
    u8 amount;
    s32 taken;
    s32 value;
    s32 index;
    s32 cap;
    s32 i;
    s32 draw;

    (void)arg0;
    (void)arg1;

    total = (s32)(D_80119010 * 255.0f);
    if (total >= 0x5FB) {
        total = 0x5FA;
    }
    count = 0;
    for (i = 0; i < 7; i++) {
        if (D_80113E60[i + 0x1D] > 0) {
            count++;
        }
    }
    if (count == 0) {
        return;
    }

    draw = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 52.0f);
    draw += 25;
    amount = draw & 0xFF;
    while (total >= amount) {
        index = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 7.0f);
        if (D_80113E60[index + 0x1D] > 0) {
            value = D_80113E60[index + 0x24];
            if (amount < value) {
                D_80113E60[index + 0x24] = value - amount;
            } else {
                D_80113E60[index + 0x24] = 0;
            }
        }
        total -= amount;
        draw = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 52.0f);
        draw += 25;
        amount = draw & 0xFF;
    }

    for (i = 0; i < 7; i++) {
        if (D_80113E60[i + 0x1D] == 0) {
            D_80113E60[i + 0x24] = 255;
        }
    }
    total = 0;
    for (i = 0; i < 7; i++) {
        total = total - D_80113E60[i + 0x24] + 255;
    }
    cap = D_80113E60[0x1C] * 255;
    if (cap >= total) {
        D_80113E84 = 255;
        D_80113E85 = 255;
        D_80113E86 = 255;
        i = 3;
        D_80113E60[i + 0x27] = 255;
        D_80113E60[i + 0x26] = 255;
        D_80113E60[i + 0x25] = 255;
        D_80113E60[i + 0x24] = 255;
    } else {
        draw = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 52.0f);
        draw += 25;
        amount = draw & 0xFF;
        while (cap >= amount) {
            index = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 7.0f);
            value = D_80113E60[index + 0x24];
            if (value < 255) {
                if (255 - value < amount) {
                    amount = amount + value - 255;
                    taken = amount & 0xFF;
                    D_80113E60[index + 0x24] = 255;
                } else {
                    taken = amount;
                    D_80113E60[index + 0x24] = value + taken;
                }
                cap -= taken;
            }
            draw = (s32)((f32)func_80082BE0() / (f32)2147483648.0 * 52.0f);
            draw += 25;
            amount = draw & 0xFF;
        }
    }
    func_800399F0();
}
