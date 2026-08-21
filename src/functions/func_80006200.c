/* Independently written from scratchpad spec specs/func_80006200.md. */

#include "podcruise/types.h"

typedef struct PcVec3f80006200 {
    f32 x;
    f32 y;
    f32 z;
} PcVec3f80006200;

typedef struct PcHolder80006200 {
    u8 unk000[0xE4];
    f32 unkE4;
    s32 unkE8;
    s32 unkEC;
    u8 unkF0[0x10];
    s32 unk100;
    u8 unk104[0x10];
    f32 unk114;
    s32 unk118;
    u8 unk11C[0x8];
    void *unk124;
} PcHolder80006200;

extern void func_80005DA8(PcVec3f80006200 *output, PcHolder80006200 *holder,
                          f32 position, s32 index);
extern void func_800155EC(PcVec3f80006200 *output, PcVec3f80006200 *base,
                          f32 scale, PcVec3f80006200 *offset);
extern void func_80017C18(void *source, f32 *destination);
extern void func_80017BA8(void *destination, f32 *source);
extern void func_80081814(f32 *matrix, PcVec3f80006200 *translation,
                          f32 *rotation, PcVec3f80006200 *scale);
extern void func_80081948(f32 *matrix, PcVec3f80006200 *translation,
                          f32 *rotation, PcVec3f80006200 *scale);

void func_80006200(PcHolder80006200 *holder) {
    PcVec3f80006200 primary;
    PcVec3f80006200 secondary;
    f32 matrix[4][4];
    f32 rotation[4][4];
    PcVec3f80006200 translation;
    PcVec3f80006200 scale;

    func_80005DA8(&primary, holder, holder->unk114, holder->unk118);
    if (holder->unk100 & 0x20000000) {
        func_80005DA8(&secondary, holder, (f32)holder->unkEC, holder->unkE8);
        primary.x *= holder->unkE4;
        primary.y *= holder->unkE4;
        primary.z *= holder->unkE4;
        func_800155EC(&primary, &primary, 1.0f - holder->unkE4, &secondary);
    }
    if (holder->unk124 != 0) {
        func_80017C18(holder->unk124, &matrix[0][0]);
        func_80081814(&matrix[0][0], &translation, &rotation[0][0], &scale);
        func_80081948(&matrix[0][0], &translation, &rotation[0][0], &primary);
        func_80017BA8(holder->unk124, &matrix[0][0]);
    }
}
