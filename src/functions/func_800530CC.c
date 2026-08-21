/* Implements the specification in specs/func_800530CC.md (mode reset and entity flag sweep). */
#include "podcruise/types.h"

typedef struct Subject {
    u8 pad0[0x60];
    s32 unk60;
    s32 unk64;
} Subject;

typedef struct Entry {
    u8 pad0[0x84];
    Subject *unk84;
} Entry;

typedef struct Owner {
    u8 pad0[0x8];
    s32 unk8;
    f32 unkC;
    u8 pad10[0x1AC];
    s32 unk1BC;
} Owner;

extern f32 D_8009B8C8;
extern f32 D_800ACE64;
extern f32 D_800ACE68;
extern Entry *D_8011B1B8;

extern s32 func_8000AB24(s32, s32, s32, s32, s32);
extern s32 func_8002F1CC(void);
extern s32 func_8003FA24(s32, u32 *);
extern s32 func_80052A08(Owner *, s32);

void func_800530CC(Owner *owner) {
    u32 tag[16];
    s32 index;
    s32 offset;

    D_8009B8C8 = D_800ACE64;
    tag[0] = 0x53776565;
    tag[1] = 0;
    func_8003FA24(0x634D616E, tag);

    owner->unk8 = owner->unk8 & ~0xF;
    owner->unkC = D_800ACE68;
    if (owner->unk8 & 0x20) {
        owner->unk8 = owner->unk8 & ~0xF00;
    } else {
        owner->unk8 = owner->unk8 | 0xF00;
    }

    if (owner->unk8 & 0x20) {
        owner->unkC = -1.0f;
    } else {
        func_8002F1CC();
    }

    func_80052A08(owner, 4);

    if (!(owner->unk8 & 0x20)) {
        func_8000AB24(-0x67, 0, 0, 0, 0);
    }

    for (index = 0, offset = 0; index < owner->unk1BC; index++, offset += 0x88) {
        if (((Entry *)((u8 *)D_8011B1B8 + offset))->unk84 != 0) {
            Subject *subject = ((Entry *)((u8 *)D_8011B1B8 + offset))->unk84;
            subject->unk64 = subject->unk64 & ~0x1000; subject->unk60 = (subject->unk60 & ~0xF) | 1;
        }
    }
}
