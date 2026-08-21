/* Specification: scratchpad specs/func_80044CD8.md */
#include "podcruise/types.h"

typedef struct {
    u8 unk_00[0x30];
} PcJointA;

typedef struct {
    u8 unk_00[0x58];
} PcJointB;

typedef struct {
    PcJointB unk_00;
    PcJointB unk_58;
} PcJointPair;

typedef struct {
    u8 unk_000[0xEC];
    s32 unk_0EC[6];
    u8 unk_104[0x360];
    PcJointA unk_464[36];
    u8 unk_B24[0xBEC];
    PcJointPair unk_1710[6];
} PcObject;

extern f32 D_800AAD0C;

extern void func_80083190(PcJointA *source, f32 matrix[4][4]);
extern void func_8001535C(f32 *output, f32 *left, f32 *right);
extern f32 func_800154D0(f32 *vector);
extern void func_80015288(f32 *destination, f32 *source);
extern void func_80015268(f32 *output, f32 x, f32 y, f32 z);
extern void func_80015538(f32 *output, f32 *left, f32 *right);
extern void func_80017580(f32 *matrix, f32 x, f32 y, f32 z);
extern void func_80017918(f32 destination[4][4], f32 x, f32 y, f32 z, f32 source[4][4]);
extern void func_80017BA8(void *destination, f32 source[4][4]);

void func_80044CD8(PcObject *object) {
    f32 head[3];
    f32 tail[3];
    f32 delta[3];
    f32 frame[4][4];
    f32 length;
    f32 work[4][4];
    f32 scale;
    s32 index;

    scale = D_800AAD0C;
    for (index = 0; index != 6; index++) {
        if (object->unk_0EC[index] == 0) {
            continue;
        }
        if (*(s32 *)&object->unk_464[index + 30] != 0 && *(s32 *)&object->unk_464[index + 18] != 0) {
            func_80083190(&object->unk_464[index + 30], work);
            head[0] = work[3][0];
            head[1] = work[3][1];
            head[2] = work[3][2];
            func_80083190(&object->unk_464[index + 18], work);
            tail[0] = work[3][0];
            tail[1] = work[3][1];
            tail[2] = work[3][2];
            func_8001535C(delta, head, tail);
            length = func_800154D0(delta);
            func_80017580(frame[0], head[0], head[1], head[2]);
            func_80015288(frame[1], delta);
            func_80015268(frame[2], 0.0f, 0.0f, 1.0f);
            func_80015538(frame[0], frame[1], frame[2]);
            func_80015538(frame[2], frame[0], frame[1]);
            func_80017918(frame, scale, length / 100.0f, scale, frame);
            func_80017BA8(&object->unk_1710[index].unk_58, frame);
        }
        if (*(s32 *)&object->unk_464[index + 24] != 0 && *(s32 *)&object->unk_464[index + 12] != 0) {
            func_80083190(&object->unk_464[index + 24], work);
            head[0] = work[3][0];
            head[1] = work[3][1];
            head[2] = work[3][2];
            func_80083190(&object->unk_464[index + 12], work);
            tail[0] = work[3][0];
            tail[1] = work[3][1];
            tail[2] = work[3][2];
            func_8001535C(delta, head, tail);
            length = func_800154D0(delta);
            func_80017580(frame[0], head[0], head[1], head[2]);
            func_80015288(frame[1], delta);
            func_80015268(frame[2], 0.0f, 0.0f, 1.0f);
            func_80015538(frame[0], frame[1], frame[2]);
            func_80015538(frame[2], frame[0], frame[1]);
            func_80017918(frame, scale, length / 100.0f, scale, frame);
            func_80017BA8(&object->unk_1710[index].unk_00, frame);
        }
    }
}
