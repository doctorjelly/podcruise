/* Independently written from specs/functions/func_8003F99C.md. */

#include "podcruise/types.h"

typedef struct Slot {
    s32 unk00;
    s16 unk04;
    s16 unk06;
} Slot;

typedef struct Message Message;

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
    void (*unk24)(Slot *, Message *, Message *);
} Pool;

extern Pool **D_800A2170;

void func_8003F99C(Slot *slot, Message *message) {
    Pool **list;
    Pool *pool;

    if (slot != 0) {
        for (list = D_800A2170; *list != 0; list++) {
            pool = *list;
            if (pool->unk00 == slot->unk00) {
                if (pool->unk24 != 0) {
                    if ((slot->unk06 & 0x100) == 0) {
                        pool->unk24(slot, message, message);
                    }
                }
                return;
            }
        }
    }
}
