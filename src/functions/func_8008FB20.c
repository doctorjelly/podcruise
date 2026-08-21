/* Recovered per scratchpad spec specs/func_8008FB20.md. */
#include "podcruise/types.h"

typedef struct Node {
    /* 0x00 */ struct Node *unk00;
    /* 0x04 */ struct Node *unk04;
    /* 0x08 */ union { s32 value; struct Node *node; } unk08;
    /* 0x0C */ s16 unk0C;
} Node;

extern void func_80088020(Node *);
extern void func_80088050(Node *, Node *);
extern u32 func_80090500(u32);

void func_8008FB20(anchor, key)
Node *anchor;
s16 key;
{
    s32 spare[2];
    Node *node;
    Node *next;
    u32 saved;

    (void)spare;
    saved = func_80090500(1);
    node = anchor->unk08.node;
    while (node != 0) {
        next = node->unk00;
        if (key == node->unk0C) {
            if (next != 0) {
                next->unk08.value += node->unk08.value;
            }
            func_80088020(node);
            func_80088050(node, anchor);
        }
        node = next;
    }
    func_80090500(saved);
}
