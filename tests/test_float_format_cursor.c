#include <assert.h>
#include <string.h>

#include "../src/functions/func_80097400.c"

f64 D_800AE170[32];
u8 D_800AE1B8[3];
u8 D_800AE1BC[3];
f64 D_800AE1C8;

static u8 captured_first_digit;
static s16 captured_nsig;
static s16 captured_xexp;
static u8 captured_conversion;

void *func_8008C2F0(void *destination, const void *source, u32 count) {
    return memcpy(destination, source, count);
}

void func_80096E90(Struct80097400 *state, u8 code, u8 *digits,
                   s16 nsig, s16 xexp) {
    (void)state;
    captured_conversion = code;
    captured_first_digit = digits[0];
    captured_nsig = nsig;
    captured_xexp = xexp;
}

Struct80097F60 func_80097F60(s32 numerator, s32 denominator) {
    Struct80097F60 result;
    result.unk0 = numerator / denominator;
    result.unk4 = numerator % denominator;
    return result;
}

int main(void) {
    Struct80097400 state = {0};
    u16 *halves;
    u8 output[8] = {0};

    /* The recovered classifier reads the first native halfword. Set it to
       exponent class 0x3ff: on big-endian hosts this keeps 1.0; on little-
       endian hosts it produces a value just above 1.0. Both round to one
       significant digit. This tests the cursor path, not endian portability. */
    state.value = 1.0;
    state.buffer = output;
    state.precision = 0;
    halves = (u16 *)&state;
    halves[0] = 0x3FF0;

    /* The classifier's decimal scaling turns 1.0 into the first digit of
       the final eight-byte chunk. */
    D_800AE170[2] = 10000.0;
    D_800AE1C8 = 100000000.0;

    func_80097400(&state, 'e');

    assert(captured_conversion == 'e');
    assert(captured_nsig == 1);
    assert(captured_xexp == 0);
    assert(captured_first_digit == '1');
    return 0;
}
