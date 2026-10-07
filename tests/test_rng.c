#include <assert.h>
#include <stdint.h>

#include "../src/functions/func_80082BE0.c"

u8 D_800A6770;
s32 D_80120C30;

static long long timer_value;
static unsigned timer_calls;

long long func_800811DC(void) {
    timer_calls++;
    return timer_value;
}

static s32 signed_from_bits(u32 bits) {
    if (bits <= 0x7FFFFFFFU) {
        return (s32)bits;
    }
    return -1 - (s32)(~bits);
}

static void check_initialized(u32 seed, u32 expected_state,
                              s32 expected_result) {
    D_800A6770 = 1;
    D_80120C30 = signed_from_bits(seed);
    timer_calls = 0;

    assert(func_80082BE0() == expected_result);
    assert((u32)D_80120C30 == expected_state);
    assert(timer_calls == 0);
}

static void check_lazy_init(long long timer, u32 expected_state,
                            s32 expected_result) {
    D_800A6770 = 0;
    D_80120C30 = 0x12345678;
    timer_value = timer;
    timer_calls = 0;

    assert(func_80082BE0() == expected_result);
    assert((u32)D_80120C30 == expected_state);
    assert(D_800A6770 == 1);
    assert(timer_calls == 1);
}

int main(void) {
    static const struct {
        u32 seed;
        u32 state;
        s32 result;
    } cases[] = {
        {0x00000000U, 0x00003039U, 12345},
        {0x00000001U, 0x41C67EA6U, 1103527590},
        {0x00000002U, 0x838CCD13U, 2087924461},
        {0x12345678U, 0x0B719151U, 191992145},
        {0x7C77A683U, 0x80000000U, 0},
        {0x8DBDBB1EU, 0x7FFFFFFFU, 2147483647},
        {0x0DBDBB1EU, 0xFFFFFFFFU, 1},
    };
    unsigned i;

    for (i = 0; i < sizeof(cases) / sizeof(cases[0]); i++) {
        check_initialized(cases[i].seed, cases[i].state, cases[i].result);
    }

    /* The initializer is 64-bit; the generator uses its low 32 bits. */
    check_lazy_init(0x12345678ABCDEF01LL, 0x014741A6U, 21447078);
    return 0;
}
