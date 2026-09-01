/* Independently written from specs/functions/recovered/func_8002D4C4.md. */

#include "podcruise/types.h"

extern u8 D_80113685;

extern void func_80008B14(s32, s16, f32, f32, s32);

void func_8002D4C4(s32 kind) {
    f32 intensity;
    f32 scale;
    s32 emphasized;

    scale = 0.125f;
    emphasized = 0;
    intensity = (f32)D_80113685 / 255.0f;

    switch (kind) {
    case 0x4B:
        scale = 0.5f;
        emphasized = 1;
        break;
    case 0x4D:
        scale = 0.25f;
        break;
    case 0x57:
        scale = 0.25f;
        intensity = (f32)((f64)intensity * 0.75);
        break;
    case 0x4F:
        emphasized = 1;
        break;
    case 0x4C:
    case 0x4E:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    default:
        break;
    }

    func_80008B14(kind, 6, scale, intensity, emphasized);
}
