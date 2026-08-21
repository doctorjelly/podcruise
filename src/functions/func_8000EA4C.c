/* Independently written from specs/func_8000EA4C.md. */

#include "podcruise/types.h"

typedef struct Node {
    u8 unk_00[0x14];
    s32 count;
    u8 ****list;
} Node;

extern void func_8000E9BC(u8 **owner, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f);
extern u32 func_80017DA4(const void *object);
extern s32 func_80017DAC(const void *object);

void func_8000EA4C(Node *node, s16 a, s16 b, s16 c, s16 d, s16 e, s16 f) {
    Node *counted;
    u8 ***entry;
    s32 i;

    if (node == 0) {
        return;
    }
    if (func_80017DA4(node) == 0x3064) {
        counted = node;
        for (i = 0; i < counted->count; i++) {
            entry = node->list[i];
            func_8000E9BC(*entry, a, b, c, d, e, f);
        }
    } else if (func_80017DA4(node) & 0x4000) {
        for (i = 0; i < func_80017DAC(node); i++) {
            func_8000EA4C((Node *)node->list[i], a, b, c, d, e, f);
        }
    }
}
