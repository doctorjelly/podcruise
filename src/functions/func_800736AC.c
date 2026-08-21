/* Specification: scratchpad specs/func_800736EC.md (corrected boundary: func_800736AC) */
#include "podcruise/types.h"

typedef struct Node {
    u8 pad_00[0x100];
    u32 unk_100;
    u8 pad_104[0x4];
    f32 unk_108;
    u8 pad_10C[0x8];
    f32 unk_114;
} Node;

s32 func_800736AC(Node **list) {
    Node *node;

    for (; (node = *list) != 0; list++) {
        if (!(node->unk_100 & 0x10000000) || (node->unk_108 <= node->unk_114)) {
            return 1;
        }
    }
    return 0;
}
