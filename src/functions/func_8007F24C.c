/* Recovery evidence: specs/functions/recovered/medium_system_tranche.md. */

#include "podcruise/types.h"

typedef struct PcVec3 {
    f32 x;
    f32 y;
    f32 z;
} PcVec3;

typedef struct PcTrack8007F24C {
    s32 unk00;
    s32 unk04;
    f32 unk08;
} PcTrack8007F24C;

extern void func_8003B02C(PcTrack8007F24C *track, f32 *matrix);

extern f32 D_800ADC54;
extern f32 D_800ADC58;

void func_8007F24C(PcTrack8007F24C *track, PcVec3 *vector) {
    f32 target;
    f32 reach;
    f32 previous;
    f32 value;
    f32 matrix[16];
    f32 step;
    s32 moved;
    s32 settled;

    moved = 0;
    func_8003B02C(track, matrix);
    step = D_800ADC54;
    do {
        settled = 1;
        target = (vector->x * matrix[4] + vector->y * matrix[5]) + matrix[6] * vector->z;
        reach = (matrix[12] * matrix[4] + matrix[13] * matrix[5]) + matrix[14] * matrix[6];
        if (reach < target) {
            value = track->unk08;
            track->unk08 = value + step;
            func_8003B02C(track, matrix);
            moved = 1;
            if (value != track->unk08) {
                settled = 0;
            }
        }
    } while (settled == 0);

    step = D_800ADC58;
    if (moved == 0) {
        track->unk08 = track->unk08 - step;
        func_8003B02C(track, matrix);
        value = track->unk08;
        do {
            settled = 1;
            target = (vector->x * matrix[4] + vector->y * matrix[5]) + matrix[6] * vector->z;
            reach = (matrix[12] * matrix[4] + matrix[13] * matrix[5]) + matrix[14] * matrix[6];
            if (target < reach) {
                previous = value;
                track->unk08 = value - step;
                func_8003B02C(track, matrix);
                value = track->unk08;
                if (previous != value) {
                    settled = 0;
                }
            }
        } while (settled == 0);
        track->unk08 = value + step;
        func_8003B02C(track, matrix);
    }
}
