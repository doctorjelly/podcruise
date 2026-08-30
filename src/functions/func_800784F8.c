/* Independently written from specs/functions/recovered/func_800784F8.md. */
#include "podcruise/types.h"

typedef f32 Matrix800784F8[4][4];
typedef f32 Vector800784F8[3];

extern f32 D_800A5CA0[][27];
extern f32 D_800A5D00[][27];
extern f32 D_800ADAA0;
extern f32 D_800ADAA4;
extern f32 D_800ADAA8;
extern f32 D_800ADAAC;
extern f32 D_800ADAB0;
extern f32 D_800ADAB4;
extern f32 D_800ADAB8;
extern f32 D_800ADABC;
extern f32 D_800ADAC0;
extern f64 D_80120BF0;

extern u32 func_8000E8C4(void *object);
extern void func_8000E9BC(u8 **owner, s16 a, s16 b, s16 c, s16 d, s16 e,
                          s16 f);
extern void func_80015268(f32 *output, f32 x, f32 y, f32 z);
extern void func_80015288(f32 *output, const f32 *source);
extern void func_80015328(f32 *output, const f32 *left, const f32 *right);
extern void func_800156DC(Matrix800784F8 output,
                          const Matrix800784F8 source);
extern void func_80016BF4(f32 *output, const f32 *vector,
                          const Matrix800784F8 matrix);
extern void func_80017520(f32 *matrix, f32 x, f32 y, f32 z);
extern void func_80017BA8(void *destination, const void *source);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags,
                         s32 mode);
extern void func_8003E0A0(void *state, f32 step_u, f32 step_v);
extern void func_800738D4(void *craft, s32 mode, f32 *from, f32 *to);
extern void func_80075FC4(Matrix800784F8 first, Matrix800784F8 second,
                          f32 spread_a, f32 spread_b, s32 index,
                          Matrix800784F8 output);
extern void func_80077C94(void *craft, Matrix800784F8 source, f32 scale_x,
                          f32 scale_y, f32 scale_z, f32 angle, s32 mode);
extern void func_800834F0(void *node, f32 *first, f32 *second, f32 scale,
                          f32 amplitude, f32 age, f32 lifetime, s32 mode);

#define FIELD(type, base, offset) (*(type *)((u8 *)(base) + (offset)))
#define POINTER(base, offset) FIELD(void *, base, offset)
#define MATRIX(base, offset) ((Matrix800784F8 *)((u8 *)(base) + (offset)))
#define CLAMP(value, low, high) \
    ((value) < (low) ? (low) : ((value) > (high) ? (high) : (value)))

