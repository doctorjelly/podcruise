/* Independently written from specs/functions/matrix_from_euler.md. */

#include "podcruise/types.h"

extern void func_80014CC0(f32 angle, f32 *sine, f32 *cosine);

void func_8001723C(f32 *matrix, f32 first, f32 second, f32 third) {
    f32 sinFirst;
    f32 cosFirst;
    f32 sinSecond;
    f32 cosSecond;
    f32 sinThird;
    f32 cosThird;
    f32 coscos;
    f32 cossin;
    f32 sincos;
    f32 sinsin;

    func_80014CC0(first, &sinFirst, &cosFirst);
    func_80014CC0(second, &sinSecond, &cosSecond);
    func_80014CC0(third, &sinThird, &cosThird);

    coscos = cosFirst * cosThird;
    cossin = cosFirst * sinThird;
    sincos = sinFirst * cosThird;
    sinsin = sinFirst * sinThird;

    matrix[0] = coscos - sinsin * sinSecond;
    matrix[1] = cossin * sinSecond + sincos;
    matrix[2] = -sinThird * cosSecond;
    matrix[4] = -sinFirst * cosSecond;
    matrix[5] = cosFirst * cosSecond;
    matrix[6] = sinSecond;
    matrix[8] = sincos * sinSecond + cossin;
    matrix[9] = sinsin - coscos * sinSecond;
    matrix[10] = cosThird * cosSecond;
}
