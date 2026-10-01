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


void func_800321F0(Obj800321F0 *object, s32 index, s32 channel, f32 step) {
    switch (index) {
    case 0:
            if (channel == 1) {
                object->f00 += 0.05f * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < 0.01f) {
                    object->f00 = 0.01f;
                }
            }
            if (channel == 2) {
                object->f00 += 0.1f * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < 0.01f) {
                    object->f00 = 0.01f;
                }
            }
            if (channel == 3) {
                object->f00 += 0.15f * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < 0.01f) {
                    object->f00 = 0.01f;
                }
            }
            if (channel == 4) {
                object->f00 += 0.2f * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < 0.01f) {
                    object->f00 = 0.01f;
                }
            }
            if (channel == 5) {
                object->f00 += 0.25f * step;
                if (object->f00 > 1.0f) {
                    object->f00 = 1.0f;
                }
                if (object->f00 < 0.01f) {
                    object->f00 = 0.01f;
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
            else if (channel == 3) {
                object->f04 += 348.0f * step;
                if (object->f04 > 1000.0f) {
                    object->f04 = 1000.0f;
                }
                if (object->f04 < 50.0f) {
                    object->f04 = 50.0f;
                }
            }
            else if (channel == 4) {
                object->f04 += 464.0f * step;
                if (object->f04 > 1000.0f) {
                    object->f04 = 1000.0f;
                }
                if (object->f04 < 50.0f) {
                    object->f04 = 50.0f;
                }
            }
            else if (channel == 5) {
                object->f04 += 578.0f * step;
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
                object->f0C = object->f0C * (0.86f + 0.13999999f * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < 0.1f) {
                    object->f0C = 0.1f;
                }
            }
            if (channel == 2) {
                object->f0C = object->f0C * (0.72f + 0.27999997f * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < 0.1f) {
                    object->f0C = 0.1f;
                }
            }
            if (channel == 3) {
                object->f0C = object->f0C * (0.58f + 0.42000002f * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < 0.1f) {
                    object->f0C = 0.1f;
                }
            }
            if (channel == 4) {
                object->f0C = object->f0C * (0.44f + 0.56f * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < 0.1f) {
                    object->f0C = 0.1f;
                }
            }
            if (channel == 5) {
                object->f0C = object->f0C * (0.3f + 0.7f * (1.0f - step));
                if (object->f0C > 5.0f) {
                    object->f0C = 5.0f;
                }
                if (object->f0C < 0.1f) {
                    object->f0C = 0.1f;
                }
            }
        break;
    case 3:
            if (channel == 1) {
                object->f10 += 40.0f * step;
                if (object->f10 > 650.0f) {
                    object->f10 = 650.0f;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
            if (channel == 2) {
                object->f10 += 80.0f * step;
                if (object->f10 > 650.0f) {
                    object->f10 = 650.0f;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
            if (channel == 3) {
                object->f10 += 120.0f * step;
                if (object->f10 > 650.0f) {
                    object->f10 = 650.0f;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
            if (channel == 4) {
                object->f10 += 160.0f * step;
                if (object->f10 > 650.0f) {
                    object->f10 = 650.0f;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
            if (channel == 5) {
                object->f10 += 200.0f * step;
                if (object->f10 > 650.0f) {
                    object->f10 = 650.0f;
                }
                if (object->f10 < 450.0f) {
                    object->f10 = 450.0f;
                }
            }
        break;
    case 4:
            if (channel == 1) {
                object->f14 = object->f14 * (0.92f + 0.07999998f * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
            if (channel == 2) {
                object->f14 = object->f14 * (0.83f + 0.17000002f * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
            if (channel == 3) {
                object->f14 = object->f14 * (0.74f + 0.26f * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
            if (channel == 4) {
                object->f14 = object->f14 * (0.65f + 0.35000002f * (1.0f - step));
                if (object->f14 > 1000.0f) {
                    object->f14 = 1000.0f;
                }
                if (object->f14 < 1.0f) {
                    object->f14 = 1.0f;
                }
            }
            if (channel == 5) {
                object->f14 = object->f14 * (0.56f + 0.44f * (1.0f - step));
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
                object->f24 += 1.6f * step;
                if (object->f24 > 20.0f) {
                    object->f24 = 20.0f;
                }
                if (object->f24 < 1.0f) {
                    object->f24 = 1.0f;
                }
            }
            if (channel == 2) {
                object->f24 += 3.2f * step;
                if (object->f24 > 20.0f) {
                    object->f24 = 20.0f;
                }
                if (object->f24 < 1.0f) {
                    object->f24 = 1.0f;
                }
            }
            if (channel == 3) {
                object->f24 += 4.8f * step;
                if (object->f24 > 20.0f) {
                    object->f24 = 20.0f;
                }
                if (object->f24 < 1.0f) {
                    object->f24 = 1.0f;
                }
            }
            if (channel == 4) {
                object->f24 += 6.4f * step;
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
                object->f2C += 0.1f * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
            if (channel == 2) {
                object->f2C += 0.2f * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
            if (channel == 3) {
                object->f2C += 0.3f * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
            if (channel == 4) {
                object->f2C += 0.4f * step;
                if (object->f2C > 1.0f) {
                    object->f2C = 1.0f;
                }
                if (object->f2C < 0.0f) {
                    object->f2C = 0.0f;
                }
            }
            if (channel == 5) {
                object->f2C += 0.45f * step;
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
