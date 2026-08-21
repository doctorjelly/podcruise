/* Independently written from $S/specs/func_8005FA38.md */
#include "podcruise/types.h"

typedef struct {
    u8 unk_00[0x10];
    void *unk_10[6];
    void *unk_28;
    u8 unk_2C[0x38];
    f32 unk_64[16];
    f32 unk_A4[16];
    f32 unk_E4[16];
    u8 unk_124[0xA4];
    s32 unk_1C8;
} Object8005FA38;

extern void func_8000EA4C(void *node, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f);
extern void func_80016F0C(void *matrix, f32 *output);
extern void func_80017824(void *destination, f32 angle, f32 x, f32 y, f32 z, void *source);
extern void func_80017BA8(void *destination, const void *source);
extern void func_80017D18(void *object, const void *source);
extern s32 func_800181BC(void *object, s32 which, s32 value, s32 flags, s32 mode);
extern s32 func_80080D08(void *matrix);

void func_8005FA38(Object8005FA38 *obj) {
    f32 pose[6];
    f32 dir[3];
    s32 i;
    f32 work[16];
    f32 result[16];

    obj->unk_A4[0] = obj->unk_64[0]; obj->unk_A4[1] = obj->unk_64[1]; obj->unk_A4[2] = obj->unk_64[2]; obj->unk_A4[3] = obj->unk_64[3]; obj->unk_A4[4] = obj->unk_64[4]; obj->unk_A4[5] = obj->unk_64[5]; obj->unk_A4[6] = obj->unk_64[6]; obj->unk_A4[7] = obj->unk_64[7]; obj->unk_A4[8] = obj->unk_64[8]; obj->unk_A4[9] = obj->unk_64[9]; obj->unk_A4[10] = obj->unk_64[10]; obj->unk_A4[11] = obj->unk_64[11]; obj->unk_A4[12] = obj->unk_64[12]; obj->unk_A4[13] = obj->unk_64[13]; obj->unk_A4[14] = obj->unk_64[14]; obj->unk_A4[15] = obj->unk_64[15];
    if (func_80080D08(work) != 0) {
        obj->unk_E4[0] = obj->unk_64[0]; obj->unk_E4[1] = obj->unk_64[1]; obj->unk_E4[2] = obj->unk_64[2]; obj->unk_E4[3] = obj->unk_64[3]; obj->unk_E4[4] = obj->unk_64[4]; obj->unk_E4[5] = obj->unk_64[5]; obj->unk_E4[6] = obj->unk_64[6]; obj->unk_E4[7] = obj->unk_64[7]; obj->unk_E4[8] = obj->unk_64[8]; obj->unk_E4[9] = obj->unk_64[9]; obj->unk_E4[10] = obj->unk_64[10]; obj->unk_E4[11] = obj->unk_64[11]; obj->unk_E4[12] = obj->unk_64[12]; obj->unk_E4[13] = obj->unk_64[13]; obj->unk_E4[14] = obj->unk_64[14]; obj->unk_E4[15] = obj->unk_64[15];
        obj->unk_1C8 = 1;
        func_80016F0C(obj->unk_64, pose);
        dir[0] = obj->unk_64[0];
        dir[1] = obj->unk_64[1];
        dir[2] = 0.0f;
        pose[0] = pose[0] + dir[0] * -10.0f;
        pose[1] = pose[1] + dir[1] * -10.0f;
        pose[2] = pose[2] + dir[2] * -10.0f;
        pose[4] = 0.0f;
        pose[5] = 0.0f;
        for (i = 0; i < 3; i++) {
            func_80017D18(obj->unk_10[i], pose);
            pose[0] = pose[0] + dir[0] * 10.0f;
            pose[1] = pose[1] + dir[1] * 10.0f;
            pose[2] = pose[2] + dir[2] * 10.0f;
        }
        func_80016F0C(work, pose);
        dir[0] = work[0];
        dir[1] = work[1];
        dir[2] = 0.0f;
        pose[0] = pose[0] + dir[0] * -10.0f;
        pose[1] = pose[1] + dir[1] * -10.0f;
        pose[2] = pose[2] + dir[2] * -10.0f;
        pose[4] = 0.0f;
        pose[5] = 0.0f;
        for (i = 3; i != 6; i++) {
            func_80017D18(obj->unk_10[i], pose);
            pose[0] = pose[0] + dir[0] * 10.0f;
            pose[1] = pose[1] + dir[1] * 10.0f;
            pose[2] = pose[2] + dir[2] * 10.0f;
        }
        result[0] = work[0]; result[1] = work[1]; result[2] = work[2]; result[3] = work[3]; result[4] = work[4]; result[5] = work[5]; result[6] = work[6]; result[7] = work[7]; result[8] = work[8]; result[9] = work[9]; result[10] = work[10]; result[11] = work[11]; result[12] = work[12]; result[13] = work[13]; result[14] = work[14]; result[15] = work[15];
    } else {
        func_80016F0C(obj->unk_64, pose);
        dir[0] = obj->unk_64[0];
        dir[1] = obj->unk_64[1];
        dir[2] = 0.0f;
        pose[0] = pose[0] + dir[0] * -25.0f;
        pose[1] = pose[1] + dir[1] * -25.0f;
        pose[2] = pose[2] + dir[2] * -25.0f;
        pose[4] = 0.0f;
        pose[5] = 0.0f;
        for (i = 0; i != 6; i++) {
            func_80017D18(obj->unk_10[i], pose);
            pose[0] = pose[0] + dir[0] * 10.0f;
            pose[1] = pose[1] + dir[1] * 10.0f;
            pose[2] = pose[2] + dir[2] * 10.0f;
        }
        result[0] = obj->unk_64[0]; result[1] = obj->unk_64[1]; result[2] = obj->unk_64[2]; result[3] = obj->unk_64[3]; result[4] = obj->unk_64[4]; result[5] = obj->unk_64[5]; result[6] = obj->unk_64[6]; result[7] = obj->unk_64[7]; result[8] = obj->unk_64[8]; result[9] = obj->unk_64[9]; result[10] = obj->unk_64[10]; result[11] = obj->unk_64[11]; result[12] = obj->unk_64[12]; result[13] = obj->unk_64[13]; result[14] = obj->unk_64[14]; result[15] = obj->unk_64[15];
        obj->unk_E4[0] = obj->unk_A4[0]; obj->unk_E4[1] = obj->unk_A4[1]; obj->unk_E4[2] = obj->unk_A4[2]; obj->unk_E4[3] = obj->unk_A4[3]; obj->unk_E4[4] = obj->unk_A4[4]; obj->unk_E4[5] = obj->unk_A4[5]; obj->unk_E4[6] = obj->unk_A4[6]; obj->unk_E4[7] = obj->unk_A4[7]; obj->unk_E4[8] = obj->unk_A4[8]; obj->unk_E4[9] = obj->unk_A4[9]; obj->unk_E4[10] = obj->unk_A4[10]; obj->unk_E4[11] = obj->unk_A4[11]; obj->unk_E4[12] = obj->unk_A4[12]; obj->unk_E4[13] = obj->unk_A4[13]; obj->unk_E4[14] = obj->unk_A4[14]; obj->unk_E4[15] = obj->unk_A4[15];
    }
    result[14] = result[14] + 22.0f;
    func_80017824(result, 180.0f, 0.0f, 0.0f, 1.0f, result);
    func_80017BA8(obj->unk_28, result);
    func_8000EA4C(obj->unk_28, -1, -1, 0, 0xFF, 0, 0);
    if (obj->unk_28 != 0) {
        func_800181BC(obj->unk_28, 2, 3, 0x10, 2);
    }
}
