/* Independently written from specs/functions/runtime_leaves.md. */

#include "podcruise/types.h"

typedef struct PcListNode {
    struct PcListNode *next;
} PcListNode;

PcListNode *func_8008D274(PcListNode **head) {
    PcListNode *node = *head;

    *head = node->next;
    return node;
}
