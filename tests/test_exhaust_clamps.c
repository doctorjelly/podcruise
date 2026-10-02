#include <assert.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "../src/functions/func_800784F8.c"

f32 D_800A5CA0[16][27];
f32 D_800A5D00[16][27];
f32 D_800ADAA0 = 0.001f;
f32 D_800ADAA4 = 0.01f;
f32 D_800ADAA8 = 0.8f;
f32 D_800ADAAC = -0.1f;
f32 D_800ADAB0 = 0.1f;
f32 D_800ADAB4 = 0.3f;
f32 D_800ADAB8 = -0.03f;
f32 D_800ADABC = 0.03f;
f32 D_800ADAC0 = 0.3f;
f64 D_80120BF0 = 1.0 / 60.0;

static s16 colors[2][4];
static s32 color_count;

u32 func_8000E8C4(void *object) {
    (void)object;
    /* A nonzero synthetic resource handle enables each color update. */
    return 1;
}
void func_8000E9BC(u8 **owner, s16 a, s16 b, s16 red, s16 green,
                    s16 blue, s16 alpha) {
    (void)owner;
    assert(a == 0 && b == 0);
    assert(color_count < 2);
    colors[color_count][0] = red;
    colors[color_count][1] = green;
    colors[color_count][2] = blue;
    colors[color_count][3] = alpha;
    color_count++;
}
void func_80015268(f32 *out, f32 x, f32 y, f32 z) {
    out[0] = x; out[1] = y; out[2] = z;
}
void func_80015288(f32 *out, const f32 *in) {
    memmove(out, in, sizeof(f32) * 3);
}
void func_80015328(f32 *out, const f32 *a, const f32 *b) {
    s32 i;
    for (i = 0; i < 3; i++) out[i] = a[i] + b[i];
}
void func_800156DC(Matrix800784F8 out, const Matrix800784F8 in) {
    memmove(out, in, sizeof(Matrix800784F8));
}
void func_80016BF4(f32 *out, const f32 *in, const Matrix800784F8 matrix) {
    (void)matrix;
    memmove(out, in, sizeof(f32) * 3);
}
void func_80017520(f32 *matrix, f32 x, f32 y, f32 z) {
    memset(matrix, 0, sizeof(Matrix800784F8));
    matrix[0] = x; matrix[5] = y; matrix[10] = z; matrix[15] = 1.0f;
}
void func_80017BA8(void *destination, const void *source) {
    (void)destination; (void)source;
}
s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode) {
    (void)object; (void)which; (void)value; (void)flags; (void)mode;
    return 0;
}
void func_8003E0A0(void *state, f32 step_u, f32 step_v) {
    (void)state; (void)step_u; (void)step_v;
}
void func_800738D4(void *craft, s32 mode, f32 *from, f32 *to) {
    (void)craft; (void)mode; (void)from; (void)to;
}
void func_80075FC4(Matrix800784F8 first, Matrix800784F8 second,
                    f32 spread_a, f32 spread_b, s32 index, Matrix800784F8 out) {
    (void)first; (void)second; (void)spread_a; (void)spread_b; (void)index;
    memset(out, 0, sizeof(Matrix800784F8));
}
void func_80077C94(void *craft, Matrix800784F8 source, f32 scale_x,
                    f32 scale_y, f32 scale_z, f32 angle, s32 mode) {
    (void)craft; (void)source; (void)scale_x; (void)scale_y; (void)scale_z;
    (void)angle; (void)mode;
}
void func_800834F0(void *node, f32 *first, f32 *second, f32 scale,
                    f32 amplitude, f32 age, f32 lifetime, s32 mode) {
    (void)node; (void)first; (void)second; (void)scale; (void)amplitude;
    (void)age; (void)lifetime; (void)mode;
}

static void run_case(f32 heat, f32 component_state, s16 rgb, s16 alpha) {
    union { max_align_t align; u8 bytes[0x2000]; } craft;
    union { max_align_t align; u8 bytes[0x200]; } attachment;
    union { max_align_t align; u8 bytes[0x30]; } type_record;
    /* This type skips connector setup and returns after the exhaust updates. */
    s32 type = 14;
    s32 *type_pointer = &type;
    void *record_pointer = type_record.bytes;
    void *attachment_pointer = attachment.bytes;
    s32 i;

    memset(&craft, 0, sizeof(craft));
    memset(&attachment, 0, sizeof(attachment));
    memset(&type_record, 0, sizeof(type_record));
    memcpy(craft.bytes + 0x344, &attachment_pointer, sizeof(attachment_pointer));
    memcpy(craft.bytes + 0x1E70, &record_pointer, sizeof(record_pointer));
    memcpy(type_record.bytes + 0x18, &type_pointer, sizeof(type_pointer));
    memcpy(craft.bytes + 0x1A0, &heat, sizeof(heat));
    memcpy(craft.bytes + 0x218, &component_state, sizeof(component_state));
    memset(colors, 0, sizeof(colors));
    color_count = 0;

    func_800784F8(craft.bytes);

    assert(color_count == 2);
    for (i = 0; i < color_count; i++) {
        assert(colors[i][0] == rgb);
        assert(colors[i][1] == rgb);
        assert(colors[i][2] == rgb);
        assert(colors[i][3] == alpha);
    }
}

int main(void) {
    run_case(1000.0f, 100.0f, 255, 50);
    run_case(1000.0f, 50.0f, 255, 50);
    run_case(1000.0f, 43.75f, 127, 73);
    run_case(1000.0f, 25.0f, 0, 145);
    run_case(1000.0f, 0.0f, 0, 240);
    run_case(1000.0f, -INFINITY, 0, 240);
    run_case(1000.0f, INFINITY, 255, 50);
    run_case(50.0f, 100.0f, 255, 12);
    run_case(25.0f, 100.0f, 255, 3);
    run_case(0.0f, 100.0f, 255, 1);
    run_case(-0.0f, 100.0f, 255, 1);
    run_case(1000.0f, NAN, 255, 50);
    run_case(NAN, 100.0f, 255, 1);
    run_case(NAN, 0.0f, 0, 1);
    return 0;
}
