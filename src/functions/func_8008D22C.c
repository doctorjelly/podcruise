/* Independently written from the specification for func_8008D22C. */
#include "podcruise/types.h"

/* Cell of a singly linked list kept in non-increasing order of the signed
 * rank at offset 4; offset 8 remembers the list head the cell belongs to. */
typedef struct PodRankedNode {
    struct PodRankedNode *link;
    s32 rank;
    struct PodRankedNode *owner;
} PodRankedNode;

void func_8008D22C(PodRankedNode *head, PodRankedNode *entry) {
    PodRankedNode *previous = head;
    PodRankedNode *current = head->link;
    s32 rank = entry->rank;

    while (rank <= current->rank) {
        previous = current;
        current = current->link;
    }
    entry->link = previous->link;
    previous->link = entry;
    entry->owner = head;
}