void func_800784F8(void *craft) {
    void *attached;
    void *kind;
    s32 type;
    s32 special_type;
    s32 paired_attachment;
    s32 effect_mode;
    s32 timer;
    s32 i;
    u32 scroll_a;
    u32 scroll_b;
    f32 heat;
    f32 velocity;
    f32 heat_level;
    f32 negative_velocity;
    f32 positive_velocity;
    f32 activity_a;
    f32 activity_b;
    f32 factor_a;
    f32 factor_b;
    f32 blend_a;
    f32 blend_b;
    f32 intensity_a;
    f32 intensity_b;
    f32 heat_scale;
    f32 red_a;
    f32 green_a;
    f32 blue_a;
    f32 red_b;
    f32 green_b;
    f32 blue_b;
    f32 scale;
    f32 response;
    f32 longitudinal_scale;
    Vector800784F8 first_point;
    Vector800784F8 second_point;
    Vector800784F8 offset;
    Vector800784F8 zero_a;
    Vector800784F8 zero_b;
    Matrix800784F8 local_matrix;
    Matrix800784F8 exhaust_matrix;
    Matrix800784F8 *matrix_a;
    Matrix800784F8 *matrix_b;
    Matrix800784F8 *output;

    attached = POINTER(craft, 0x344);
    if (attached == 0) {
        return;
    }

    if (POINTER(attached, 0xEC) != 0) {
        func_800181BC(POINTER(attached, 0xEC), 2, 3, 0x10, 2);
    }
    func_800156DC(local_matrix, *MATRIX(craft, 0x20));

    kind = POINTER(craft, 0x1E70);
    type = **(s32 **)((u8 *)kind + 0x18);
    special_type = type == 14;
    paired_attachment =
        (FIELD(s32, attached, 0x0C) != 0) &&
        (FIELD(s32, attached, 0x10) != 0);

    matrix_a = MATRIX(craft, 0x390);
    matrix_b = MATRIX(craft, 0x3D0);
    if (!special_type) {
        func_80015288(first_point, (*matrix_a)[3]);
        func_80015288(offset, &D_800A5CA0[type][15]);
        offset[0] = -offset[0];
        func_80016BF4(offset, offset, *matrix_a);
        func_80015328(first_point, offset, first_point);

        if (paired_attachment) {
            func_80015288(second_point, (*MATRIX(craft, 0x450))[3]);
            func_80015288(offset, &D_800A5CA0[type][15]);
            func_80016BF4(offset, offset, *MATRIX(craft, 0x450));
            func_80015328(second_point, offset, second_point);
            first_point[2] += FIELD(f32, craft, 0x250);
            second_point[2] += FIELD(f32, craft, 0x250);
            func_800738D4(craft, 2, first_point, second_point);

            func_80015288(first_point, (*MATRIX(craft, 0x410))[3]);
            func_80015288(offset, &D_800A5CA0[type][15]);
            offset[0] = -offset[0];
            func_80016BF4(offset, offset, *MATRIX(craft, 0x410));
            func_80015328(first_point, offset, first_point);
        }

        func_80015288(second_point, (*matrix_b)[3]);
        func_80015288(offset, &D_800A5CA0[type][15]);
        func_80016BF4(offset, offset, *matrix_b);
        func_80015328(second_point, offset, second_point);
        first_point[2] += FIELD(f32, craft, 0x250);
        second_point[2] += FIELD(f32, craft, 0x250);
        func_800738D4(craft, 1, first_point, second_point);
    }

    heat = CLAMP(FIELD(f32, craft, 0x1A0) * D_800ADAA0, 0.0f, 1.0f);
    velocity = CLAMP(FIELD(f32, craft, 0x1EC) / 60.0f, -1.0f, 1.0f);

    attached = POINTER(craft, 0x344);
    scroll_a = func_8000E8C4(POINTER(attached, 0x114));
    scroll_b = func_8000E8C4(POINTER(attached, 0x118));

    func_800156DC(exhaust_matrix, *matrix_a);
    func_80015288(offset, &D_800A5CA0[type][21]);
    func_80016BF4(offset, offset, exhaust_matrix);
    exhaust_matrix[3][0] += offset[0];
    exhaust_matrix[3][1] += offset[1];
    exhaust_matrix[3][2] += offset[2];
    exhaust_matrix[1][0] = (*matrix_a)[2][0];
    exhaust_matrix[1][1] = (*matrix_a)[2][1];
    exhaust_matrix[1][2] = (*matrix_a)[2][2];
    exhaust_matrix[2][0] = (*matrix_a)[1][0];
    exhaust_matrix[2][1] = (*matrix_a)[1][1];
    exhaust_matrix[2][2] = (*matrix_a)[1][2];
    output = MATRIX(craft, 0x1410);
    func_800156DC(*output, exhaust_matrix);
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x10C) != 0) {
        func_800181BC(POINTER(attached, 0x10C), 2, 3, 0x10, 2);
    }
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x10C) != 0) {
        func_80017BA8(POINTER(attached, 0x10C), output);
    }

    func_800156DC(exhaust_matrix, *matrix_b);
    func_80015288(offset, &D_800A5CA0[type][21]);
    offset[0] *= -1.0f;
    func_80016BF4(offset, offset, exhaust_matrix);
    exhaust_matrix[3][0] += offset[0];
    exhaust_matrix[3][1] += offset[1];
    exhaust_matrix[3][2] += offset[2];
    exhaust_matrix[1][0] = (*matrix_b)[2][0];
    exhaust_matrix[1][1] = (*matrix_b)[2][1];
    exhaust_matrix[1][2] = (*matrix_b)[2][2];
    exhaust_matrix[2][0] = (*matrix_b)[1][0];
    exhaust_matrix[2][1] = (*matrix_b)[1][1];
    exhaust_matrix[2][2] = (*matrix_b)[1][2];
    output = MATRIX(craft, 0x1450);
    func_800156DC(*output, exhaust_matrix);
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x110) != 0) {
        func_800181BC(POINTER(attached, 0x110), 2, 3, 0x10, 2);
    }
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x110) != 0) {
        func_80017BA8(POINTER(attached, 0x110), output);
    }

    scale = D_800A5D00[type][0] * D_800ADAA4;
    longitudinal_scale = -((heat * 3.0f + 9.0f) * D_800ADAA4);
    func_80017520((f32 *)MATRIX(craft, 0x1490), scale, scale,
                  longitudinal_scale);
    func_80017520((f32 *)MATRIX(craft, 0x14D0), scale, scale,
                  longitudinal_scale);
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x114) != 0) {
        func_80017BA8(POINTER(attached, 0x114), MATRIX(craft, 0x1490));
    }
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x118) != 0) {
        func_80017BA8(POINTER(attached, 0x118), MATRIX(craft, 0x14D0));
    }

    heat_level = CLAMP(heat * 255.0f, 1.0f, 50.0f);
    negative_velocity = -velocity;
    if (negative_velocity < 0.0f) {
        negative_velocity = 0.0f;
    }
    intensity_a = (1.0f - negative_velocity * D_800ADAA8) * heat_level;
    if (intensity_a < 1.0f) {
        intensity_a = 1.0f;
    }
    positive_velocity = velocity;
    if (positive_velocity < 0.0f) {
        positive_velocity = 0.0f;
    }
    intensity_b = (1.0f - positive_velocity * D_800ADAA8) * heat_level;
    if (intensity_b < 1.0f) {
        intensity_b = 1.0f;
    }

    activity_a = 1.0f - FIELD(f32, craft, 0x218) / 100.0f;
    activity_b = activity_a;
    for (i = 0; i < 3; i++) {
        if (activity_a < FIELD(f32, craft, 0x288 + i * 4)) {
            activity_a = FIELD(f32, craft, 0x288 + i * 4);
        }
        if (activity_b < FIELD(f32, craft, 0x294 + i * 4)) {
            activity_b = FIELD(f32, craft, 0x294 + i * 4);
        }
        if (FIELD(s32, craft, 0x2A0 + i * 4) & 8) {
            activity_a = 1.0f;
        }
        if (FIELD(s32, craft, 0x2AC + i * 4) & 8) {
            activity_b = 1.0f;
        }
    }

    factor_a = CLAMP(2.0f * (activity_a - 0.5f), 0.0f, 1.0f);
    factor_b = CLAMP(2.0f * (activity_b - 0.5f), 0.0f, 1.0f);
    blend_a = factor_a * 4.0f;
    if (blend_a > 1.0f) {
        blend_a = 1.0f;
    }
    blend_b = factor_b * 4.0f;
    if (blend_b > 1.0f) {
        blend_b = 1.0f;
    }

    red_a = (0.0f - 255.0f) * blend_b + 255.0f;
    green_a = (0.0f - 255.0f) * blend_b + 255.0f;
    blue_a = (0.0f - 255.0f) * blend_b + 255.0f;
    intensity_a += (240.0f - intensity_a) * factor_b;
    red_b = (0.0f - 255.0f) * blend_a + 255.0f;
    green_b = (0.0f - 255.0f) * blend_a + 255.0f;
    blue_b = (0.0f - 255.0f) * blend_a + 255.0f;
    intensity_b += (240.0f - intensity_b) * factor_a;

    heat_scale = CLAMP(FIELD(f32, craft, 0x1A0) / 50.0f, 0.0f, 1.0f);
    intensity_a *= heat_scale;
    intensity_b *= heat_scale;
    if (FIELD(s32, craft, 0x64) & 0x4000) {
        red_a = 0.0f;
        green_a = 0.0f;
        blue_a = 0.0f;
        red_b = 0.0f;
        green_b = 0.0f;
        blue_b = 0.0f;
    }

    red_a = CLAMP(red_a, 0.0f, 255.0f);
    green_a = CLAMP(green_a, 0.0f, 255.0f);
    blue_a = CLAMP(blue_a, 0.0f, 255.0f);
    intensity_a = CLAMP(intensity_a, 1.0f, 254.0f);
    red_b = CLAMP(red_b, 0.0f, 255.0f);
    green_b = CLAMP(green_b, 0.0f, 255.0f);
    blue_b = CLAMP(blue_b, 0.0f, 255.0f);
    intensity_b = CLAMP(intensity_b, 1.0f, 254.0f);

    if (scroll_a != 0) {
        func_8000E9BC((u8 **)(unsigned long)scroll_a, 0, 0, (s16)red_a,
                      (s16)green_a, (s16)blue_a, (s16)intensity_a);
        func_8003E0A0((void *)(unsigned long)scroll_a, 0.0f,
                      (heat * 3.5f + 0.5f) * (f32)D_80120BF0);
    }
    if (scroll_b != 0) {
        func_8000E9BC((u8 **)(unsigned long)scroll_b, 0, 0, (s16)red_b,
                      (s16)green_b, (s16)blue_b, (s16)intensity_b);
        func_8003E0A0((void *)(unsigned long)scroll_b, 0.0f,
                      (heat * 3.5f + 0.5f) * (f32)D_80120BF0);
    }

    effect_mode = (FIELD(s32, craft, 0x60) & 0x80) != 0;
    func_80077C94(craft, *MATRIX(craft, 0x1310), 0.1f, D_800ADAAC,
                  D_800ADAAC, 10.0f, effect_mode);
    func_80077C94(craft, *MATRIX(craft, 0x12D0), D_800ADAB0, -0.1f,
                  D_800ADAB0, 10.0f, effect_mode);

    timer = FIELD(s32, craft, 0x1998);
    attached = POINTER(craft, 0x344);
    if (special_type || timer >= 76 || attached == 0) {
        if (POINTER(attached, 0x28) != 0) {
            func_800181BC(POINTER(attached, 0x28), 2, (u32)-4, 0x10, 3);
        }
        if (POINTER(attached, 0x2C) != 0) {
            func_800181BC(POINTER(attached, 0x2C), 2, (u32)-4, 0x10, 3);
        }
        return;
    }

    if (POINTER(attached, 0x28) != 0) {
        output = MATRIX(craft, 0x5D0);
        func_80075FC4(*MATRIX(craft, 0x490), *matrix_a, 1.0f, 1.0f,
                      type, *output);
        (*output)[3][2] += FIELD(f32, craft, 0x250);
        func_80017BA8(POINTER(POINTER(craft, 0x344), 0x28), output);
    }
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x2C) != 0) {
        output = MATRIX(craft, 0x610);
        func_80075FC4(*MATRIX(craft, 0x490), *matrix_b, -1.0f, 1.0f,
                      type, *output);
        (*output)[3][2] += FIELD(f32, craft, 0x250);
        func_80017BA8(POINTER(POINTER(craft, 0x344), 0x2C), output);
    }
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x30) != 0) {
        output = MATRIX(craft, 0x650);
        func_80075FC4(*MATRIX(craft, 0x490), *MATRIX(craft, 0x410),
                      1.0f, -1.0f, type, *output);
        (*output)[3][2] += FIELD(f32, craft, 0x250);
        func_80017BA8(POINTER(POINTER(craft, 0x344), 0x30), output);
    }
    attached = POINTER(craft, 0x344);
    if (POINTER(attached, 0x34) != 0) {
        output = MATRIX(craft, 0x690);
        func_80075FC4(*MATRIX(craft, 0x490), *MATRIX(craft, 0x450),
                      -1.0f, -1.0f, type, *output);
        (*output)[3][2] += FIELD(f32, craft, 0x250);
        func_80017BA8(POINTER(POINTER(craft, 0x344), 0x34), output);
    }

    timer = FIELD(s32, craft, 0x1998);
    if (timer < 51 && POINTER(craft, 0x344) != 0 &&
        !(FIELD(s32, craft, 0x64) & 0x01000000)) {
        FIELD(s32, craft, 0x64) |= 0x01000000;
        func_80015268(zero_a, 0.0f, 0.0f, 0.0f);
        func_80015268(zero_b, 0.0f, 0.0f, 0.0f);
        response = FIELD(f32, craft, 0x1EC) * D_800ADAB8;
        scale = D_800ADAB4;
        if ((f64)response > 1.0) {
            scale = D_800ADAB4 * response;
        }
        if ((f64)scale > 1.0) {
            scale = 1.0f;
        }
        attached = POINTER(craft, 0x344);
        func_800834F0(POINTER(attached, 0x28), zero_a, zero_b, scale, 1.0f,
                      (f32)timer, 50.0f, 0);

        func_80015268(zero_a, 0.0f, 0.0f, 0.0f);
        func_80015268(zero_b, 0.0f, 0.0f, 0.0f);
        response = FIELD(f32, craft, 0x1EC) * D_800ADABC;
        scale = D_800ADAB4;
        if ((f64)response > 1.0) {
            scale = D_800ADAC0 * response;
        }
        if ((f64)scale > 1.0) {
            scale = 1.0f;
        }
        attached = POINTER(craft, 0x344);
        func_800834F0(POINTER(attached, 0x2C), zero_a, zero_b, scale, 1.0f,
                      (f32)timer, 50.0f, 0);
    }
}

#undef MATRIX
#undef POINTER
#undef FIELD
#undef CLAMP
