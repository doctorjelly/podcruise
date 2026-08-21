/* Independently written from scratchpad spec specs/func_8007F914.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10[7];
    /* 0x2C */ s32 unk2C;
} PcTrack; /* 0x30 */

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 unk04;
} PcSample; /* 0x08 */

extern s32 func_8003A568(PcTrack *track, s32 index);
extern void func_8003B02C(PcTrack *track, f32 *matrix);
extern void func_8003B184(PcTrack *track, f32 *matrix, f32 offset);
extern f32 func_80015470(const f32 *from, const f32 *to);

extern PcSample D_80120408[];
extern f32 D_800A6700;
extern s32 D_800A6704;
extern f32 D_8011DCB8[16];

void func_8007F914(PcTrack *arg0, f32 arg1, s16 *arg2, s16 *arg3) {
    s32 index;
    s32 lastIndex;
    s32 done;
    s32 step;
    f32 matrix[16];
    f32 previous[3];
    s32 pass;
    f32 base;
    f32 limit;
    PcTrack track;
    s32 row;
    s32 column;
    f32 total;
    f32 blend;
    s32 steps;
    f32 fraction;
    s32 first;

    (void)row;
    (void)column;
    first = 0;
    index = func_8003A568(arg0, 0);
    if (D_80120408[index].unk00 > 0.0f) {
        return;
    }

    if (arg0->unk2C == 0) {
        base = 0.0f;
        first = 1;
    } else {
        base = D_80120408[arg0->unk10[0]].unk00;
    }
    D_80120408[index].unk00 = base;

    track = *arg0;
    total = 0.0f;
    track.unk08 = 0.0f;
    func_8003B02C(&track, matrix);
    steps = 0;
    index = -1;
    done = 0;
    previous[0] = matrix[12];
    previous[1] = matrix[13];
    previous[2] = matrix[14];

    do {
        steps++;
        blend = 0.0f;
        for (step = 1; step < arg1; step++) {
            blend += 1.0f / arg1;
            func_8003B184(&track, matrix, blend);
            total += func_80015470(previous, &matrix[12]);
            previous[0] = matrix[12];
            previous[1] = matrix[13];
            previous[2] = matrix[14];
        }
        track.unk08 = 1.0f;
        func_8003B02C(&track, matrix);
        lastIndex = index;
        index = func_8003A568(&track, 0);
        if (lastIndex == index) {
            done = 1;
            limit = 1.0f;
            if (D_800A6704 == -2) {
                D_800A6704 = index;
                D_8011DCB8[0] = matrix[0]; D_8011DCB8[1] = matrix[1]; D_8011DCB8[2] = matrix[2]; D_8011DCB8[3] = matrix[3];
                D_8011DCB8[4] = matrix[4]; D_8011DCB8[5] = matrix[5]; D_8011DCB8[6] = matrix[6]; D_8011DCB8[7] = matrix[7]; D_8011DCB8[8] = matrix[8]; D_8011DCB8[9] = matrix[9];
                D_8011DCB8[10] = matrix[10]; D_8011DCB8[11] = matrix[11];
                D_8011DCB8[12] = matrix[12]; D_8011DCB8[13] = matrix[13]; D_8011DCB8[14] = matrix[14]; D_8011DCB8[15] = matrix[15];
            } else {
                D_800A6704 = -3;
            }
        } else {
            total += func_80015470(previous, &matrix[12]);
            previous[0] = matrix[12];
            previous[1] = matrix[13];
            previous[2] = matrix[14];
            if (D_80120408[index].unk00 < 0.0f) {
                D_80120408[index].unk00 = total;
                track.unk08 = 0.0f;
            } else {
                limit = D_80120408[index].unk00;
                done = 1;
            }
        }
    } while (done == 0);

    if (limit == 0.0f) {
        limit = 1.0f;
    }
    if (first != 0) {
        D_800A6700 = total;
    }

    track = *arg0;
    pass = 0;
    if (steps > 0) {
        do {
            index = func_8003A568(&track, 0);
            arg2[index] = *arg3;
            fraction = (D_80120408[index].unk00 - base) / total;
            D_80120408[index].unk00 = (1.0f - fraction) * base + fraction * limit;
            if (pass != 0) {
                D_80120408[lastIndex].unk04 =
                    D_80120408[index].unk00 - D_80120408[lastIndex].unk00;
            }
            lastIndex = index;
            track.unk08 = 1.0f;
            func_8003B02C(&track, matrix);
            pass++;
            track.unk08 = 0.0f;
        } while (pass != steps);
    }
    D_80120408[lastIndex].unk04 = limit - D_80120408[lastIndex].unk00;
    *arg3 = *arg3 + 1;
}
