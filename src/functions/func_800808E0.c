/* Independently written from specs/func_800808E0.md. */

#include "podcruise/types.h"

typedef struct Obj800808E0 {
    /* 0x000 */ u8 unk000[0x50];
    /* 0x050 */ f32 unk050[3];
    /* 0x05C */ u8 unk05C[0xAC - 0x5C];
    /* 0x0AC */ u8 unk0AC[0x118 - 0xAC];
    /* 0x118 */ f32 unk118[3];
    /* 0x124 */ f32 unk124;
} Obj800808E0;

extern f32 D_800ADC6C;

extern void func_8003B02C(void *source, f32 *matrix);
extern void func_800155EC(f32 *output, f32 *base, f32 scale, f32 *direction);
extern f32 func_800153C0(const f32 *vector);

void func_800808E0(Obj800808E0 *object) {
    f32 dotA;
    f32 dotB;
    f32 spare;
    f32 point[3];
    f32 delta[3];
    f32 matrix[16];
    f32 inverse;

    func_8003B02C(&object->unk0AC, matrix);

    dotA = (object->unk050[0] * matrix[4] + object->unk050[1] * matrix[5]) +
           object->unk050[2] * matrix[6];
    dotB = (matrix[12] * matrix[4] + matrix[13] * matrix[5]) +
           matrix[14] * matrix[6];

    func_800155EC(point, &matrix[12], dotA - dotB, &matrix[4]);

    delta[0] = object->unk050[0] - point[0];
    delta[1] = object->unk050[1] - point[1];
    delta[2] = object->unk050[2] - point[2];

    object->unk124 = func_800153C0(delta);

    if (D_800ADC6C < object->unk124) {
        inverse = 1.0f / object->unk124;
        object->unk118[0] = delta[0] * inverse;
        object->unk118[1] = delta[1] * inverse;
        object->unk118[2] = delta[2] * inverse;
    } else {
        object->unk118[0] = 0.0f;
        object->unk118[1] = 0.0f;
        object->unk118[2] = 1.0f;
    }

    (void)spare;
}
