/* Independently written from specs/functions/recovered/func_8008DCB0.md. */
#include "podcruise/types.h"

typedef struct Element {
    u8 unk_00[0x20];
    u8 unk_20[0x2C];
} Element;

typedef struct Owner {
    u8 unk_00[0x30];
    void *unk_30;
    Element *unk_34;
} Owner;

extern void func_8008D870(void *, void *, void *);
extern void func_800963B4(void *, s32, Element *);
extern void func_8008DD50(void *, s32, void *);
void *func_8008DCB0(Owner *owner, s16 index, void *arg2, void *arg3) {
    Element *element;
    func_8008D870(owner->unk_34[index].unk_20, arg2, arg3);
    element = &owner->unk_34[index];
    func_800963B4(element->unk_20, 1, element);
    func_8008DD50(owner->unk_30, 2, owner->unk_34[index].unk_20);
    return owner->unk_34[index].unk_20;
}
