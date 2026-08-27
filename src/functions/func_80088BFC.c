/* Recovered from scratchpad specification specs/func_80088BFC.md. */
#include "podcruise/types.h"

/*
 * Packaging note: this body lives in a translation unit built one optimisation
 * level above the rest of the ROM, next to the file-local helper it calls
 * twice.  The helper receives its arguments in callee-saved registers and
 * destroys one the caller reloads afterwards, which only happens when the two
 * are compiled together at that level.
 */

typedef struct Chunk80088BFC {
    /* 0x00 */ struct Chunk80088BFC *unk00;
    /* 0x04 */ struct Chunk80088BFC *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ void *unk10;
} Chunk80088BFC;

typedef struct Pool80088BFC {
    /* 0x00 */ Chunk80088BFC *unk00;
    /* 0x04 */ Chunk80088BFC *unk04;
    /* 0x08 */ Chunk80088BFC *unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
} Pool80088BFC;

typedef struct Sample80088BFC {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 unk0C;
    /* 0x0D */ u8 unk0D;
} Sample80088BFC;

typedef struct Program80088BFC {
    /* 0x00 */ Sample80088BFC *unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 unk0C;
} Program80088BFC;

typedef struct Voice80088BFC {
    /* 0x00 */ u8 unk00[0x1C];
    /* 0x1C */ Program80088BFC *unk1C;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ u8 unk2E;
    /* 0x2F */ u8 unk2F;
} Voice80088BFC;

typedef struct Event80088BFC {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ Voice80088BFC *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
} Event80088BFC;

typedef struct Note80088BFC {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ u8 unk04;
    /* 0x05 */ u8 unk05[0xF];
} Note80088BFC;

typedef struct Post80088BFC {
    /* 0x00 */ s16 unk00;
    /* 0x04 */ Voice80088BFC *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
} Post80088BFC;

typedef struct Query80088BFC {
    /* 0x00 */ s16 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
} Query80088BFC;

typedef struct Scratch80088BFC {
    /* 0x00 */ s32 unk00[17];
} Scratch80088BFC;

typedef struct Player80088BFC {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ Pool80088BFC unk14;
    /* 0x28 */ Event80088BFC unk28;
    /* 0x38 */ void *unk38;
    /* 0x3C */ u8 unk3C[0xC];
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
    /* 0x50 */ s32 unk50;
} Player80088BFC;



extern s32 func_80090500(s32);
extern void func_80088020(Chunk80088BFC *);
extern void func_80088050(Chunk80088BFC *, Pool80088BFC *);
extern void func_8008FC3C(void *, void *, s32);
extern s32 func_8008FD60(void *, void *);
extern s32 func_8008FF98(void *, Voice80088BFC *, Note80088BFC *);
extern void func_800900E0(void *, Voice80088BFC *, s32);
extern void func_80090170(void *, Voice80088BFC *, u8);
extern void func_80090200(void *, Voice80088BFC *, s16, s32);
extern void func_800902A0(void *, Voice80088BFC *, f32);
extern void func_80090330(void *, Voice80088BFC *, u8);
extern void func_800903D0(void *, Voice80088BFC *);
extern void func_80090450(void *, Voice80088BFC *);

static void func_80088B70(Pool80088BFC *, void *);

