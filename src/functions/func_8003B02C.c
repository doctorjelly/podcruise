/* Recovered from specification $S/specs/func_8003B02C.md (batch_06). */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} PcVec3;

typedef struct {
    f32 m[4][4];
} PcMtx;

typedef struct {
    s32 unk00;
    s32 unk04;
    f32 unk08;
    s32 unk0C;
    s32 unk10;
} PcTrack;

extern void func_8003AE64(PcTrack *track, PcVec3 *frame);
extern f32 func_800153C0(PcVec3 *vector);
extern void func_8003A5D0(s32 arg0, s32 arg1, f32 arg2, void *arg3, PcVec3 *arg4);
extern void func_80015538(PcVec3 *output, PcVec3 *left, PcVec3 *right);
extern f32 func_800154D0(PcVec3 *vector);
extern void func_80015694(PcMtx *matrix, s32 row, PcVec3 *source);
extern void func_800156B8(PcMtx *matrix, s32 row, PcVec3 *output);

void func_8003B02C(PcTrack *track, PcMtx *matrix) {
    PcVec3 binormal;
    PcVec3 normal;
    PcVec3 previous;
    f32 length;
    PcVec3 frame[4];

    func_8003AE64(track, frame);
    length = func_800153C0(&frame[1]);
    if (length < 0.0001) {
        if (track->unk08 < 0.5f) {
            func_8003A5D0(track->unk00, 2, 0.001f, &track->unk10, frame);
        } else {
            func_8003A5D0(track->unk00, 2, 0.999f, &track->unk10, frame);
        }
    }

    func_80015538(&normal, &frame[1], &frame[3]);
    func_80015538(&binormal, &normal, &frame[1]);
    func_800154D0(&normal);
    func_800154D0(&binormal);
    func_800154D0(&frame[1]);

    matrix->m[0][3] = 0.0f;
    matrix->m[1][3] = 0.0f;
    matrix->m[2][3] = 0.0f;
    matrix->m[3][3] = 1.0f;
    func_80015694(matrix, 0, &normal);
    func_80015694(matrix, 1, &frame[1]);
    func_80015694(matrix, 2, &binormal);
    func_800156B8(matrix, 3, &previous);
    func_80015694(matrix, 3, &frame[0]);
}
