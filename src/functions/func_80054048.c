/* Implements the specification in specs/func_80054048.md (race timing and lap advance step). */
#include "podcruise/types.h"

typedef struct Racer54048 {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ s32 flags;
    /* 0x0C */ u8 pad0C[0x10 - 0xC];
    /* 0x10 */ u8 slot;
    /* 0x11 */ u8 pad11[0x18 - 0x11];
    /* 0x18 */ s32 *name;
    /* 0x1C */ u8 pad1C[0x5C - 0x1C];
    /* 0x5C */ s16 place;
    /* 0x5E */ u8 pad5E[0x60 - 0x5E];
    /* 0x60 */ f32 lap[5];
    /* 0x74 */ f32 total;
    /* 0x78 */ s32 lapIndex;
    /* 0x7C */ u8 pad7C[0x84 - 0x7C];
    /* 0x84 */ struct Body54048 *body;
} Racer54048;

typedef struct Body54048 {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ s32 stateA;
    /* 0x64 */ s32 stateB;
} Body54048;

typedef struct Race54048 {
    /* 0x000 */ u8 pad000[0x8];
    /* 0x008 */ s32 flags;
    /* 0x00C */ f32 elapsed;
    /* 0x010 */ u8 pad010[0x34 - 0x10];
    /* 0x034 */ u8 pathA[0x30];
    /* 0x064 */ f32 matrixA[16];
    /* 0x0A4 */ u8 pad0A4[0x130 - 0xA4];
    /* 0x130 */ s32 hasPathB;
    /* 0x134 */ u8 pathB[0x30];
    /* 0x164 */ f32 matrixB[16];
    /* 0x1A4 */ u8 pad1A4[0x1AC - 0x1A4];
    /* 0x1AC */ s32 mode;
    /* 0x1B0 */ u8 pad1B0[0x1BC - 0x1B0];
    /* 0x1BC */ s32 count;
    /* 0x1C0 */ s32 view;
    /* 0x1C4 */ u8 pad1C4[0x1C8 - 0x1C4];
    /* 0x1C8 */ s32 laps;
    /* 0x1CC */ u8 pad1CC[0x1D0 - 0x1CC];
    /* 0x1D0 */ f32 best;
} Race54048;

extern Racer54048 *D_8011B1B8;
extern Racer54048 *D_8011B1BC;
extern Racer54048 *D_8011B1C0;
extern Racer54048 *D_8011B1C4;
extern Racer54048 *D_8011B1C8;
extern s32 D_800A52D0;
extern f32 D_800ACEA8;
extern f64 D_80120BF0;

extern void func_800092EC(s32 owner, s32 handle, s32 detail);
extern u32 func_80009524(s32 index, u32 mask);
extern void func_8000953C(s32 index, u32 mask);
extern void func_80009704(s32 owner, s32 handle, s32 detail, s32 first,
                          s32 second, s32 third);
extern void func_8000FCA4(s32 index, u8 value);
extern void func_80011764(f32 first, f32 second);
extern void func_800117A4(s32 value);
extern void func_800117E4(f32 value);
extern void func_80031BBC(s32 index);
extern void func_80031BEC(s32 index);
extern void func_8003B02C(void *path, void *matrix);
extern f32 func_800521C0(Racer54048 *racer);
extern void func_80052208(Race54048 *race);
extern void func_80053AD4(void *race, void *racer);
extern void func_80053C08(Race54048 *race);
extern s32 func_80080BEC(void *body, f32 *step);

