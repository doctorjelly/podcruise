/* Independently written from the specification in specs/func_8008D870.md. */

#include "podcruise/types.h"

typedef struct Envelope {
    /* 0x00 */ u8 pad00[0x14];
    /* 0x14 */ void *unk14;
    /* 0x18 */ u8 pad18[0x8];
    /* 0x20 */ f32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ u8 pad28[0xC];
} Envelope; /* 0x34 */

typedef struct Channel {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ u8 pad02[0x26];
    /* 0x28 */ void *unk28;
    /* 0x2C */ u8 pad2C[0x4];
} Channel; /* 0x30 */

typedef struct Voice {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ Channel *unk20;
    /* 0x24 */ Envelope *unk24;
} Voice; /* 0x28 */

typedef struct Sequence {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s16 *unk14;
    /* 0x18 */ s16 *unk18;
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ Voice *unk20;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 pad25[0x3];
    /* 0x28 */ void *unk28;
} Sequence;

typedef struct Song {
    /* 0x00 */ u8 pad00[0x18];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 unk1C;
    /* 0x1D */ u8 pad1D[0x3];
    /* 0x20 */ s32 *unk20;
} Song;

extern s32 D_800A7BF0[];
extern s32 D_800A7C58[];
extern s32 D_800A7CE0[];
extern s32 D_800A7D08[];
extern s32 D_800A7D30[];
extern s32 D_800A7D58[];

extern void func_800963B4();
extern void func_800963CC();
extern void func_80096158();
extern void func_80095AA0(Sequence *, void *, void *, s32);
extern void *func_80087FC0(const char *, s32, void *, u32, u32);
extern void func_8008D7D0(Channel *);

void func_8008D870(Sequence *sequence, Song *song, void *arena) {
    Voice *voice;
    s32 *table;
    s32 value;
    u16 cursor;
    u16 index;
    u16 i;
    s32 one;

    func_80095AA0(sequence, 0, (void *)func_800963B4, 5);

    sequence->unk04 = (void *)func_800963CC;
    sequence->unk28 = (void *)func_80096158;

    one = 1;
    switch (song->unk1C) {
        case 1:
            table = D_800A7BF0;
            break;
        case 2:
            table = D_800A7C58;
            break;
        case 5:
            table = D_800A7CE0;
            break;
        case 3:
            table = D_800A7D08;
            break;
        case 4:
            table = D_800A7D30;
            break;
        case 6:
            table = song->unk20;
            break;
        default:
            table = D_800A7D58;
            break;
    }

    sequence->unk24 = table[0];
    sequence->unk1C = table[1];
    cursor = 2;
    sequence->unk20 = func_80087FC0(0, 0, arena, sequence->unk24, 0x28);
    sequence->unk14 = func_80087FC0(0, 0, arena, sequence->unk1C, 2);
    sequence->unk18 = sequence->unk14;

    for (i = 0; i < sequence->unk1C; i++) {
        sequence->unk14[i] = 0;
    }

    for (index = 0; index < sequence->unk24; index++) {
        voice = &sequence->unk20[index];
        voice->unk00 = table[cursor++];
        voice->unk04 = table[cursor++];
        voice->unk0A = table[cursor++];
        voice->unk08 = table[cursor++];
        voice->unk0C = table[cursor++];
        value = table[cursor];
        if (value != 0) {
            voice->unk10 = value / 1000.0f * 2.0 / song->unk18;
            cursor = cursor + 1;
            voice->unk1C = (f32)table[cursor++] / 173123.40490667601 *
                           (f64)(u32)(voice->unk04 - voice->unk00);
            voice->unk14 = 1.0f;
            voice->unk18 = 0;
            voice->unk24 = func_80087FC0(0, 0, arena, one, 0x34);
            voice->unk24->unk14 = func_80087FC0(0, 0, arena, one, 0x20);
            voice->unk24->unk20 = 0.0f;
            voice->unk24->unk24 = one;
        } else {
            voice->unk24 = 0;
            cursor++;
            cursor++;
        }
        if (table[cursor] != 0) {
            voice->unk20 = func_80087FC0(0, 0, arena, one, 0x30);
            voice->unk20->unk28 = func_80087FC0(0, 0, arena, one, 8);
            voice->unk20->unk00 = table[cursor];
            cursor++;
            func_8008D7D0(voice->unk20);
        } else {
            voice->unk20 = 0;
            cursor++;
        }
    }
}
