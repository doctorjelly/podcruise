/* Independently written from scratchpad spec specs/func_800521C0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x08];
    /* 0x08 */ s32 flags;
    /* 0x0C */ u8 unk0C[0x68];
    /* 0x74 */ f32 unk74;
} PcRaceEntity;

extern f32 D_800ACE38;
extern f32 func_80052134(PcRaceEntity *entity);

f32 func_800521C0(PcRaceEntity *entity) {
    if ((entity->flags & 2) == 0) {
        return func_80052134(entity);
    }
    return D_800ACE38 - entity->unk74;
}