void func_80054048(Race54048 *race) {
    f32 spare[4];
    f32 step;
    s32 running;
    s32 moved;
    Racer54048 *racer;
    f32 rate;
    register f32 cap;
    s32 i;

    (void)spare;

    running = race->flags & 0xF;
    if (running == 4) {
        if (race->hasPathB != 0) {
            func_8003B02C(race->pathB, race->matrixB);
            running = race->flags & 0xF;
        }
    }

    if (running == 1) {
        func_8003B02C(race->pathA, race->matrixA);
        race->flags = (race->flags & ~0xF) | 2;

        for (i = 0; i < race->count; i++) {
            cap = D_800ACEA8;
            racer = &D_8011B1B8[i];
            if ((racer->flags & 1) && !(racer->flags & 2)) {
                moved = func_80080BEC(racer->body, &step);
                if (D_800A52D0 != 0) {
                    func_80053AD4(race, racer);
                }
                if (moved != 0) {
                    if (race->mode == 1) {
                        if (race->view == 0) {
                            if (racer->lapIndex == 0) {
                                func_80011764(25.0f, 45.0f);
                                func_800117A4(20);
                            } else {
                                func_800117A4(60);
                                func_80011764(20.0f, 60.0f);
                                func_8000FCA4(0, 0x80);
                            }
                        } else if (race->view == 1) {
                            if (racer->lapIndex == 0) {
                                func_800117A4(60);
                                func_80011764(20.0f, 60.0f);
                                func_8000FCA4(0, 0x80);
                            } else {
                                func_800117A4(80);
                                func_80011764(10.0f, 90.0f);
                                func_800117E4(1.0f);
                                func_8000FCA4(0, 0x14);
                            }
                        } else if (race->view == 2) {
                            if (racer->lapIndex == 0) {
                                func_800117A4(80);
                                func_80011764(10.0f, 60.0f);
                                func_8000FCA4(0, 0x40);
                            } else {
                                func_800117A4(80);
                                func_80011764(10.0f, 90.0f);
                                func_800117E4(1.0f);
                                func_8000FCA4(0, 0x14);
                            }
                        }
                    }

                    racer->total = racer->total + step;
                    racer->lap[racer->lapIndex] = racer->lap[racer->lapIndex] + step;
                    if (racer->body->stateA & 0x20) {
                        if (racer->lap[racer->lapIndex] < race->best) {
                            race->best = racer->lap[racer->lapIndex];
                        }
                    }
                    racer->lapIndex = racer->lapIndex + 1;
                    if (racer->lapIndex == race->laps) {
                        if (racer->body->stateA & 0x20) {
                            racer->body->stateB |= 0x4000000;
                            func_80031BEC(racer->slot);
                            func_80031BBC(racer->slot);
                            if (racer->lap[race->laps - 1] <= race->best) {
                                if (func_80009524(racer->slot, 0x100000) == 0) {
                                    if (racer->place == 1) {
                                        func_80009704(1, *racer->name, 0xF, 6, 0, 0x27);
                                    } else if (racer->place >= 5) {
                                        func_80009704(1, *racer->name, 0x10, 6, 0, 0x27);
                                    } else {
                                        func_800092EC(6, 0, 0x27);
                                    }
                                    func_8000953C(racer->slot, 0x100000);
                                }
                            } else {
                                if (racer->place == 1) {
                                    func_800092EC(1, *racer->name, 0xF);
                                } else if (racer->place >= 5) {
                                    func_800092EC(1, *racer->name, 0x10);
                                }
                            }
                        }
                        racer->flags |= 2;
                        racer->body->stateA &= ~0x20;
                        racer->body->stateA &= ~0x00A00000;
                        racer->body->stateA |= 0x80;
                        racer->body->stateB |= 0x2000000;
                    } else {
                        racer->lap[racer->lapIndex] = 0.0f;
                    }
                } else {
                    step = 0.0f;
                }

                if (!(racer->flags & 2)) {
                    racer->total = (f32)((f64)racer->total + (D_80120BF0 - (f64)step));
                    if (cap < racer->total) {
                        racer->total = cap;
                    }
                    racer->lap[racer->lapIndex] =
                        (f32)((f64)racer->lap[racer->lapIndex] + (D_80120BF0 - (f64)step));
                    if (cap < racer->lap[racer->lapIndex]) {
                        racer->lap[racer->lapIndex] = cap;
                    }
                    if (D_8011B1BC == 0 || racer == D_8011B1BC ||
                        racer == D_8011B1C0 || racer == D_8011B1C4 ||
                        racer == D_8011B1C8) {
                        race->flags = (race->flags & ~0xF) | 1;
                    }
                }
            } else if (racer->flags & 2) {
                func_80080BEC(racer->body, &step);
            }
        }

        func_80052208(race);
        func_80053C08(race);

        if ((race->flags & 0xF) == 2) {
            race->elapsed = 0.0f;
            for (i = 0; i < race->count; i++) {
                racer = &D_8011B1B8[i];
                rate = func_800521C0(racer);
                if (rate < (f32)race->laps) {
                    racer->total = (racer->total / rate) * (f32)race->laps;
                    racer->body->stateA &= ~0x00A00000;
                    racer->body->stateB |= 0x2000000;
                }
            }
        }
    } else if (running == 2) {
        for (i = 0; i < race->count; i++) {
            racer = &D_8011B1B8[i];
            func_80080BEC(racer->body, &step);
        }
    } else if (running != 6) {
        for (i = 0; i < race->count; i++) {
            racer = &D_8011B1B8[i];
            func_80080BEC(racer->body, &step);
        }
    }
}
