/* Independently written from the specification for func_8008CAC0. */

#include "podcruise/types.h"

/* Singly linked record threaded through a head cell held by the caller.
 * Only the link word at offset 0 is touched by this routine. */
typedef struct PodListNode {
    struct PodListNode *link;    /* 0x00 */
    s32 rank;                    /* 0x04 */
    struct PodListNode **owner;  /* 0x08 */
} PodListNode;

void func_8008CAC0(PodListNode **head, PodListNode *target) {
    register PodListNode *previous = (PodListNode *)head;
    register PodListNode *current = previous->link;

    while (current != 0) {
        if (current == target) {
            previous->link = target->link;
            return;
        }
        previous = current;
        current = previous->link;
    }
}
