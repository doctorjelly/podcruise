/* Independently written from the specification for func_8008D22C. */

#include "podcruise/types.h"

/* Record threaded on a singly linked list that is kept sorted by a signed
 * rank held at offset 4; offset 8 remembers the head cell the record sits on. */
typedef struct PodRankedNode {
    struct PodRankedNode *link;    /* 0x00 */
    s32 rank;                      /* 0x04 */
    struct PodRankedNode **owner;  /* 0x08 */
} PodRankedNode;

void func_8008D22C(PodRankedNode **head, PodRankedNode *entry) {
    PodRankedNode *previous = (PodRankedNode *)head;
    PodRankedNode *current = *head;
    s32 rank = entry->rank;

    while (rank <= current->rank) {
        previous = current;
        current = current->link;
    }

    entry->link = previous->link;
    previous->link = entry;
    entry->owner = head;
}
