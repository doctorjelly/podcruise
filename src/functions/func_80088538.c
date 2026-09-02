/* Recovered from specs/func_80088538.md (worker specification for the mixer command-list builder). */
#include "podcruise/types.h"

typedef struct Voice80088538 {
    /* 0x00 */ struct Voice80088538 *next;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 (*step)(struct Voice80088538 *);
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
} Voice80088538;

typedef struct Driver80088538 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ u32 *(*emit)(struct Driver80088538 *, s16 *, s32, s32, u32 *);
    /* 0x08 */ void (*setup)(struct Driver80088538 *, s32, u32 *);
} Driver80088538;

typedef struct Mixer80088538 {
    /* 0x00 */ Voice80088538 *head;
    /* 0x04 */ u8 pad04[0x18];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ u8 pad24[0x14];
    /* 0x38 */ Driver80088538 *driver;
    /* 0x3C */ u8 pad3C[8];
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
} Mixer80088538;

extern Mixer80088538 *D_800A6990;
extern void func_80088488(Mixer80088538 *);

u32 *func_80088538(u32 *commands, s32 *countOut, void *state, s32 samples) {
    Voice80088538 *best[1];
    s16 flag[6];
    Mixer80088538 *mixer;
    Voice80088538 *node;
    Driver80088538 *driver;
    u32 *cursor;
    u32 *out;
    s32 position;
    s32 delta;
    s32 delta2;
    s32 chunk;
    s32 spare[11];

    (void)spare;
    mixer = D_800A6990;
    cursor = commands;
    out = state;
    flag[1] = 0;
    if (mixer->head == 0) {
        *countOut = 0;
        return commands;
    }

    best[0] = 0;
    node = mixer->head;
    delta = 0x7FFFFFFF;
    while (node != 0) {
        if ((node->unk10 - mixer->unk20) < delta) {
            best[0] = node;
            delta = node->unk10 - mixer->unk20;
        }
        node = node->next;
    }

    position = best[0]->unk10;
    mixer->unk1C = position;
    if ((position - mixer->unk20) < samples) {
        do {
            mixer->unk1C &= ~0xF;
            best[0]->unk10 += (s32)(f32)(((f64)((f32)best[0]->step(best[0]) * (f32)mixer->unk44) / 1000000.0) + 0.5);

            best[0] = 0;
            node = mixer->head;
            delta2 = 0x7FFFFFFF;
            while (node != 0) {
                if ((node->unk10 - mixer->unk20) < delta2) {
                    best[0] = node;
                    delta2 = node->unk10 - mixer->unk20;
                }
                node = node->next;
            }
            position = best[0]->unk10;
            mixer->unk1C = position;
        } while ((position - mixer->unk20) < samples);
    }

    mixer->unk1C &= ~0xF;
    while (samples > 0) {
        chunk = (mixer->unk48 < samples) ? mixer->unk48 : samples;
        cursor[0] = 0x07000000;
        cursor[1] = 0;
        driver = mixer->driver;
        driver->setup(driver, 6, out);
        cursor = driver->emit(driver, &flag[1], chunk, mixer->unk20, cursor + 2);
        samples -= chunk;
        out += chunk;
        mixer->unk20 += chunk;
    }

    *countOut = (s32)((u8 *)cursor - (u8 *)commands) >> 3;
    func_80088488(mixer);
    return cursor;
}
