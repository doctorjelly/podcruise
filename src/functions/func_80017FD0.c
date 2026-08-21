/* Independently written from the complete object-island body. */

#include "podcruise/types.h"

extern void func_80015724(f32 *destination, const f32 *source, const f32 *third);

void func_80017FD0(void *object, const f32 *input) {
    f32 *matrix = (f32 *)((u8 *)object + 0xB0);

    matrix[0] = input[0];
    matrix[1] = input[1];
    matrix[2] = input[2];
    matrix[3] = input[3];
    matrix[4] = input[4];
    matrix[5] = input[5];
    matrix[6] = input[6];
    matrix[7] = input[7];
    matrix[8] = input[8];
    matrix[9] = input[9];
    matrix[10] = input[10];
    matrix[11] = input[11];
    matrix[12] = input[12];
    matrix[13] = input[13];
    matrix[14] = input[14];
    matrix[15] = input[15];
    func_80015724((f32 *)((u8 *)object + 0x70), (f32 *)((u8 *)object + 0x30),
                  matrix);
}
