/* Implements specification $S/specs/func_80082FA4.md */
#include "podcruise/types.h"

typedef struct Node80082FA4 {
    s32 unk0[6];
    struct Node80082FA4 **children;
} Node80082FA4;

extern s32 func_80017DA4(Node80082FA4 *node);
extern s32 func_80017DAC(Node80082FA4 *node);
void func_80082FA4(Node80082FA4 *target, Node80082FA4 *node, Node80082FA4 **out,
                   s32 index, s32 limit, s32 *done);

void func_80082FA4(Node80082FA4 *target, Node80082FA4 *node, Node80082FA4 **out,
                   s32 index, s32 limit, s32 *done) {
    s32 scratch[3];
    s32 flags;
    s32 count;
    s32 i;
    s32 next;

    (void)scratch;

    if (node != 0) {
        if (index < limit - 1) {
            if (*done == 0) {
                flags = func_80017DA4(node);
                if (target == node) {
                    *done = 1;
                    if (flags & 0x8000) {
                        out[index + 1] = 0;
                    } else {
                        out[index] = 0;
                    }
                } else if (flags & 0x4000) {
                    if (flags & 0x8000) {
                        next = index + 1;
                    } else {
                        next = index;
                    }
                    count = func_80017DAC(node);
                    for (i = 0; i < count && *done == 0; i++) {
                        if (node->children[i] != 0) {
                            func_80082FA4(target, node->children[i], out, next, limit, done);
                        }
                    }
                }
                if (flags & 0x8000) {
                    if (*done != 0) {
                        out[index] = node;
                    }
                }
            }
        }
    }
}
