/* Recovered from specification $S/specs/func_8007BBEC.md */
#include "podcruise/types.h"

typedef struct Sub8007BBEC {
    u8 pad00[0x20];
    void *unk20;
} Sub8007BBEC;

typedef struct Obj8007BBEC {
    u8 pad00[0xC];
    s32 unkC;
    f32 unk10;
    u8 pad14[0x4C - 0x14];
    Sub8007BBEC *unk4C;
    s32 unk50;
    s32 unk54;
} Obj8007BBEC;

typedef struct Tag8007BBEC {
    u32 unk0;
    f32 unk4;
    f32 unk8;
} Tag8007BBEC;

extern f32 D_800ADB60;
extern void *D_8011C910[];

extern void func_80083D80(void *, f32 *, s32);
extern s32 func_800181BC(void *, s32, s32, s32, s32);
extern void func_80017B7C(void *, f32, f32, f32);
extern void func_8007B6CC(s32);
extern s32 func_8007B430(void *);
extern void func_8003FA24(u32, Tag8007BBEC *);
extern void func_8007B744(s32);
extern void func_8003FD7C(Obj8007BBEC *);

void func_8007BBEC(Obj8007BBEC *self, s32 arg1);

void func_8007BBEC(Obj8007BBEC *self, s32 arg1) {
    register s32 index;
    Tag8007BBEC tag;
    f32 box[23];
    f32 mid[3];
    f32 extra[1];

    (void)extra;
    index = arg1;
    if (!(self->unkC & 4)) {
        if (1.5f < self->unk10) {
            self->unkC |= 4;
            func_80083D80(self->unk4C->unk20, box, 0);
            mid[0] = box[0] + box[3]; mid[1] = box[1] + box[4]; mid[2] = box[2] + box[5];
            mid[0] = mid[0] * 0.5f;
            mid[1] = mid[1] * 0.5f;
            mid[2] = mid[2] * 0.5f;
            if (self->unk4C->unk20 != 0) {
                func_800181BC(self->unk4C->unk20, 2, -4, 0x10, 3);
            }
            func_800181BC(self->unk4C->unk20, 0, -3, 0x10, 3);
            func_80017B7C(D_8011C910[index], mid[0], mid[1], mid[2]);
            if (D_8011C910[index] != 0) {
                func_800181BC(D_8011C910[index], 2, 3, 0x10, 2);
            }
            func_8007B6CC(index);
            self->unk50 = 0;
            self->unk54 = func_8007B430(D_8011C910[index]);
            self->unk10 = 0.0f;
        }
    } else if (D_800ADB60 < self->unk10) {
        tag.unk0 = 0x5368616B;
        tag.unk4 = 0.0f;
        tag.unk8 = 0.0f;
        func_8003FA24(0x634D616E, &tag);
        func_8007B744(index);
        if (D_8011C910[index] != 0) {
            func_800181BC(D_8011C910[index], 2, -4, 0x10, 3);
        }
        self->unkC = self->unkC & ~1;
        func_8003FD7C(self);
    }
}
