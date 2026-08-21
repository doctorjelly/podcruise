/* Recovered per specs/func_8004AF60.md (worker specification). */
#include "podcruise/types.h"

typedef struct Entity {
    u8 pad0[0x14];
    s32 unk14;
    u8 pad18[0x48];
    u8 unk60;
} Entity;

typedef struct Control {
    u8 pad0[0x20];
    s16 unk20;
} Control;

extern Control D_800D6960;
extern void func_80017F28(s32);
extern void func_80020030(Entity *);
extern void func_80086CC8(s32, s32, s32);

void func_8004AF60(Entity *entity) {
    func_80017F28(1);
    if (entity->unk14 & 1) {
        D_800D6960.unk20 |= 2;
        func_80086CC8(0, 0, 0);
        if (entity->unk60 != 0) {
            func_80020030(entity);
        }
    }
}
