#include <assert.h>
#include <stddef.h>
#include <string.h>

#include "../src/functions/func_8004BE90.c"

PcRacerRecord D_800A31E0[32];
s8 D_800A21C2[256];
u8 D_800AAE44[1], D_800AAE48[1];
PcOptionBlock D_80113680;
PcNameBlock D_80113E60;
s32 D_800D76F0;
s32 *D_8011A508[256];
s32 *D_8011A544;

static const s32 *random_values;
static size_t random_count;
static size_t random_index;
static int special_count;
static int fallback_count;
static s32 fallback_racer_resource;

void func_80051898(s32 a) {(void)a;}
void func_8000A44C(s16 a, s32 b) {(void)a; (void)b;}
void func_80005B80(void) {}
void func_80046870(void) {}
s32 func_80030154(s32 a) {return a;}
void func_8000AC34(s16 a, u32 b) {(void)a; (void)b;}
void func_8000AC60(s16 a, u32 b) {(void)a; (void)b;}
void func_8000AB24(s16 a, u8 b, u8 c, u8 d, u8 e) {
    (void)a; (void)b; (void)c; (void)d; (void)e;
}
void func_8004B3FC(void) {}
void func_8004B084(void) {}
void func_8004B18C(void) {}
void func_80046670(s32 a, s32 b, s32 c, s32 d) {
    (void)a; (void)b; (void)c; (void)d;
}
void func_8004AFD4(void) {}
s32 func_80082BE0(void) {
    assert(random_index < random_count);
    return random_values[random_index++];
}
void func_800517D8(s32 resource, s32 slot, s32 type, f32 scale) {
    (void)scale;
    if (slot == 0x39 && resource == 0x6D && type == 1) {
        special_count++;
    }
    if (slot == 0x39 && type == 2) {
        fallback_count++;
        fallback_racer_resource = resource;
    }
}
void func_8004B568(void) {}
void func_8002963C(void *a) {(void)a;}
void func_8004B6E8(void) {}
s32 func_8002D968(u8 *a, u8 *b) {(void)a; (void)b; return 0;}
void func_8002FB90(void) {}

static void run_phase3(s32 mask, const s32 *rng, size_t rng_count,
                       int expected_special, int expected_fallback,
                       s32 expected_fallback_resource) {
    PcRaceState state;
    s32 i;

    memset(&state, 0, sizeof(state));
    memset(D_800A31E0, 0, sizeof(D_800A31E0));
    memset(&D_80113680, 0, sizeof(D_80113680));
    for (i = 0; i < 32; i++) {
        D_800A31E0[i].unk30 = 0x1000 + i;
    }
    D_80113680.unk10 = mask;
    state.kind = 1;
    state.previous = 0;
    random_values = rng;
    random_count = rng_count;
    random_index = 0;
    special_count = 0;
    fallback_count = 0;
    fallback_racer_resource = -1;

    func_8004BE90(&state);

    assert(random_index == random_count);
    assert(special_count == expected_special);
    assert(fallback_count == expected_fallback);
    if (expected_fallback) {
        assert(fallback_racer_resource == expected_fallback_resource);
    }
}

int main(void) {
    static const s32 zero[] = {0};
    static const s32 bit18_rng[] = {0x64000000};
    static const s32 bit19_rng[] = {0x69000000, 0};
    static const s32 fallback_rng[] = {0x70000000, 0};

    run_phase3(2, zero, 1, 1, 0, -1);
    run_phase3(0x00040002, zero, 1, 1, 0, -1);
    run_phase3((s32)0x80000002u, zero, 1, 1, 0, -1);
    run_phase3(0x00040000, bit18_rng, 1, 1, 0, -1);
    run_phase3(0x00080000, bit19_rng, 2, 0, 1, 0x1000);
    run_phase3(0x00100000, fallback_rng, 2, 0, 1, 0x1000);
    return 0;
}
