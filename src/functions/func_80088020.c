/* Independently written from the specification for func_80088020. */

#include "podcruise/types.h"

typedef struct Link {
    /* 0x00 */ struct Link *unk00;
    /* 0x04 */ struct Link *unk04;
} Link;

void func_80088020(Link *link) {
    if (link->unk00 != 0) {
        link->unk00->unk04 = link->unk04;
    }
    if (link->unk04 != 0) {
        link->unk04->unk00 = link->unk00;
    }
}
