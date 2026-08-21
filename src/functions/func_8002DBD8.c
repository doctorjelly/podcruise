/* Independently written from the specification for func_8002DBD8. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct {
    /* 0x00 */ PcVec3f unk00;
    /* 0x0C */ PcVec3f unk0C;
    /* 0x18 */ u8 pad18[0x8];
} PcSlotRecord;

typedef struct {
    /* 0x00 */ u8 pad00[0x34];
    /* 0x34 */ s32 unk34;
} PcSlotOwner;

extern PcSlotRecord D_800A4C00[];
extern PcVec3f D_80118E10;
extern PcVec3f D_80118E50;
extern PcVec3f D_80118ED0;

s32 func_8002DBD8(PcSlotOwner *owner) {
    s32 result;

    result = !func_800152CC(&D_800A4C00[owner->unk34].unk0C, &D_80118E50);
    if (result == 0) {
        result = !func_800152CC(&D_800A4C00[owner->unk34].unk0C, &D_80118ED0);
        if (result == 0) {
            result = !func_800152CC(&D_800A4C00[owner->unk34].unk00, &D_80118E10);
        }
    }
    return result;
}