void func_80088BFC(Player80088BFC *player) {
    Query80088BFC post5;
    Note80088BFC note;
    f64 value;
    u8 amount;
    f32 rate;
    Post80088BFC post;
    register s32 count;
    s16 scaled;
    Scratch80088BFC scratch;
    s16 sum;
    s32 total;
    u8 level;
    Event80088BFC *event;
    Voice80088BFC *voice;
    Program80088BFC *program;

    event = &player->unk28;
    for (;;) {
        if (player->unk28.unk00 == 5) {
            post5.unk00 = 5;
            func_8008FC3C(&player->unk14, &post5, player->unk48);
        } else {
            voice = player->unk28.unk04;
            program = voice->unk1C;
        switch (player->unk28.unk00) {
            case 0:
                if (voice->unk28 == 0) {
                    if (program == 0) {
                        break;
                    }
                    note.unk02 = 0;
                    note.unk04 = 0;
                    note.unk00 = voice->unk20;
                    func_8008FF98(player->unk38, voice, &note);
                    scaled = program->unk00->unk0C * voice->unk2C / 0x7F;
                    sum = voice->unk2E + program->unk0C - 0x40;
                    if (sum <= 0) {
                        sum = 0;
                    }
                    if (sum < 0x7F) {
                        amount = sum;
                    } else {
                        amount = 0x7F;
                    }
                    rate = voice->unk24;
                    count = program->unk00->unk00;
                    func_800900E0(player->unk38, voice, program->unk08);
                    voice->unk28 = 1;
                    func_80090170(player->unk38, voice, amount);
                    func_80090200(player->unk38, voice, scaled, count);
                    func_800902A0(player->unk38, voice, rate);
                    func_80090330(player->unk38, voice, voice->unk2F);
                    post.unk00 = 6;
                    post.unk04 = voice;
                    value = (f32)program->unk00->unk00 / voice->unk24;
                    if (2147483647.0 < value) {
                        total = 0x7FFFFFFF;
                    } else {
                        total = (s32)value;
                    }
                    func_8008FC3C(&player->unk14, &post, total);
                }
                break;
            case 1:
                if (voice->unk28 == 1) {
                    if (program == 0) {
                        break;
                    }
                    value = (f32)program->unk00->unk08 / voice->unk24;
                    if (2147483647.0 < value) {
                        total = 0x7FFFFFFF;
                    } else {
                        total = (s32)value;
                    }
                    func_80090200(player->unk38, voice, 0, total);
                    if (total != 0) {
                        post.unk00 = 7;
                        post.unk04 = voice;
                        func_8008FC3C(&player->unk14, &post, total);
                        voice->unk28 = 2;
                    } else {
                        func_800903D0(player->unk38, voice);
                        func_80090450(player->unk38, voice);
                        func_80088B70(&player->unk14, voice);
                        voice->unk28 = 0;
                    }
                    break;
                }
                break;
            case 2:
                voice->unk2E = event->unk08;
                if (voice->unk28 == 1) {
                    if (program == 0) {
                        break;
                    }
                    sum = voice->unk2E + program->unk0C - 0x40;
                    if (sum <= 0) {
                        sum = 0;
                    }
                    if (sum < 0x7F) {
                        level = sum;
                    } else {
                        level = 0x7F;
                    }
                    func_80090170(player->unk38, voice, level);
                }
                break;
            case 4:
                voice->unk24 = *(f32 *)&event->unk08;
                if (voice->unk24 < 0.0001) {
                    voice->unk24 = 0.0001;
                }
                if (voice->unk28 == 1) {
                    func_800902A0(player->unk38, voice, voice->unk24);
                }
                break;
            case 8:
                voice->unk2F = event->unk08;
                if (voice->unk28 == 1) {
                    func_80090330(player->unk38, voice, voice->unk2F);
                }
                break;
            case 3:
                voice->unk2C = event->unk08;
                if (voice->unk28 == 1) {
                    if (program != 0) {
                        scaled = program->unk00->unk0D * voice->unk2C / 0x7F;
                        func_80090200(player->unk38, voice, scaled, 1000);
                    }
                }
                break;
            case 6:
                if (program->unk00->unk04 != -1) {
                    value = (f32)program->unk00->unk04 / voice->unk24;
                    if (2147483647.0 < value) {
                        total = 0x7FFFFFFF;
                    } else {
                        total = (s32)value;
                    }
                    func_80090200(player->unk38, voice, program->unk00->unk0D * voice->unk2C / 0x7F, total);
                    post.unk00 = 1;
                    post.unk04 = voice;
                    func_8008FC3C(&player->unk14, &post, total);
                }
                break;
            case 7:
                func_800903D0(player->unk38, voice);
                func_80090450(player->unk38, voice);
                func_80088B70(&player->unk14, voice);
                voice->unk28 = 0;
                break;
            }
        }
        player->unk4C = func_8008FD60(&player->unk14, event);
        if (player->unk4C != 0) {
            break;
        }
    }
    (void)scratch;
    player->unk50 += player->unk4C;
}

static void func_80088B70(Pool80088BFC *pool, void *owner) {
    Chunk80088BFC *chunk;
    Chunk80088BFC *next;
    s32 saved;

    saved = func_80090500(1);
    chunk = pool->unk08;
    while (chunk != 0) {
        next = chunk->unk00;
        if (chunk->unk10 == owner) {
            if (next != 0) {
                next->unk08 += chunk->unk08;
            }
            func_80088020(chunk);
            func_80088050(chunk, pool);
        }
        chunk = next;
    }
    func_80090500(saved);
}

