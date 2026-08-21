/* Independently written from specs/functions/func_8003F714.md. */

#include "podcruise/types.h"

typedef struct Slot {
    s32 unk00;
    s16 unk04;
    s16 unk06;
} Slot;

typedef struct Pool {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    Slot *unk10;
} Pool;

extern Pool **D_800A2170;

Slot *func_8003F714(s32 id, s32 key) {
    Pool **list;
    Pool *pool;
    Slot *slot;
    s16 index;

    for (list = D_800A2170; *list != 0; list++) {
        pool = *list;
        if (pool->unk00 == id) {
            slot = pool->unk10;
            for (index = 0; index < pool->unk08; index++) {
                if (!(slot->unk06 & 0x100)) {
                    if (slot->unk04 == key) {
                        return slot;
                    }
                }
                slot = (Slot *)((u8 *)slot + pool->unk0C);
            }
        }
    }
    return 0;
}
