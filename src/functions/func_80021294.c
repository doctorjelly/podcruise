/* Independently written from the specification specs/func_80021294.md. */
#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct {
    u8 pad00[0x34];
    s32 mode;
    s32 gate;
    s32 *button_source;
    u8 pad38[0x38];
    s8 count;
    s8 pad71;
    s8 entries[2];
} PcTuneState;

extern s32 D_800A2540;
extern s32 D_800A2544;
extern s32 D_800A31E0[];
extern s32 D_800A31E4[];
extern s32 D_800A4B94[];
extern s32 D_800A4BA4[];
extern s32 D_800A4BBC;
extern s16 D_800A4BC0;
extern f32 D_800A4BF0;
extern f32 D_800A4BF4;
extern char D_800A8DF0[];
extern char D_800A8DF4[];
extern char D_800A8DF8[];
extern char D_800A8E04[];
extern char D_800A8E14[];
extern char D_800A8E24[];
extern char D_800A8E34[];
extern char D_800A8E44[];
extern char D_800A8E50[];
extern char D_800A8E5C[];
extern char D_800A8E68[];
extern char D_800A8E74[];
extern char D_800D7288[];
extern f32 D_800D7388;
extern f32 D_800D739C;
extern f32 D_800D73A0;
extern f32 D_800D7720[];
extern f32 D_800D7730[];
extern u8 D_80113E7C;
extern PcVec3f D_80118D90;
extern f32 D_80118D98;
extern PcVec3f D_80118E50;
extern f32 D_80118E58;
extern PcVec3fSlot D_80118E20[4];
extern PcVec3fSlot D_80118E60[4];
extern f32 D_80120BF8;

extern s32 func_8008A6B4(char *buffer, const char *format, ...);
extern void func_8002AFFC(PcTuneState *state, s32 mode, s32 flag);
extern void func_8002B3C8(PcTuneState *state, s32 mode);
extern void func_8002D4C4(s32 sound);
extern void func_800469B4(PcTuneState *state, s32 mode);
extern void func_8003EC40(s16 x, s16 y, u8 red, u8 green, u8 blue, u8 alpha,
                          s32 text);
extern f32 func_800154D0(f32 *vector);
extern f32 func_80014F54(f32 x, f32 y);
extern f32 func_80014D4C(f32 value);
extern f32 func_80015470(const PcVec3f *from, const PcVec3f *to);
extern void func_8001745C(f32 *matrix, f32 first, f32 second, f32 third);

