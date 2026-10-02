#include <assert.h>
#include <math.h>
#include <string.h>

#include "../src/functions/func_80079824.c"

f64 D_800ADAC8 = -0.05;
f64 D_800ADAD0 = 700.0;
f64 D_800ADAD8 = -180.0;
f64 D_800ADAE0 = 360.0;
f64 D_800ADAE8 = 180.0;
f64 D_800ADAF0 = 360.0;
f64 D_80120BF0 = 1.0 / 60.0;
f32 D_800D7720[4];
f32 D_800D7730[4];

static s32 channels[6];
static f32 targets[6];
static s32 angle_count;
static s32 applied_count;
static f32 applied_rotations[2][3];

void func_800156DC(f32 out[4][4], const f32 in[4][4]) {
    memcpy(out, in, sizeof(f32) * 16);
}
void func_8001745C(f32 matrix[4][4], f32 x, f32 y, f32 z) {
    /* Preserve the requested angles for the subsequent part-update mock. */
    memset(matrix, 0, sizeof(f32) * 16);
    matrix[0][0] = x;
    matrix[0][1] = y;
    matrix[0][2] = z;
}
void func_80017BA8(void *part, const void *matrix) {
    assert(part != 0);
    assert(applied_count < 2);
    memcpy(applied_rotations[applied_count], matrix, sizeof(f32) * 3);
    applied_count++;
}
s32 func_800181BC(void *part, s32 which, u32 value, s32 flags, s32 mode) {
    (void)part; (void)which; (void)value; (void)flags; (void)mode;
    return 0;
}
f32 func_80079714(Object80079824 *object, s32 channel, f32 target,
                   f32 a, f32 b, f32 c, f32 d, f32 e) {
    (void)object; (void)a; (void)b; (void)c; (void)d; (void)e;
    assert(angle_count < 6);
    assert(isfinite(target));
    channels[angle_count] = channel;
    targets[angle_count] = target;
    angle_count++;
    /* Immediate response exposes the selected target in applied rotations. */
    return target;
}

static void run_case(f32 steering, f32 expected_40, f32 expected_30) {
    static const s32 expected_channels[6] = {0x2E, 0x2F, 0x20, 0x12, 0x23, 0x15};
    Object80079824 object;
    Parts80079824 parts;
    Kind80079824 descriptor;
    s32 kind = 22;
    s32 dummy_parts[2];
    s32 i;

    memset(&object, 0, sizeof(object));
    memset(&parts, 0, sizeof(parts));
    memset(&descriptor, 0, sizeof(descriptor));
    descriptor.kind = &kind;
    object.parts = &parts;
    object.kindData = &descriptor;
    object.steering = steering;
    parts.entries[0xC0 / 4] = &dummy_parts[0];
    parts.entries[0xC4 / 4] = &dummy_parts[1];
    angle_count = 0;
    applied_count = 0;

    func_80079824(&object);

    assert(angle_count == 6);
    for (i = 0; i < angle_count; i++) assert(channels[i] == expected_channels[i]);
    assert(targets[0] == expected_40);
    assert(targets[1] == 0.0f);
    assert(targets[2] == expected_30);
    assert(targets[3] == -expected_30);
    assert(targets[4] == expected_30);
    assert(targets[5] == -expected_30);
    assert(applied_count == 2);
    for (i = 0; i < applied_count; i++) {
        assert(applied_rotations[i][0] == expected_40);
        assert(applied_rotations[i][1] == 0.0f);
        assert(applied_rotations[i][2] == 0.0f);
    }
}

int main(void) {
    run_case(-100.0f, 40.0f, 30.0f);
    run_case(-20.0f, 40.0f, 30.0f);
    run_case(-10.0f, 20.0f, 15.0f);
    run_case(-0.0f, 0.0f, 0.0f);
    run_case(0.0f, 0.0f, 0.0f);
    run_case(10.0f, -20.0f, -15.0f);
    run_case(20.0f, -40.0f, -30.0f);
    run_case(100.0f, -40.0f, -30.0f);
    run_case(-INFINITY, 40.0f, 30.0f);
    run_case(INFINITY, -40.0f, -30.0f);
    run_case(NAN, -40.0f, -30.0f);
    return 0;
}
