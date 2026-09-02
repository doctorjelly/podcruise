/* Independently written from the specification in specs/func_8008D22C.md. */
#include "podcruise/types.h"

/* Cell of a singly linked list kept in non-increasing order of the signed
 * rank at offset 4; offset 8 remembers the list head the cell belongs to.
 * The list always ends in a sentinel whose rank is lower than any real
 * rank, so the search below needs no null test. */
typedef struct PodRankedNode {
    struct PodRankedNode *link;
    s32 rank;
    struct PodRankedNode *owner;
} PodRankedNode;

void func_8008D22C(PodRankedNode *head, PodRankedNode *entry) {
    PodRankedNode *previous;
    PodRankedNode *current;
    s32 rank;
    s32 currentRank;

    previous = head;
    current = head->link;
    rank = entry->rank;
    currentRank = current->rank;
    while (currentRank >= rank) {
        previous = current;
        current = current->link;
        currentRank = current->rank;
    }
    entry->link = previous->link;
    previous->link = entry;
    entry->owner = head;
}