void func_80021294(PcTuneState *state) {
    f32 matrix[4][4];
    PcVec3f offset;
    f32 pitch;
    f32 yaw;
    f32 previous;
    s32 stepped;
    s32 moved;
    s32 saturated;
    s32 index;
    s32 mode;
    s32 gate;
    s32 *button_source;
    s32 row;

    moved = 0;
    saturated = 0;
    stepped = 0;

    if (D_800A2540 != 0 || D_800A4BBC != 0 || D_800A4BC0 == 4) {
        if (D_800A4BBC != 0) {
            func_8008A6B4(D_800D7288, D_800A8DF0);
        }
        if (D_800A4BBC != 0) {
            func_80015268(&D_80118E50, 0.0f, 0.0f, 0.0f);
        }
        state->mode = 20;
        func_8002AFFC(state, 20, 0);
        func_8001535C(&offset, &D_80118D90, &D_80118E50);
        D_800D7388 = func_800153C0(&offset);
        func_800154D0(&offset.x);
        D_800D739C = func_80014F54(-offset.x, offset.y);
        pitch = func_80014D4C(offset.z);
        yaw = D_800D739C;
        if (yaw < 0.0f) {
            yaw = yaw + 360.0f;
        }
        D_800D739C = yaw;
        if (yaw > 360.0f) {
            D_800D739C = yaw - 360.0f;
        }
        if (pitch < -90.0f) {
            pitch = pitch + 180.0f;
        }
        D_800D73A0 = pitch;
        if (pitch > 90.0f) {
            D_800D73A0 = pitch - 180.0f;
        }
        D_800A2540 = 0;
        D_800A4BBC = 0;
        D_800A4BC0 = 0;
        D_800A2544 = 1;
    }

    if (D_800A2544 != 0) {
        D_800A4BF4 = D_800A4BF4 + D_80120BF8;
        if (D_800A4BF4 >= 5.0f) {
            D_800A4BF4 = 5.0f;
        }
    }

    switch (state->mode) {
    case 20:
        func_8008A6B4(D_800D7288, D_800A8DF4);
        break;
    case 21:
        func_8008A6B4(D_800D7288, D_800A8DF8);
        break;
    case 22:
        func_8008A6B4(D_800D7288, D_800A8E04);
        break;
    case 23:
        func_8008A6B4(D_800D7288, D_800A8E14);
        break;
    case 24:
        func_8008A6B4(D_800D7288, D_800A8E24);
        break;
    case 25:
        func_8008A6B4(D_800D7288, D_800A8E34);
        break;
    case 26:
        func_8008A6B4(D_800D7288, D_800A8E50);
        break;
    case 27:
        func_8008A6B4(D_800D7288, D_800A8E5C);
        break;
    case 28:
        func_8008A6B4(D_800D7288, D_800A8E68);
        break;
    case 29:
        func_8008A6B4(D_800D7288, D_800A8E74);
        break;
    case 30:
        row = state->entries[0];
        func_8008A6B4(D_800D7288, D_800A8E44, D_800A31E0[(row * 13) + 5],
                      D_800A31E0[(row * 13) + 6]);
        break;
    }

    func_8003EC40(160, (s16)(s32)(185.0f + 10.0f), 0, 255, 0, 255,
                  (s32)(long)D_800D7288);

    button_source = D_800A4BA4;
    for (index = 0; index < state->count; index++, button_source++) {
        f32 distance;
        s32 buttons;
        s32 held;

        distance = D_800D7388;
        buttons = *button_source;
        if (buttons & 1) {
            func_8002D4C4(0x55);
            D_800A2540 = 1;
            func_800469B4(state, 3);
            return;
        }
        if ((buttons & 2) && !(buttons & 1)) {
            D_800D7388 = distance;
            func_8002D4C4(0x4D);
            D_800A2540 = 1;
            D_800A4BF0 = 0.0f;
            func_800469B4(state, 3);
            return;
        }

        previous = distance;
        if ((f64)D_800D7720[index] > 0.1 || (f64)D_800D7720[index] < -0.1) {
            if (D_800A2544 == 0) {
                D_800D739C = (f32)((f64)D_800D739C +
                                   (f64)(140.0f * D_80120BF8 *
                                         D_800D7720[index]) * 1.5);
                moved = 1;
            }
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
            D_800A2544 = 0;
        }

        gate = D_800A2544;
        if ((f64)D_800D7730[index] > 0.1 || (f64)D_800D7730[index] < -0.1) {
            if (gate == 0) {
                pitch = (f32)((f64)D_800D73A0 +
                              (f64)(45.0f * D_80120BF8 * D_800D7730[index]) *
                                  1.5);
                moved = 1;
                if (pitch > 89.0f) {
                    pitch = 89.0f;
                }
                D_800D73A0 = pitch;
                if (pitch < -89.0f) {
                    D_800D73A0 = -89.0f;
                }
            }
            gate = 0;
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
        }

        held = D_800A4B94[index];
        if (held & 4) {
            if (gate == 0) {
                distance = distance - 800.0f * D_80120BF8;
                if (distance < 100.0f) {
                    distance = 100.0f;
                }
                moved = 1;
            }
            gate = 0;
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
        }
        D_800A2544 = gate;
        D_800D7388 = distance;
        if (held & 8) {
            D_800A2544 = 0;
            D_800D7388 = distance;
            if (gate == 0) {
                distance = distance + 800.0f * D_80120BF8;
                D_800D7388 = distance;
                moved = 1;
                if (distance > 1336.0f) {
                    D_800D7388 = 1336.0f;
                }
            }
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
        }

        if ((D_800A4B94[0] & 0x10) && D_800A4BC0 != 3) {
            mode = state->mode + 1;
            state->mode = mode;
            D_800A2544 = 0;
            stepped = 1;
            if (mode == 22) {
                if (D_800A31E4[state->entries[index] * 13] == 30) {
                    mode = mode + 4;
                    state->mode = mode;
                }
            }
            if (mode == 24) {
                if (D_800A31E4[state->entries[index] * 13] == 40) {
                    mode = mode + 2;
                    state->mode = mode;
                }
            }
            if (mode < 30) {
                if (D_80113E7C < mode - 25) {
                    mode = 30;
                    state->mode = 30;
                }
            }
            if (mode >= 31) {
                state->mode = 20;
            }
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
            D_800A4BF4 = 0.0f;
        }

        if ((D_800A4B94[0] & 0x20) && D_800A4BC0 != 3) {
            mode = state->mode - 1;
            state->mode = mode;
            D_800A2544 = 0;
            stepped = 1;
            if (mode == 25) {
                if (D_800A31E4[state->entries[index] * 13] == 30) {
                    mode = mode - 4;
                    state->mode = mode;
                }
            }
            if (mode == 25) {
                if (D_800A31E4[state->entries[index] * 13] != 40) {
                    mode = mode - 2;
                    state->mode = mode;
                }
            }
            if (D_80113E7C < mode - 25) {
                mode = D_80113E7C + 25;
                state->mode = mode;
            }
            if (mode < 20) {
                state->mode = 30;
            }
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
            D_800A4BF4 = 0.0f;
        }

        if (stepped && !saturated) {
            stepped = 0;
            func_8002AFFC(state, state->mode, 1);
        } else {
            func_8002B3C8(state, state->mode);
        }

        if (moved || D_800A4BC0 == 3) {
            func_8001745C(&matrix[0][0], D_800D739C, D_800D73A0, 0.0f);
            func_800155EC(&D_80118D90, &D_80118E50, D_800D7388,
                          (PcVec3f *)&matrix[1][0]);
            if (D_80118D98 < -147.0f) {
                func_800155EC(&D_80118D90, &D_80118E50,
                              D_800D7388 *
                                  ((D_80118E58 - -147.0f) /
                                   (D_80118E58 - D_80118D98)),
                              (PcVec3f *)&matrix[1][0]);
            }
            if (1066.0f < D_80118D98) {
                func_800155EC(&D_80118D90, &D_80118E50,
                              D_800D7388 *
                                  ((D_80118E58 - 1066.0f) /
                                   (D_80118E58 - D_80118D98)),
                              (PcVec3f *)&matrix[1][0]);
            }
            distance = D_800D7388;
            if (distance != previous) {
                distance = func_80015470(&D_80118D90, &D_80118E50);
            }
            D_800D7388 = distance;
            if (moved) {
                moved = 0;
                func_800156DC(D_80118E60, D_80118E20);
            }
        }
    }

    if (saturated) {
        D_800A4BF4 = 0.0f;
        D_800A2544 = 0;
        func_8002AFFC(state, state->mode, 1);
        func_8001535C(&offset, &D_80118D90, &D_80118E50);
        D_800D7388 = func_800153C0(&offset);
        func_800154D0(&offset.x);
        D_800D739C = func_80014F54(-offset.x, offset.y);
        pitch = func_80014D4C(offset.z);
        yaw = D_800D739C;
        if (yaw < 0.0f) {
            yaw = yaw + 360.0f;
        }
        D_800D739C = yaw;
        if (yaw > 360.0f) {
            D_800D739C = yaw - 360.0f;
        }
        if (pitch < -90.0f) {
            pitch = pitch + 180.0f;
        }
        D_800D73A0 = pitch;
        if (pitch > 90.0f) {
            D_800D73A0 = pitch - 180.0f;
        }
    }
}
