/* Independently written from specs/functions/recovered/func_80020030.md. */
#include "podcruise/types.h"

typedef f32 Matrix80020030[4][4];
typedef f32 Vector80020030[3];

typedef struct {
    Vector80020030 position;
    Vector80020030 rotation;
} TransformInput80020030;

extern s32 D_800A2190;
extern s32 D_800A2194;
extern s32 D_800A21B0;
extern s32 D_800A2530;
extern s32 D_800A2534;
extern s32 D_800A2538;
extern f32 D_800A253C;
extern u8 D_800A31E0[];
extern s32 D_800A4BBC;
extern f32 D_800A4BF0;
extern u8 D_800A4C00[];
extern f32 D_800A4FC0[3];
extern f32 D_800A4FCC[3];
extern f32 D_800A9C40;
extern f32 D_800A9C44;
extern f64 D_800A9C48;
extern f64 D_800A9C50;
extern f64 D_800A9C58;
extern f64 D_800A9C60;
extern f32 D_800A9C68;
extern f32 D_800A9C6C;
extern f32 D_800A9C70;
extern f32 D_800A9C74;
extern f32 D_800A9C78;
extern u8 D_800D6C20[];
extern f32 D_800D6D90[];
extern f32 D_800D6DB4;
extern f32 D_800D6DC0[];
extern s16 D_800D7170[];
extern u8 D_800D7178[];
extern f32 D_800D7218[];
extern f32 D_800D7248[];
extern u8 D_80113E7C;
extern f32 D_801195F0[3];
extern void **D_8011A508[];
extern void **D_8011A544;
extern f32 D_80120BF8;

extern f32 func_80014F54(f32 first, f32 second);
extern void func_80015268(f32 *output, f32 x, f32 y, f32 z);
extern void func_80015288(f32 *output, f32 *source);
extern void func_8001745C(f32 *matrix, f32 first, f32 second, f32 third);
extern void func_800174B8(f32 *matrix, f32 *source);
extern void func_80017918(Matrix80020030 destination, f32 x, f32 y, f32 z,
                          Matrix80020030 source);
extern void func_80017BA8(void *destination, const void *source);
extern void func_80017C18(void *source, Matrix80020030 destination);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags,
                         s32 mode);
extern void func_80018480(void *object, Matrix80020030 matrix, s32 mode,
                          f32 x, f32 y, f32 z, f32 depth, s32 flag,
                          f32 scale_a, f32 scale_b);
extern void func_80021294(void *state);
extern void func_80021F84(void *state);
extern void func_80033878(void *node, f32 *position);
extern void *func_8003F800(u32 tag, s32 index);
extern void func_80048A50(s32 state);
extern f32 func_80051934(void);
extern void func_80063084(s32 index, s32 mode, f32 *first, f32 *second,
                          f32 first_angle, f32 second_angle);
extern s32 func_80082BE0(void);
extern void func_80084A3C(s32 first_resource, s32 second_resource,
                          f32 *position, s32 limit, s32 record,
                          f32 *first_output, f32 *second_output);
extern void func_80084BDC(f32 *first, f32 *second, void *record,
                          f32 *first_input, f32 *second_input);

#define FIELD(type, base, offset) (*(type *)((u8 *)(base) + (offset)))
#define POINTER_VALUE(pointer) ((s32)(unsigned long)(pointer))

