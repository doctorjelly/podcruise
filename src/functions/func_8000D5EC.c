/* Independently written from specs/func_8000D5EC.md. */

#include "podcruise/types.h"

typedef struct Holder {
    s8 pad00[0x1C];
    s32 unk1C;
} Holder;

/* The constant pool that precedes this function's jump table belongs to
   neighbouring code; in an isolated probe unit this stand-in reserves the
   same number of words so that the table keeps its ROM address. */
#ifndef POOL_PAD_WORDS
#define POOL_PAD_WORDS 3
#endif
static const u32 D_800A8630[POOL_PAD_WORDS] = { 0 };

extern s32 D_8009B7D0;
extern u32 D_8009B7D8;
extern s32 D_800A52D0;
extern s32 D_800A52D4;
extern f32 D_800A5B54;
extern f32 D_800A5B58;
extern f32 D_800A5B64;
extern f32 D_800A5B68;
extern Holder D_800D6960;

extern void func_8000C724(s32 *value, f32 rate, f32 scale, s32 lower, s32 upper);
extern void func_8000C6C8(f32 *value, f32 rate, f32 scale, f32 lower, f32 upper);

void func_8000D5EC(s32 selector, f32 value) {
    s32 *toggle;
    Holder *holder;

    (void)D_800A8630;

    switch (selector) {
    case 0:
        func_8000C724(&D_8009B7D0, value, 1.0f, 0, 6);
        break;
    case 1:
        toggle = &D_800A52D4;
        if (D_8009B7D8 & 4) {
            *toggle = (*toggle == 0);
        }
        break;
    case 2:
        if (D_8009B7D8 & 8) {
            func_8000C6C8(&D_800A5B64, value, 0.001f, 0.2f, 2.0f);
        }
        break;
    case 3:
        if (D_8009B7D8 & 8) {
            func_8000C6C8(&D_800A5B68, value, 0.5f, 2.0f, 200.0f);
        }
        break;
    case 4:
        if (D_8009B7D8 & 8) {
            func_8000C6C8(&D_800A5B54, value, 1.0f, 20.0f, 1000.0f);
        }
        break;
    case 5:
        if (D_8009B7D8 & 8) {
            func_8000C6C8(&D_800A5B58, value, 1.0f, 20.0f, 500.0f);
        }
        break;
    case 6:
        toggle = &D_800A52D0;
        if (D_8009B7D8 & 0x10) {
            *toggle = (*toggle == 0);
        }
        break;
    case 7:
        if (D_8009B7D8 & 0x20) {
            holder = &D_800D6960;
            if (holder->unk1C & 0x4000) {
                holder->unk1C = holder->unk1C & ~0x4000;
            } else {
                holder->unk1C = holder->unk1C | 0x4000;
            }
        }
        break;
    case 8:
        break;
    }
}
