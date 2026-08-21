/* Independently written from specs/functions/recovered/medium_control_math_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    f32 f00;
    f32 f04;
    u8 pad08[0x4];
    f32 f0C;
    f32 f10;
    f32 f14;
    u8 pad18[0xC];
    f32 f24;
    u8 pad28[0x4];
    f32 f2C;
} Obj800321F0;

extern f32 D_800AA3C8;
extern f32 D_800AA3CC;
extern f32 D_800AA3D0;
extern f32 D_800AA3D4;
extern f32 D_800AA3D8;
extern f32 D_800AA3DC;
extern f32 D_800AA3E0;
extern f32 D_800AA3E4;
extern f32 D_800AA3E8;
extern f32 D_800AA3EC;
extern f32 D_800AA3F0;
extern f32 D_800AA3F4;
extern f32 D_800AA3F8;
extern f32 D_800AA3FC;
extern f32 D_800AA400;
extern f32 D_800AA404;
extern f32 D_800AA408;
extern f32 D_800AA40C;
extern f32 D_800AA410;
extern f32 D_800AA414;
extern f32 D_800AA418;
extern f32 D_800AA41C;
extern f32 D_800AA420;
extern f32 D_800AA424;
extern f32 D_800AA428;
extern f32 D_800AA42C;
extern f32 D_800AA430;
extern f32 D_800AA434;
extern f32 D_800AA438;
extern f32 D_800AA43C;
extern f32 D_800AA440;
extern f32 D_800AA444;
extern f32 D_800AA448;
extern f32 D_800AA44C;
extern f32 D_800AA450;
extern f32 D_800AA454;
extern f32 D_800AA458;
extern f32 D_800AA45C;
extern f32 D_800AA460;
extern f32 D_800AA464;

void func_800321F0(Obj800321F0 *object, s32 index, s32 channel, f32 step) {
    switch (index) {
    case 0:
            if (channel == 1) {
                object->f00 += D_800AA3C8 * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < D_800AA3CC) {
                    object->f00 = D_800AA3CC;
                }
            }
            if (channel == 2) {
                object->f00 += D_800AA3D4 * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < D_800AA3D0) {
                    object->f00 = D_800AA3D0;
                }
            }
            if (channel == 3) {
                object->f00 += D_800AA3D8 * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < D_800AA3D0) {
                    object->f00 = D_800AA3D0;
                }
            }
            if (channel == 4) {
                object->f00 += D_800AA3DC * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < D_800AA3D0) {
                    object->f00 = D_800AA3D0;
                }
            }
            if (channel == 5) {
                object->f00 += 0.25f * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < D_800AA3D0) {
                    object->f00 = D_800AA3D0;
                }
            }
        break;
    case 1:
            if (channel == 1) {
                object->f04 += 116.0f * step;
                if (object->f04 > 1000.0f) {
                    object->f04 = 1000.0f;
                }
                if (object->f04 < 50.0f) {
                    object->f04 = 50.0f;
                }
            }
            if (channel == 2) {
                object->f04 += 232.0f * step;
                if (object->f04 > 1000.0f) {
                    object->f04 = 1000.0f;
                }
                if (object->f04 < 50.0f) {
                    object->f04 = 50.0f;
                }
            }
            if (channel == 3) {
                object->f04 += 348.0f * step;
                if (object->f04 > 1000.0f) {
                    object->f04 = 1000.0f;
                }
                if (object->f04 < 50.0f) {
                    object->f04 = 50.0f;
                }
            }
            if (channel == 4) {
                object->f04 += 464.0f * step;
                if (object->f04 > 1000.0f) {
                    object->f04 = 1000.0f;
                }
                if (object->f04 < 50.0f) {
                    object->f04 = 50.0f;
                }
            }
            if (channel == 5) {
                object->f04 += D_800AA3E0 * step;
                if (object->f04 > 1000.0f) {
                    object->f04 = 1000.0f;
                }
                if (object->f04 < 50.0f) {
                    object->f04 = 50.0f;
                }
            }
        break;
    case 2:
            if (channel == 1) {
                object->f0C = object->f0C * (D_800AA3E8 + D_800AA3E4 * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < D_800AA3EC) {
                    object->f0C = D_800AA3EC;
                }
            }
            if (channel == 2) {
                object->f0C = object->f0C * (D_800AA3F8 + D_800AA3F4 * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < D_800AA3F0) {
                    object->f0C = D_800AA3F0;
                }
            }
            if (channel == 3) {
                object->f0C = object->f0C * (D_800AA400 + D_800AA3FC * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < D_800AA3F0) {
                    object->f0C = D_800AA3F0;
                }
            }
            if (channel == 4) {
                object->f0C = object->f0C * (D_800AA408 + D_800AA404 * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < D_800AA3F0) {
                    object->f0C = D_800AA3F0;
                }
            }
            if (channel == 5) {
                object->f0C = object->f0C * (D_800AA410 + D_800AA40C * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < D_800AA3F0) {
                    object->f0C = D_800AA3F0;
                }
            }
        break;
    case 3:
            if (channel == 1) {
                object->f10 += 40.0f * step;
                if (object->f10 > D_800AA414) {
                    object->f10 = D_800AA414;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
            if (channel == 2) {
                object->f10 += 80.0f * step;
                if (object->f10 > D_800AA418) {
                    object->f10 = D_800AA418;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
            if (channel == 3) {
                object->f10 += 120.0f * step;
                if (object->f10 > D_800AA418) {
                    object->f10 = D_800AA418;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
            if (channel == 4) {
                object->f10 += 160.0f * step;
                if (object->f10 > D_800AA418) {
                    object->f10 = D_800AA418;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
            if (channel == 5) {
                object->f10 += 200.0f * step;
                if (object->f10 > D_800AA418) {
                    object->f10 = D_800AA418;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
        break;
    case 4:
            if (channel == 1) {
                object->f14 = object->f14 * (D_800AA420 + D_800AA41C * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
            if (channel == 2) {
                object->f14 = object->f14 * (D_800AA428 + D_800AA424 * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
            if (channel == 3) {
                object->f14 = object->f14 * (D_800AA430 + D_800AA42C * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
            if (channel == 4) {
                object->f14 = object->f14 * (D_800AA438 + D_800AA434 * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
            if (channel == 5) {
                object->f14 = object->f14 * (D_800AA440 + D_800AA43C * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
        break;
    case 5:
            if (channel == 1) {
                object->f24 += D_800AA444 * step;
                if (object->f24 > 20.0f) {
                    object->f24 = 20.0f;
                }
                if (object->f24 < 1.0f) {
                    object->f24 = 1.0f;
                }
            }
            if (channel == 2) {
                object->f24 += D_800AA448 * step;
                if (object->f24 > 20.0f) {
                    object->f24 = 20.0f;
                }
                if (object->f24 < 1.0f) {
                    object->f24 = 1.0f;
                }
            }
            if (channel == 3) {
                object->f24 += D_800AA44C * step;
                if (object->f24 > 20.0f) {
                    object->f24 = 20.0f;
                }
                if (object->f24 < 1.0f) {
                    object->f24 = 1.0f;
                }
            }
            if (channel == 4) {
                object->f24 += D_800AA450 * step;
                if (object->f24 > 20.0f) {
                    object->f24 = 20.0f;
                }
                if (object->f24 < 1.0f) {
                    object->f24 = 1.0f;
                }
            }
            if (channel == 5) {
                object->f24 += 8.0f * step;
                if (object->f24 > 20.0f) {
                    object->f24 = 20.0f;
                }
                if (object->f24 < 1.0f) {
                    object->f24 = 1.0f;
                }
            }
        break;
    case 6:
            if (channel == 1) {
                object->f2C += D_800AA454 * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
            if (channel == 2) {
                object->f2C += D_800AA458 * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
            if (channel == 3) {
                object->f2C += D_800AA45C * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
            if (channel == 4) {
                object->f2C += D_800AA460 * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
            if (channel == 5) {
                object->f2C += D_800AA464 * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
        break;
    }
}
