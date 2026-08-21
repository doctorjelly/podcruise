/* Recovered from specification: specs/func_80052E44.md (worker scratchpad) */
#include "podcruise/types.h"

typedef struct Subject {
    u8 pad0[0x2C4];
    f32 unk2C4;
} Subject;

typedef struct Entry {
    u8 pad0[0x80];
    f32 unk80;
    Subject *unk84;
} Entry;

typedef struct Owner {
    u8 pad0[0x6];
    s16 unk6;
    s32 unk8;
    u8 pad10[0x1B0];
    s32 unk1BC;
} Owner;

extern s32 D_8009B80C;
extern f32 D_8009B8C8;
extern s32 D_800A52B0;
extern s32 D_800A52D8;
extern s32 D_800A6950;
extern s32 D_800A6954[2];
extern s32 D_800A695C[2];
extern f32 D_800ACE60;
extern s32 D_800D6960[];
extern Entry *D_8011B1B8;

extern void func_80008750(u8);
extern void func_8000955C(s32, s32);
extern void func_80009F6C(void);
extern void func_8000A4D8(void);
extern void func_8000AB24(s16, u8, u8, u8, u8);
extern void func_8000AEFC(s16, s16, u32, s16);
extern void func_8000FE1C(void);
extern void func_8000FE78(void);
extern void func_8000FEF0(void);
extern void func_80011838(void);
extern void func_80011918(void);
extern void func_80030304(s32);
extern void func_80031F94(void);
extern void func_80039EC0(s32);
extern void func_8003FA24(u32, void *);
extern s32 func_80052A08(Owner *, s32);
extern void func_80060880(Owner *, Entry *);
extern void func_800811CC(void);
extern void func_80087754(void *);

void func_80052E44(Owner *owner, u32 tag) {
    u32 name[16];
    s32 index;

    D_8009B8C8 = D_800ACE60;
    func_80009F6C();
    for (index = 0; index < 12; index++) {
        func_8000955C(index, 0xFF0000);
    }
    D_8009B80C = 1;
    func_8000AB24(-0x67, 0, 0, 0, 255);

    for (index = 0; index < owner->unk1BC; index++) {
        if (((Entry *)((u8 *)D_8011B1B8 + index * 0x88))->unk84 != 0) {
            ((Entry *)((u8 *)D_8011B1B8 + index * 0x88))->unk80 =
                ((Entry *)((u8 *)D_8011B1B8 + index * 0x88))->unk84->unk2C4;
        }
        ((Entry *)((u8 *)D_8011B1B8 + index * 0x88))->unk84 = 0;
    }

    func_80030304(0x54657374);
    func_80030304(0x546F7373);
    func_80030304(0x536D6F6B);
    func_80030304(0x54726967);
    func_80030304(0x43687372);
    func_80039EC0(1);
    func_80052A08(owner, 1);
    func_80008750(0);
    D_800A6954[0] = 0;
    D_800A695C[0] = 0;
    D_800A6954[1] = 0;
    D_800A695C[1] = 0;
    D_800A6950 = 0;
    func_80011918();
    func_8000FEF0();
    func_80011838();
    func_8000FE1C();
    func_8000FE78();
    func_8000A4D8();
    func_80031F94();
    D_800D6960[7] = D_800D6960[7] & ~0x4000;
    func_80087754(0);
    func_8000AEFC(1, 0, 0, 0);
    func_8000AEFC(5, 0, 0, 0);

    if ((D_800A52B0 & 2) && tag == 0x46696E69) {
        func_80060880(owner, D_8011B1B8);
        func_800811CC();
        owner->unk8 = (owner->unk8 & ~0xF) | 3;
    } else {
        owner->unk6 = owner->unk6 | 0x1000;
        name[0] = 0x52536574;
        func_8003FA24(0x634D616E, name);
        if (D_800A52D8 != 0) {
            tag = 0x41627274;
        }
        name[0] = tag;
        func_8003FA24(0x416C6C21, name);
    }
}