void func_80020030(void *state) {
    Matrix80020030 placement_matrix;
    Matrix80020030 resource_matrix;
    Vector80020030 position;
    Vector80020030 projected;
    Vector80020030 auxiliary;
    TransformInput80020030 node_transform;
    f32 scale_a;
    f32 scale_b;
    f32 first_angle;
    f32 second_angle;
    f32 vertical;
    f64 bound_vertical;
    f32 random_value;
    f32 sign;
    f32 generated_x;
    f32 generated_y;
    f32 *placement;
    f32 *target;
    void **resources;
    void *node;
    void *item;
    u8 *record;
    f32 *first_data;
    f32 *second_data;
    s32 selected_resource;
    s32 left_resource;
    s32 right_resource;
    s32 random_word;
    s32 mode;
    s32 attempt;
    s32 i;
    s32 j;
    s16 candidate;

    scale_a = D_800A9C40;
    scale_b = D_800A9C44;

    if (FIELD(u8, state, 0x60) == 0) {
        FIELD(u8, state, 0x60) = 1;
        return;
    }

    mode = FIELD(s32, state, 0x08);
    if ((mode != 3) && (mode != 8)) {
        return;
    }

    if (D_800A4BBC != 0) {
        D_800A2538 = -1;
    }

    for (i = 0; i < FIELD(s8, state, 0x70); i++) {
        if (D_8011A508[i + 15] != 0) {
            placement = (f32 *)(D_800D6C20 + i * 0x28);
            placement[1] = (f32)(0.0 - (f64)(f32)i * D_800A9C48);
            placement[2] =
                50.0f + (f32)(D_800A31E0[
                                   FIELD(s8, state, 0x72 + i) * 0x34 + 0x24] *
                               10);

            func_8001745C((f32 *)placement_matrix, 0.0f, 0.0f, 0.0f);
            func_80015268(placement_matrix[3], placement[0], placement[1],
                          placement[2]);

            if (D_800A2538 != -1) {
                item = func_8003F800(0x456C6D6F, D_800A2538);
                mode = FIELD(s32, item, 0x14);
                if ((mode == 13) || (mode == 15)) {
                    D_800A253C =
                        (f32)((f64)D_800A253C - (f64)D_80120BF8);
                } else if (mode == 14) {
                    D_800A253C = (f32)((f64)D_800A253C +
                                      D_800A9C58 +
                                      D_800A9C50 *
                                          (f64)((f32)func_80082BE0() /
                                                2147483648.0f));
                }

                if ((f64)D_800A253C < D_800A9C60) {
                    D_800A253C = D_800A9C68;
                }
                if ((f64)D_800A253C > 1.5) {
                    D_800A253C = 1.5f;
                }
                if (D_800A2534 == 2) {
                    scale_a = D_800A253C;
                } else {
                    scale_b = D_800A253C;
                }
            }

            func_80018480(D_8011A508[i + 15], placement_matrix, 0, 70.0f,
                          70.0f, 70.0f, -157.0f, 1, scale_a, scale_b);
        }
    }

    for (i = 0; i < 4; i++) {
        node = D_8011A508[i + 85][0];
        if (node != 0) {
            func_800181BC(node, 2, (u32)-4, 0x10, 3);
            func_80015268(node_transform.position, D_800A9C70,
                          (f32)(i * 100 - 522), -157.0f);
            func_80015268(node_transform.rotation, 0.0f, 0.0f, 0.0f);
            if (i == 3) {
                func_80015268(node_transform.position, D_800A9C70,
                              D_800A9C6C, -103.0f);
                func_80015268(node_transform.rotation, 0.0f, 45.0f, 0.0f);
            }
            func_800174B8((f32 *)resource_matrix, node_transform.position);
            func_80017918(resource_matrix, 0.5f, 0.5f, 0.5f,
                          resource_matrix);
            func_80017BA8(node, resource_matrix);
            func_800181BC(node, 2, 3, 0x10, 2);
        }
    }

    if ((D_800A4BBC != 0) && (FIELD(s32, state, 0x3C) != 2)) {
        for (i = 0; i < FIELD(s8, state, 0x70); i++) {
            func_80015288(position, D_800A4FC0);
            position[2] = -157.0f;
            func_80015288(D_801195F0, D_800A4FCC);
            D_801195F0[1] -= (f32)(i * 2500);
            first_angle =
                func_80014F54(position[0] - FIELD(f32, D_800A4C00, 0x3CC),
                              FIELD(f32, D_800A4C00, 0x3D0) - position[1]);
            target = (f32 *)(D_800A4C00 + FIELD(s32, state, 0x34) * 0x20);
            second_angle = func_80014F54(D_801195F0[0] - target[3],
                                         target[4] - D_801195F0[1]);
            func_80063084(i + 28, 20, position, D_801195F0, first_angle,
                          second_angle);
        }

        D_800D7170[0] =
            (s16)(s32)(((f32)func_80082BE0() / 2147483648.0f) * 4.0f);
        for (i = 1; i < 4; i++) {
            do {
                candidate = (s16)(s32)(((f32)func_80082BE0() /
                                        2147483648.0f) *
                                       4.0f);
                for (j = 0; j < i; j++) {
                    if (candidate == D_800D7170[j]) {
                        candidate = -1;
                    }
                }
            } while (candidate == -1);
            D_800D7170[i] = candidate;
        }

        resources = D_8011A544;
        D_800A2190 = 1;
        D_800A2194 = 2;
        left_resource = 0x11;
        right_resource = 0x1F;
        if (resources[1] == 0) {
            D_800A2190 = 5;
            left_resource = 0x2D;
        }
        if (resources[D_800A2194] == 0) {
            D_800A2194 = 5;
            right_resource = 0x2D;
        }

        for (i = 0; i < (s32)D_80113E7C; i++) {
            record = D_800D7178 + i * 0x28;
            first_data = D_800D7218 + i * 3;
            second_data = D_800D7248 + i * 3;
            mode = D_800D7170[i];

            switch (mode) {
            case 0:
                attempt = 0;
                do {
                    bound_vertical = (2.0 * (f64)D_800D6DC0[1] +
                                      (f64)D_800D6DC0[4]) /
                                     3.0;
                    random_value =
                        (f32)func_80082BE0() / 2147483648.0f;
                    generated_y =
                        (f32)((f64)random_value *
                                  ((f64)D_800D6DC0[4] - bound_vertical) +
                              bound_vertical);
                    random_word = func_80082BE0();
                    sign = func_80051934();
                    generated_x =
                        sign * (D_800D6DC0[0] +
                                (D_800D6DC0[3] - D_800D6DC0[0]) *
                                    ((f32)random_word / 2147483648.0f));
                    func_80015268(position, generated_x, generated_y,
                                  -157.0f);

                    if (position[0] < 0.0f) {
                        D_800A2534 = D_800A2194;
                        selected_resource = left_resource;
                    } else {
                        D_800A2534 = D_800A2190;
                        selected_resource = right_resource;
                    }
                    D_800A2530 = selected_resource;
                    func_80084A3C(POINTER_VALUE(resources[0]),
                                  POINTER_VALUE(resources[selected_resource]),
                                  position, 10, POINTER_VALUE(record),
                                  first_data, second_data);
                    func_80084BDC(projected, auxiliary, record, first_data,
                                  second_data);
                    if ((projected[2] - 90.0f - 32.0f) <= -157.0f) {
                        attempt++;
                    } else {
                        break;
                    }
                } while (attempt < 20);

                func_80017C18(resources[D_800A2534], resource_matrix);
                func_80015288(position, projected);
                first_angle =
                    func_80014F54(position[0] - resource_matrix[3][0],
                                  resource_matrix[3][1] - position[1]);
                func_80063084(i + 52, 14, position, position, first_angle,
                              first_angle);
                D_800A2538 = i + 52;
                break;

            case 1:
                func_80017C18(resources[5], resource_matrix);
                sign = func_80051934();
                random_value =
                    (f32)func_80082BE0() / 2147483648.0f;
                func_80015268(position,
                              sign * (D_800D6D90[0] - 30.0f),
                              D_800D6D90[1] +
                                  random_value *
                                      (D_800D6D90[4] - D_800D6D90[1]),
                              resource_matrix[3][2]);
                func_80084A3C(POINTER_VALUE(resources[0]),
                              POINTER_VALUE(resources[0x2D]), position, 10,
                              POINTER_VALUE(record), first_data, second_data);
                func_80084BDC(projected, auxiliary, record, first_data,
                              second_data);
                func_80015288(position, projected);
                if (position[0] < 0.0f) {
                    position[0] -= 30.0f;
                } else {
                    position[0] += 30.0f;
                }
                break;

            case 2:
                func_80017C18(resources[D_800A2194], resource_matrix);
                bound_vertical = (2.0 * (f64)D_800D6DC0[1] +
                                  (f64)D_800D6DC0[4]) /
                                 3.0;
                random_value =
                    (f32)func_80082BE0() / 2147483648.0f;
                func_80015268(
                    position, D_800D6DC0[0] - 30.0f,
                    (f32)((f64)random_value *
                              ((f64)D_800D6DC0[4] - bound_vertical) +
                          bound_vertical),
                    resource_matrix[3][2]);
                func_80084A3C(POINTER_VALUE(resources[0]),
                              POINTER_VALUE(resources[left_resource]),
                              position, 10, POINTER_VALUE(record), first_data,
                              second_data);
                func_80084BDC(projected, auxiliary, record, first_data,
                              second_data);
                func_80015288(position, projected);
                position[0] -= 30.0f;
                break;

            case 3:
                func_80017C18(resources[D_800A2190], resource_matrix);
                bound_vertical = (2.0 * (f64)D_800D6DC0[1] +
                                  (f64)D_800D6DC0[4]) /
                                 3.0;
                random_value =
                    (f32)func_80082BE0() / 2147483648.0f;
                func_80015268(
                    position, D_800D6DB4 + 30.0f,
                    (f32)((f64)random_value *
                              ((f64)D_800D6DC0[4] - bound_vertical) +
                          bound_vertical),
                    resource_matrix[3][2]);
                func_80084A3C(POINTER_VALUE(resources[0]),
                              POINTER_VALUE(resources[right_resource]),
                              position, 10, POINTER_VALUE(record), first_data,
                              second_data);
                func_80084BDC(projected, auxiliary, record, first_data,
                              second_data);
                func_80015288(position, projected);
                position[0] += 30.0f;
                break;
            }

            if ((mode > 0) && (mode < 4)) {
                position[2] -= 20.0f;
                func_80015288(D_801195F0, position);
                D_801195F0[0] *= -1.0f;
                first_angle = func_80014F54(
                    position[0] - D_801195F0[0],
                    D_801195F0[1] - position[1]);
                func_80063084(i + 52, 8, position, position, first_angle,
                              first_angle);
            }
        }

        random_word = func_80082BE0();
        random_value =
            (f32)func_80082BE0() / 2147483648.0f;
        generated_x =
            (f32)random_word / 2147483648.0f * 2000.0f - 1000.0f;
        vertical = D_800D6DC0[4] + 500.0f;
        generated_y =
            random_value * (D_800D6DC0[4] + D_800A9C74 - vertical) +
            vertical;
        func_80015268(position, generated_x, generated_y, -157.0f);
        first_angle =
            ((f32)func_80082BE0() / 2147483648.0f) * 360.0f;
        func_80063084(20, 41, position, position, first_angle, first_angle);

        random_word = func_80082BE0();
        random_value =
            (f32)func_80082BE0() / 2147483648.0f;
        vertical = D_800D6DC0[0] - 500.0f;
        generated_x =
            (f32)random_word / 2147483648.0f *
                (D_800D6DC0[0] - 1000.0f - vertical) +
            vertical;
        generated_y =
            random_value * (D_800D6DC0[4] - -1000.0f) + -1000.0f;
        func_80015268(position, generated_x, generated_y, -157.0f);
        first_angle =
            ((f32)func_80082BE0() / 2147483648.0f) * 360.0f;
        func_80063084(19, 40, position, position, first_angle, first_angle);
    }

    for (i = 0; i < (s32)D_80113E7C; i++) {
        item = func_8003F800(0x456C6D6F, i + 52);
        record = D_800D7178 + i * 0x28;
        first_data = D_800D7218 + i * 3;
        second_data = D_800D7248 + i * 3;
        func_80084BDC(projected, auxiliary, record, first_data, second_data);
        func_80015288((f32 *)((u8 *)item + 0x44), projected);

        switch (D_800D7170[i]) {
        case 0:
            FIELD(f32, item, 0x4C) -= 90.0f;
            break;
        case 1:
            if (FIELD(f32, item, 0x44) < 0.0f) {
                FIELD(f32, item, 0x44) -= 30.0f;
            } else {
                FIELD(f32, item, 0x44) += 30.0f;
            }
            FIELD(f32, item, 0x4C) -= 20.0f;
            break;
        case 2:
            FIELD(f32, item, 0x44) -= 30.0f;
            FIELD(f32, item, 0x4C) -= 20.0f;
            break;
        case 3:
            FIELD(f32, item, 0x44) += 30.0f;
            FIELD(f32, item, 0x4C) -= 20.0f;
            break;
        }
        func_80033878(FIELD(void *, item, 0x30),
                      (f32 *)((u8 *)item + 0x44));
    }

    func_80048A50(POINTER_VALUE(state));
    if ((D_800A4BBC != 0) && (D_800A21B0 == 1)) {
        D_800A21B0 = 0;
        FIELD(s32, state, 0x10) = 1;
    }

    if (FIELD(s32, state, 0x10) != 1) {
        D_800A4BF0 -= D_80120BF8;
        if (D_800A4BF0 < 0.0f) {
            D_800A4BF0 = 0.0f;
        }
        if (FIELD(s32, state, 0x08) == 8) {
            func_80021294(state);
        }
    } else {
        D_800A4BF0 += D_80120BF8;
        if (D_800A4BF0 > D_800A9C78) {
            D_800A4BF0 = D_800A9C78;
        }
        if (FIELD(s32, state, 0x08) == 8) {
            func_80021F84(state);
        }
    }
}

#undef POINTER_VALUE
#undef FIELD
