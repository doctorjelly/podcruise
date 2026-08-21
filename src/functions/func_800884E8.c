/* Independently written from the specification for func_800884E8. */

#include "podcruise/types.h"

typedef struct Link {
    /* 0x00 */ struct Link *next;
} Link;

typedef struct {
    /* 0x00 */ u8 pad00[0x2C];
    /* 0x2C */ Link *head;
} Pool;

extern Pool *D_800A6990;

void func_800884E8(Link *node) {
    Pool *pool = D_800A6990;

    node->next = pool->head;
    pool->head = node;
}
