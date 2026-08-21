/* Implements the specification in specs/func_80088488.md */
#include "podcruise/types.h"

extern void func_80088020(void *);
extern void func_80088050(void *, void *);

struct Obj80088488 {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    void *unk14;
};

void func_80088488(struct Obj80088488 *arg0) {
    void *node;

    node = arg0->unk14;
    while (node != 0) {
        func_80088020(node);
        func_80088050(node, &arg0->unk04);
        node = arg0->unk14;
    }
}
