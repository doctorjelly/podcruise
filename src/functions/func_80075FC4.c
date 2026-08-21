/* Recovery evidence: specs/functions/recovered/medium_runtime_tranche.md. */
#include "podcruise/types.h"

extern f32 D_800A5CA0[][27];
extern f32 D_800AD9D4;

extern void func_80015268(f32 *output, f32 x, f32 y, f32 z);
extern void func_80015288(f32 *output, f32 *source);
extern void func_80015328(f32 *output, f32 *left, f32 *right);
extern void func_8001535C(f32 *output, f32 *left, f32 *right);
extern f32 func_800153C0(f32 *vector);
extern f32 func_800154D0(f32 *vector);
extern void func_80015538(f32 *output, f32 *left, f32 *right);
extern void func_800156DC(f32 output[4][4], f32 source[4][4]);
extern void func_80016BF4(f32 *output, f32 *vector, f32 matrix[4][4]);
extern void func_80017580(f32 *matrix, f32 x, f32 y, f32 z);
extern void func_80017918(f32 dest[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);

void func_80075FC4(f32 first[4][4], f32 second[4][4], f32 spreadA, f32 spreadB, s32 index, f32 output[4][4]) {
    f32 startPoint[3];
    f32 endPoint[3];
    f32 startOffset[3];
    f32 endOffset[3];
    f32 direction[3];
    f32 length;
    f32 frame[4][4];

    func_80015288(startPoint, first[3]);
    func_80015288(endPoint, second[3]);

    startOffset[0] = D_800A5CA0[index][9] * spreadA;
    startOffset[1] = D_800A5CA0[index][10];
    startOffset[2] = D_800A5CA0[index][11];
    endOffset[0] = D_800A5CA0[index][12] * spreadA;
    endOffset[1] = D_800A5CA0[index][13];
    endOffset[2] = D_800A5CA0[index][14] * spreadB;

    func_80016BF4(startOffset, startOffset, first);
    func_80015328(startPoint, startOffset, startPoint);
    func_80016BF4(endOffset, endOffset, second);
    func_80015328(endPoint, endOffset, endPoint);

    func_8001535C(direction, startPoint, endPoint);
    length = func_800153C0(direction);
    func_800154D0(direction);

    func_80017580(frame[0], startPoint[0], startPoint[1], startPoint[2]);
    func_80015288(frame[1], direction);
    func_80015268(frame[2], 0.0f, 0.0f, 1.0f);
    func_80015538(frame[0], frame[1], frame[2]);
    func_80015538(frame[2], frame[0], frame[1]);
    func_80017918(frame, D_800AD9D4, length / 100.0f, D_800AD9D4, frame);
    func_800156DC(output, frame);
}
