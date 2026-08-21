/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

typedef struct Ent80029330 {
    u8 pad0[8];
    s32 unk8;
} Ent80029330;

typedef struct Obj80029330 {
    u8 pad0[0x40];
    s32 unk40;
    u8 pad44[0x28];
    s8 unk6C;
} Obj80029330;

extern s32 D_8011A508[];

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80063084(s32, s32, f32 *, f32 *, f32, f32);
extern void func_80063AA0(s32, s32);
extern Ent80029330 *func_8003F800(u32, s32);

void func_8002932C(Obj80029330 *obj) {
    s32 unused;
    f32 place[3];
    Ent80029330 *entry;
    s16 index;

    (void)unused;
    func_80015268(place, 0.0f, 0.0f, 0.0f);
    func_80063084(0x1C, 0x1B, place, place, 0.0f, 0.0f);
    func_80063AA0(0x4, 0x43);
    func_80063AA0(0x16, 0x2A);
    func_80063AA0(0x17, 0x2E);
    if (obj->unk6C != 0) {
        obj->unk40 = 0x39;
    } else {
        obj->unk40 = 0x38;
    }
    for (index = 0x38; index < 0x3B; index++) {
        entry = func_8003F800(0x456C6D6F, index);
        if (entry != 0) {
            if (index != obj->unk40 && entry->unk8 != 1) {
                if (D_8011A508[index] != 0) {
                    func_80063AA0(index, 0x11);
                }
            } else if (D_8011A508[index] != 0) {
                func_80063AA0(index, 0);
            }
        }
    }
    obj->unk40 = -1;
}
