/* Independently written from specs/functions/recovered/func_8002D4C4.md. */

#include "podcruise/types.h"

extern u8 D_80113685;

extern void func_80008B14(s32, s16, f32, f32, s32);

void func_8002D4C4(s32 kind) {
    f32 intensity;
    f32 scale;
    s32 emphasized;

    intensity = (f32)D_80113685 / 255.0f;
    scale = 1.0f;
    emphasized = 0;

    switch (kind) {
    case 0x4B:
        scale = 0.5f;
        emphasized = 1;
        break;
    case 0x4D:
        scale = 0.25f;
        break;
    case 0x4F:
        emphasized = 1;
        break;
    case 0x57:
        scale = 0.25f;
        intensity = (f32)((f64)intensity * 1.5);
        break;
    }

    func_80008B14(kind, 6, scale, intensity, emphasized);
}
