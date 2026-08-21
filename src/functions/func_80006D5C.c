/* Independently written from scratchpad spec specs/func_80006D5C.md. */

#include "podcruise/types.h"
typedef struct PcEntity {
    u8 unk000[0x100];
    u32 unk100;
    u8 unk104[0x20];
    void *unk124;
} PcEntity;
extern s32 D_8009A2A0;
extern PcEntity *D_800AF4C0[300];
PcEntity *func_80006D5C(void *owner, s32 kind) {
    PcEntity *entity;
    s32 i;

    if (owner == 0) {
        return 0;
    }
    for (i = 0; i < D_8009A2A0; i++) {
        entity = D_800AF4C0[i];
        if (entity != 0 && !(entity->unk100 & 0x80000000) &&
            (s32)(entity->unk100 & 0xF) == kind && entity->unk124 == owner) {
            return entity;
        }
    }
    return 0;
}
