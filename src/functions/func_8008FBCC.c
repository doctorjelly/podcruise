/* Recovered per specs/func_8008FBCC.md (worker specification). */
#include "podcruise/types.h"

typedef struct Node {
    struct Node *unk0;
} Node;

typedef struct Owner {
    s32 unk0;
    s32 unk4;
    Node *unk8;
} Owner;

extern s32 func_80090500(s32);
extern void func_80088020(Node *);
extern void func_80088050(Node *, Owner *);

void func_8008FBCC(Owner *owner) {
    s32 count;
    s32 limit;
    s32 saved;
    Node *node;
    Node *next;

    saved = func_80090500(1);
    limit = 0;
    count = limit;
    node = owner->unk8;
    if (node != 0) {
        do {
            next = node->unk0;
            func_80088020(node);
            func_80088050(node, owner);
            node = next;
        } while (next != 0);
    }
    (void)count;
    func_80090500(saved);
}
