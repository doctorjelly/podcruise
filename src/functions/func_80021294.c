/* Independently written from the specification specs/func_80021294.md. */
#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct {
    u8 pad00[0x34];
    s32 mode;
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
    f32 yaw;
    s32 moved;
    s32 *flags;
    f32 previous;
    s32 saturated;
    f32 matrix[4][4];
    PcVec3f offset;
    f32 *cam;
    s32 gate;
    f32 pitch;
    s32 stepped;
    s32 mode;
    s32 index;
    /* pointer views of the camera globals keep IDO from hoisting their addresses */
    cam = &D_800D7388;
    flags = &D_800A2544;
    moved = 0;
    stepped = 0;
    saturated = 0;

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
        cam[0] = func_800153C0(&offset);
        func_800154D0(&offset.x);
        cam[5] = func_80014F54(-offset.x, offset.y);
        pitch = func_80014D4C(offset.z);
        yaw = cam[5];
        if (yaw < 0.0f) {
            yaw = yaw + 360.0f;
        }
        cam[5] = yaw;
        if (yaw > 360.0f) {
            cam[5] = yaw - 360.0f;
        }
        if (pitch < -90.0f) {
            pitch = pitch + 180.0f;
        }
        cam[6] = pitch;
        if (pitch > 90.0f) {
            cam[6] = pitch - 180.0f;
        }
        D_800A4BF4 = 0.0f;
        D_800A2540 = 0;
        D_800A4BBC = 0;
        D_800A4BC0 = 0;
        flags[0] = 1;
    }

    if (flags[0] != 0) {
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
    case 30:
        mode = state->entries[0];
        func_8008A6B4(D_800D7288, D_800A8E44, D_800A31E0[(mode * 13) + 5],
                      D_800A31E0[(mode * 13) + 6]);
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
    }

    previous = 185.0f;
    func_8003EC40(160, (s16)(s32)(previous + 10.0f), 0, 255, 0, 255,
                  (s32)(long)D_800D7288);

    for (index = 0; index < state->count; index++) {
        f32 distance;

        distance = cam[0];
        mode = D_800A4BA4[index];
        if (mode & 1) {
            func_8002D4C4(0x55);
            D_800A2540 = 1;
            func_800469B4(state, 3);
            return;
        }
        if ((mode & 2) && !(mode & 1)) {
            cam[0] = distance;
            func_8002D4C4(0x4D);
            D_800A2540 = 1;
            D_800A4BF0 = 0.0f;
            func_800469B4(state, 3);
            return;
        }

        previous = distance;
        if ((f64)D_800D7720[index] > 0.1 || (f64)D_800D7720[index] < -0.1) {
            if (flags[0] == 0) {
                cam[5] = (f32)((f64)cam[5] +
                                   (f64)(140.0f * D_80120BF8 *
                                         D_800D7720[index]) * 1.5);
                moved = 1;
            }
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
            flags[0] = 0;
        }

        gate = flags[0];
        if ((f64)D_800D7730[index] > 0.1 || (f64)D_800D7730[index] < -0.1) {
            if ((gate != 0) == 0) {
                pitch = (f32)((f64)cam[6] +
                              (f64)(45.0f * D_80120BF8 * D_800D7730[index]) *
                                  1.5);
                moved = 1;
                if (pitch > 89.0f) {
                    pitch = 89.0f;
                }
                cam[6] = pitch;
                if (pitch < -89.0f) {
                    cam[6] = -89.0f;
                }
            }
            gate = 0;
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
        }

        mode = D_800A4B94[index];
        if (mode & 4) {
            if ((gate != 0) == 0) {
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
        flags[0] = gate;
        cam[0] = distance;
        if (mode & 8) {
            flags[0] = 0;
            cam[0] = distance;
            if ((gate != 0) == 0) {
                distance = distance + 800.0f * D_80120BF8;
                cam[0] = distance;
                moved = 1;
                if (distance > 1336.0f) {
                    cam[0] = 1336.0f;
                }
            }
            if (D_800A4BF4 == 5.0f) {
                saturated = 1;
            }
        }

        if ((D_800A4B94[0] & 0x10) && D_800A4BC0 != 3) {
            state->mode = state->mode + 1;
            mode = state->mode;
            flags[0] = 0;
            stepped = 1;
            if (mode == 22) {
                if (D_800A31E4[state->entries[index] * 13] == 30) {
                    state->mode = mode + 4;
                    mode = state->mode;
                }
            }
            if (mode == 24) {
                if (D_800A31E4[state->entries[index] * 13] == 40) {
                    state->mode = mode + 2;
                    mode = state->mode;
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
            state->mode = state->mode - 1;
            mode = state->mode;
            flags[0] = 0;
            stepped = 1;
            if (mode == 25) {
                if (D_800A31E4[state->entries[index] * 13] == 30) {
                    mode = mode - 4;
                    state->mode = mode;
                }
            }
            if (mode == 25) {
                if (D_800A31E4[state->entries[index] * 13] != 40) {
                    state->mode = mode - 2;
                    mode = state->mode;
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
            pitch = cam[6];
            yaw = cam[5];
            func_8001745C(&matrix[0][0], yaw, pitch, 0.0f);
            distance = cam[0];
            func_800155EC(&D_80118D90, &D_80118E50, distance,
                          (PcVec3f *)&matrix[1][0]);
            if (D_80118D98 < -147.0f) {
                func_800155EC(&D_80118D90, &D_80118E50,
                              cam[0] *
                                  ((D_80118E58 - -147.0f) /
                                   (D_80118E58 - D_80118D98)),
                              (PcVec3f *)&matrix[1][0]);
            }
            if (1066.0f < D_80118D98) {
                func_800155EC(&D_80118D90, &D_80118E50,
                              cam[0] *
                                  ((D_80118E58 - 1066.0f) /
                                   (D_80118E58 - D_80118D98)),
                              (PcVec3f *)&matrix[1][0]);
            }
            distance = cam[0];
            if (distance != previous) {
                distance = func_80015470(&D_80118D90, &D_80118E50);
            }
            cam[0] = distance;
            if (moved) {
                func_800156DC(D_80118E60, D_80118E20);
            }
            moved = 0;
        }
    }

    if (saturated) {
        D_800A4BF4 = 0.0f;
        flags[0] = 0;
        func_8002AFFC(state, state->mode, 1);
        func_8001535C(&offset, &D_80118D90, &D_80118E50);
        cam[0] = func_800153C0(&offset);
        func_800154D0(&offset.x);
        cam[5] = func_80014F54(-offset.x, offset.y);
        pitch = func_80014D4C(offset.z);
        yaw = cam[5];
        if (yaw < 0.0f) {
            yaw = yaw + 360.0f;
        }
        cam[5] = yaw;
        if (yaw > 360.0f) {
            cam[5] = yaw - 360.0f;
        }
        if (pitch < -90.0f) {
            pitch = pitch + 180.0f;
        }
        cam[6] = pitch;
        if (pitch > 90.0f) {
            cam[6] = pitch - 180.0f;
        }
    }
}
