/* Independently written from $S/specs/func_8002D6EC.md */
#include "podcruise/types.h"

typedef struct Rec8002D6EC {
    s8 unk00;
    u8 unk01;
    u8 pad02[2];
    f32 unk04[13];
} Rec8002D6EC;

typedef struct Obj8002D6EC {
    u8 pad00[0x34];
    s32 unk34;
    s32 unk38;
    u8 pad3C[0x72 - 0x3C];
    s8 unk72;
} Obj8002D6EC;

typedef struct Table8002D6EC {
    u8 pad00[0x18];
    s32 unk18;
} Table8002D6EC;

extern s32 D_800A21A8;
extern u8 D_800A2DE0[];
extern u8 D_800A2DE1[];
extern u8 D_800A2DE3[];
extern s32 D_800D6CC8;
extern s32 D_800D6CCC;
extern Table8002D6EC D_80113E60;
extern Rec8002D6EC D_801198A8[];
extern Rec8002D6EC D_8011A050[];
extern u8 D_8011A206[];
extern s32 D_8011A270;

extern void func_80015288(f32 *destination, f32 *source);
extern void func_80029C24(void);
extern void func_80051994(s32 first, s32 second);
extern void func_800519C0(s32 index, s32 slot, s32 mode, s32 level);

void func_8002D6EC(Obj8002D6EC *obj) {
    u8 value;
    Rec8002D6EC saved;
    u8 kind;
    f32 vec[3];

    kind = D_800A2DE3[D_801198A8[D_8011A270].unk00 * 16];
    value = ((u8 *)&D_80113E60 + kind)[0x24];
    D_80113E60.unk18 = D_80113E60.unk18 - D_800D6CCC;
    D_80113E60.unk18 = D_80113E60.unk18 + D_800D6CC8;
    if (obj->unk38 == 1) {
        D_8011A206[obj->unk34 * 3] = value;
    }
    saved = D_801198A8[D_8011A270];
    D_801198A8[D_8011A270] = D_8011A050[kind];
    D_8011A050[kind] = saved;
    func_80015288(vec, D_801198A8[D_8011A270].unk04);
    func_80015288(D_801198A8[D_8011A270].unk04, D_8011A050[kind].unk04);
    func_80015288(D_8011A050[kind].unk04, vec);
    ((u8 *)&D_80113E60 + kind)[0x24] = D_8011A050[kind].unk01;
    ((u8 *)&D_80113E60 + kind)[0x1D] = D_800A2DE1[D_8011A050[kind].unk00 * 16];
    func_80051994(D_8011A270 + 0x62, kind + 0x8E);
    D_800A21A8 = 1;
    func_800519C0(obj->unk72,
                  D_800A2DE0[D_801198A8[D_8011A270].unk00 * 16 + 3],
                  D_800A2DE0[D_801198A8[D_8011A270].unk00 * 16 + 1],
                  D_801198A8[D_8011A270].unk01);
    func_80029C24();
}
