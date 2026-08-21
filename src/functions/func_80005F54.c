/* Recovery evidence: specs/functions/recovered/medium_system_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 unk000[0x11C];
    /* 0x11C */ f32 *keys;
    /* 0x120 */ f32 (*poses)[4];
} PcPoseTrack;

extern f32 func_80005CAC(PcPoseTrack *track, f32 position, s32 index);
extern void func_800827E0(f32 *from, f32 *to, f32 blend, f32 *result);
extern void func_800829F4(f32 *result, f32 *quaternion);
extern void func_80082B38(f32 *quaternion, f32 *rotation);

void func_80005F54(f32 *out, PcPoseTrack *track, f32 time, s32 index) {
    f32 from[4];
    f32 to[4];
    f32 blend;
    f32 fromQuat[4];
    f32 toQuat[4];
    f32 result[4];

    if (track->keys[index + 1] < time) {
        out[0] = track->poses[index + 1][0];
        out[1] = track->poses[index + 1][1];
        out[2] = track->poses[index + 1][2];
        out[3] = track->poses[index + 1][3];
    } else if (time <= track->keys[index]) {
        out[0] = track->poses[index][0];
        out[1] = track->poses[index][1];
        out[2] = track->poses[index][2];
        out[3] = track->poses[index][3];
    } else {
        blend = func_80005CAC(track, time, index);
        from[0] = track->poses[index][0];
        from[1] = track->poses[index][1];
        from[2] = track->poses[index][2];
        from[3] = track->poses[index][3];
        to[0] = track->poses[index + 1][0];
        to[1] = track->poses[index + 1][1];
        to[2] = track->poses[index + 1][2];
        to[3] = track->poses[index + 1][3];
        func_80082B38(fromQuat, from);
        func_80082B38(toQuat, to);
        func_800827E0(fromQuat, toQuat, blend, result);
        func_800829F4(out, result);
    }
}
