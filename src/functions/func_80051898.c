/* Specification: specs/func_80051898.md (worker-authored) */
#include "podcruise/types.h"

typedef struct Entity {
    u8 pad0[6];
    s16 unk6;
    u8 pad8[0x28];
    u32 unk30;
    u32 unk34;
} Entity;

extern void func_8002FA00(void);
extern s32 func_8002FB18(u32);
extern Entity *func_8003F800(u32, s32);

void func_80051898(void) {
    Entity *entity;
    s32 i;

    func_8002FA00();
    for (i = 0; i != 60; i++) {
        entity = func_8003F800(0x456C6D6F, i);
        if (entity != 0) {
            if (!func_8002FB18(entity->unk30) || !func_8002FB18(entity->unk34)) {
                if (!(entity->unk6 & 0x100)) {
                    entity->unk6 |= 0x100;
                }
            }
        }
    }
}
