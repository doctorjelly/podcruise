/* Independently written from scratchpad specs/func_8003FBDC.md (corrected boundary: entry 0x8003FBD4). */

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
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    void (*unk24)(Slot *, s32 *, s32 *);
} Pool;

extern Pool **D_800A2170;
extern void func_8003F99C(Slot *slot, s32 *message);

Slot *func_8003FBD4(s32 key) {
    Pool **list;
    Pool *pool;
    Slot *slot;
    s32 index;

    for (list = D_800A2170; *list != 0; list++) {
        pool = *list;
        if (pool->unk00 == key) {
            if (pool->unk24 != 0) {
                slot = pool->unk10;
                for (index = 0; index < pool->unk08; ) {
                    index++;
                    if (slot->unk06 & 0x100) {
                        s32 message[9];

                        slot->unk06 &= ~0x100;
                        message[0] = 0x416C6F63;
                        message[8] = (s32)(long)slot;
                        func_8003F99C(slot, message);
                        return (Slot *)(long)message[8];
                    }
                    slot = (Slot *)((u8 *)slot + pool->unk0C);
                }
            }
            return 0;
        }
    }
    return 0;
}
