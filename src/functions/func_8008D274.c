/* Independently written from specs/func_8008D274.md (scratchpad). */

#include "podcruise/types.h"

typedef struct PcListNode {
    struct PcListNode *next;
} PcListNode;

PcListNode *func_8008D274(PcListNode **head) {
    PcListNode *node;

    node = *head;
    *head = node->next;
    return node;
}
