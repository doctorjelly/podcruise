/* Independently written from specs/functions/recovered/medium_leaf_tranche.md. */

#include "podcruise/types.h"

typedef struct Node80007728 {
    /* 0x0000 */ struct Node80007728 *unk0;
    /* 0x0004 */ struct Node80007728 *unk4;
    /* 0x0008 */ u8 pad8[0x4];
    /* 0x000C */ s32 unkC;
} Node80007728;

extern u8 D_800B0498[];
extern Node80007728 *D_800AFAC0[2];
extern u32 D_800AFE88;

extern void func_80087E80(void *arg0, s32 *arg1, s32 arg2);
extern void func_80088020(Node80007728 *node);
extern void func_80088050(Node80007728 *node, Node80007728 *after);

void func_80007728(s32 count) {
    s32 index;
    s32 scratch;
    Node80007728 *node;
    Node80007728 *next;
    Node80007728 *tail;

    for (index = 0; index < count; index++) {
        func_80087E80(D_800B0498, &scratch, 0);
    }

    node = D_800AFAC0[0];
    while (node != 0) {
        next = node->unk0;
        if ((u32)(node->unkC + 1) < D_800AFE88) {
            if (node == D_800AFAC0[0]) {
                D_800AFAC0[0] = node->unk0;
            }
            func_80088020(node);
            tail = D_800AFAC0[1];
            if (tail != 0) {
                func_80088050(node, tail);
            } else {
                D_800AFAC0[1] = node;
                node->unk0 = 0;
                node->unk4 = 0;
            }
        }
        node = next;
    }
}
