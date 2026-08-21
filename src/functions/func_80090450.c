/* Independently written from the specification for func_80090450. */

#include "podcruise/types.h"

typedef struct Node Node;
typedef struct Handler Handler;
typedef struct Target Target;

struct Handler {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ void (*unk08)(Handler *, s32, Node *);
};

struct Target {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ Handler *unk0C;
    /* 0x10 */ u8 pad10[0xC8];
    /* 0xD8 */ u32 unkD8;
};

struct Node {
    /* 0x00 */ u8 pad00[0x4];
    /* 0x04 */ u32 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ Target *unk0C;
};

typedef struct Owner {
    /* 0x00 */ u8 pad00[0x1C];
    /* 0x1C */ u32 unk1C;
} Owner;

typedef struct Holder {
    /* 0x00 */ u8 pad00[0x8];
    /* 0x08 */ Target *unk08;
} Holder;

extern void func_80088450(Owner *owner, Target *target);
extern Node *func_80088500(void);

void func_80090450(Owner *owner, Holder *holder) {
    Node *node;
    Target *target;

    target = holder->unk08;
    if (target == 0) {
        return;
    }

    if (target->unkD8 != 0) {
        node = func_80088500();
        if (node == 0) {
            return;
        }
        node->unk04 = owner->unk1C + holder->unk08->unkD8;
        node->unk08 = 0;
        node->unk0C = holder->unk08;
        holder->unk08->unk0C->unk08(holder->unk08->unk0C, 3, node);
    } else {
        func_80088450(owner, target);
    }

    holder->unk08 = 0;
}
