/* Independently written from the specification for func_80088050. */

#include "podcruise/types.h"

typedef struct Link {
    /* 0x00 */ struct Link *unk00;
    /* 0x04 */ struct Link *unk04;
} Link;

void func_80088050(Link *link, Link *anchor) {
    link->unk00 = anchor->unk00;
    link->unk04 = anchor;
    if (anchor->unk00 != 0) {
        anchor->unk00->unk04 = link;
    }
    anchor->unk00 = link;
}
