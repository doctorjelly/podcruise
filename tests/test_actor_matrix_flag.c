#include <assert.h>
#include <string.h>

#include "../src/functions/func_80042BB8.c"

f32 D_800A4AF0;
f64 D_80120BF0;

static f32 *actor050_address;
static f32 *first_vector_address;
static f32 *later_vector_address;
static f32 later_vector_x;
static int matrix_builds;
static int first_vector_calls;
static int later_vector_copies;

s32 func_80051FF4(void) {
    return 1;
}

void func_80017874(f32 (*matrix)[4]) {
    memset(matrix, 0, sizeof(f32) * 16);
    matrix_builds++;
}

void func_8001535C(f32 *output, f32 *left, f32 *right) {
    (void)output;
    (void)left;
    if (right == actor050_address) {
        first_vector_calls++;
        first_vector_address = right;
        right[0] = 42.0f;
    }
}

void func_80015288(f32 *output, f32 *source) {
    (void)output;
    if (source == actor050_address) {
        later_vector_copies++;
        later_vector_address = source;
        later_vector_x = source[0];
    }
}

void func_80015538(f32 *output, f32 *left, f32 *right) {
    (void)output;
    (void)left;
    (void)right;
}

f32 func_800154D0(f32 *vector) {
    (void)vector;
    return 0.0f;
}

void func_800181BC(void *node, s32 which, s32 value, s32 flags, s32 mode) {
    (void)node;
    (void)which;
    (void)value;
    (void)flags;
    (void)mode;
}

void func_8000EA4C(void *node, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    (void)node;
    (void)a;
    (void)b;
    (void)c;
    (void)d;
    (void)e;
    (void)f;
}

void func_80017918(f32 (*output)[4], f32 x, f32 y, f32 z, f32 (*source)[4]) {
    (void)output;
    (void)x;
    (void)y;
    (void)z;
    (void)source;
}

void func_800155EC(f32 *output, f32 *source, f32 angle, f32 *axis) {
    (void)output;
    (void)source;
    (void)angle;
    (void)axis;
}

void func_80017BA8(void *node, f32 (*matrix)[4]) {
    (void)node;
    (void)matrix;
}

static void check_gate(s32 flags, int has_part, int has_nested,
                       int expected_matrix_builds, int expect_pointer_alias) {
    Actor80042BB8 actor;
    Part80042BB8 part;
    int nested_marker;

    memset(&actor, 0, sizeof(actor));
    memset(&part, 0, sizeof(part));
    nested_marker = 0;
    if (has_part) {
        actor.unk0F4 = &part;
        part.unk060 = flags;
        if (has_nested) {
            part.unk254 = &nested_marker;
        }
    }
    actor050_address = actor.unk050;
    actor.unk050[0] = 1.0f;
    actor.unk050[1] = 2.0f;
    actor.unk050[2] = 3.0f;

    matrix_builds = 0;
    first_vector_calls = 0;
    later_vector_copies = 0;
    first_vector_address = 0;
    later_vector_address = 0;
    later_vector_x = 0.0f;
    D_800A4AF0 = 0.25f;
    D_80120BF0 = 0.0;

    func_80042BB8(&actor);

    assert(matrix_builds == expected_matrix_builds);
    if (expect_pointer_alias) {
        assert(first_vector_calls == 1);
        assert(later_vector_copies == 1);
        assert(first_vector_address == actor050_address);
        assert(later_vector_address == actor050_address);
        assert(later_vector_x == 42.0f);
    } else {
        assert(first_vector_calls == 0);
        assert(later_vector_copies == 0);
    }
}

int main(void) {
    check_gate(-1, 0, 1, 0, 0);                    /* no part */
    check_gate(0x04000000, 1, 1, 0, 0);           /* bit 26 does not enter */
    check_gate(0x08000000, 1, 1, 2, 1);           /* bit 27 enters */
    check_gate(0x08000000, 1, 0, 0, 0);           /* null nested pointer */
    check_gate(0x10000000, 1, 1, 0, 0);           /* bit 28 shifts out */
    check_gate(-268435456, 1, 1, 0, 0);           /* negative, bit 27 clear */
    check_gate(-1, 1, 1, 2, 1);                   /* negative, bit 27 set */
    return 0;
}
