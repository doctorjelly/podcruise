/* Specification: specs/func_80050450.md (worker scratchpad) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ f32 first[3];
    /* 0x0C */ f32 second[3];
    /* 0x18 */ u8 pad18[0x8];
} PcPlacement;

typedef struct {
    /* 0x00 */ u8 pad00[0x34];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ u8 pad38[0x38];
    /* 0x70 */ s8 count;
} PcOwner;

typedef struct {
    /* 0x00 */ u8 pad00[0x68];
    /* 0x68 */ f32 unk68;
} PcEntity;

extern PcPlacement D_800A4C00[];
extern f32 D_801195F0[];
extern void *D_8011A508[];

extern void func_80015288(f32 *, f32 *);
extern void func_800513E0(PcOwner *, s32);
extern PcEntity *func_8003F800(u32, s32);
extern void func_80033590(void *, f32 *);
extern f32 func_80014F54(f32, f32);
extern void func_80063084(s32, s32, f32 *, f32 *, f32, f32);

void func_80050450(PcOwner *owner) {
    f32 sp60[3];
    f32 first[3];
    f32 second[3];
    s32 i;
    s32 id;
    PcEntity *entity;

    func_80015288(first, D_800A4C00[owner->unk34].first);
    func_80015288(second, D_800A4C00[owner->unk34].second);
    for (i = 0; i < owner->count; i++) {
        func_800513E0(owner, i);
        id = i + 0x1C;
        entity = func_8003F800(0x456C6D6F, id);
        if (entity != 0) {
            func_80033590(D_8011A508[i + 28], sp60);
            func_80063084(id, 0x14, sp60, D_801195F0, entity->unk68,
                          func_80014F54(D_801195F0[0] - second[0], second[1] - D_801195F0[1]));
        }
    }
}
