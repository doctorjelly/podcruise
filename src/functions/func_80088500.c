/* Independently written from the specification for func_80088500. */

#include "podcruise/types.h"

typedef struct Link {
    /* 0x00 */ struct Link *next;
} Link;

typedef struct {
    /* 0x00 */ u8 pad00[0x2C];
    /* 0x2C */ Link *head;
} Pool;

extern Pool *D_800A6990;

Link *func_80088500(void) {
    Pool *pool = D_800A6990;
    Link *result = 0;
    Link *node = pool->head;

    if (node != 0) {
        pool->head = node->next;
        result = node;
        node->next = 0;
    }
    return result;
}
