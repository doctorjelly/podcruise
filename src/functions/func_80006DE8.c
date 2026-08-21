/* Independently written from scratchpad spec specs/func_80006DE8.md. */

#include "podcruise/types.h"
typedef struct PcEntity {
    u8 unk000[0xF0];
    f32 unk0F0;
    f32 unk0F4;
    f32 unk0F8;
} PcEntity;
void func_80006DE8(PcEntity *entity, f32 lower, f32 upper) {
    if (upper < lower) {
        while (1) {
        }
    }
    if (lower < 0.0f) {
        lower = 0.0f;
    }
    if (upper < 0.0f) {
        upper = 0.0f;
    }
    entity->unk0F0 = lower;
    entity->unk0F4 = upper;
    entity->unk0F8 = upper - lower;
}
