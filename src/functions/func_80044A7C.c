/* Recovered from specs/functions/recovered/medium_service_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    u8 unk_00[0x30];
} PcJointA;

typedef struct {
    u8 unk_00[0x58];
} PcJointB;

typedef struct {
    u8 unk_000[0xEC];
    s32 unk_0EC[6];
    u8 unk_104[0x360];
    PcJointA unk_464[12];
    u8 unk_6A4[0x588];
    PcJointB unk_C2C[12];
} PcObject;

extern f32 D_800AAD08;

extern void func_80083190(PcJointA *source, f32 matrix[4][4]);
extern f32 func_800154D0(f32 *vector);
extern void func_80015288(f32 *destination, f32 *source);
extern void func_80015538(f32 *output, f32 *left, f32 *right);
extern void func_800155C0(f32 *output, f32 scale, f32 *source);
extern void func_800155EC(f32 *output, f32 *source, f32 scale, f32 *addend);
extern void func_80017520(f32 *matrix, f32 x, f32 y, f32 z);
extern void func_80017BA8(void *destination, void *source);

void func_80044A7C(PcObject *object) {
    f32 head[3];
    f32 tail[3];
    f32 delta[3];
    f32 side[3];
    f32 frame[4][4];
    f32 work[4][4];
    s32 index;
    f32 length;

    for (index = 0; index != 6; index++) {
        if (object->unk_0EC[index] == 0) {
            continue;
        }
        if (*(s32 *)&object->unk_464[index + 6] == 0) {
            continue;
        }
        if (*(s32 *)&object->unk_464[index] == 0) {
            continue;
        }

        func_80083190(&object->unk_464[index + 6], work);
        head[0] = work[3][0];
        head[1] = work[3][1];
        head[2] = work[3][2];

        func_80083190(&object->unk_464[index], work);
        delta[0] = head[0] - work[3][0]; tail[0] = work[3][0];
        delta[1] = head[1] - work[3][1]; tail[1] = work[3][1];
        delta[2] = head[2] - work[3][2]; tail[2] = work[3][2];

        length = func_800154D0(delta);
        side[0] = delta[1];
        side[1] = -delta[0];
        side[2] = 0.0;
        func_800154D0(side);

        func_80015538(frame[0], delta, side);
        func_80015288(frame[2], delta);
        func_80015288(frame[1], side);
        frame[0][3] = 0.0f;
        frame[1][3] = 0.0f;
        frame[2][3] = 0.0f;
        frame[3][3] = 1.0f;
        func_800155C0(frame[3], 0.5f, head);
        func_800155EC(frame[3], frame[3], 0.5f, tail);

        func_80017BA8(&object->unk_C2C[index], frame);
        func_80017520(frame[0], D_800AAD08, 1.0f, length / 20.0f);
        func_80017BA8(&object->unk_C2C[index + 6], frame);
    }
}
