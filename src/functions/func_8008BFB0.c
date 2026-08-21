/* Implements the specification in specs/func_8008BFB0.md (worker-authored). */
#include "podcruise/types.h"

struct Node8008BFB0 {
    s32 unk0;
    s32 unk4;
    struct Node8008BFB0 *unk8;
    s32 unkC;
    u16 unk10;
};

extern struct Node8008BFB0 *D_800A7BB8;
extern struct Node8008BFB0 *D_800A7BC0;

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32 token);
extern void func_8008CAC0(struct Node8008BFB0 *parent, struct Node8008BFB0 *node);
extern void func_8008D12C(struct Node8008BFB0 **slot);
extern void func_8008D22C(struct Node8008BFB0 *parent, struct Node8008BFB0 *node);

void func_8008BFB0(struct Node8008BFB0 *node, s32 value) {
    register s32 token;

    token = func_8008CA80();
    if (node == 0) {
        node = D_800A7BC0;
    }
    if (node->unk4 != value) {
        node->unk4 = value;
        if (node != D_800A7BC0 && node->unk10 != 1) {
            func_8008CAC0(node->unk8, node);
            func_8008D22C(node->unk8, node);
        }
        if (D_800A7BC0->unk4 < D_800A7BB8->unk4) {
            D_800A7BC0->unk10 = 2;
            func_8008D12C(&D_800A7BB8);
        }
    }
    func_8008CAA0(token);
}
