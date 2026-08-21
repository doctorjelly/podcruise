/* Independently written from the specification for func_800880E0. */

#include "podcruise/types.h"

typedef struct Link {
    /* 0x00 */ struct Link *unk00;
    /* 0x04 */ struct Link *unk04;
} Link;

typedef struct {
    /* 0x00 */ Link *unk00;
    /* 0x04 */ Link *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ void *unk14;
} List;

/* The original translation unit reaches the terminator record through two
 * separate declarations that the link step resolves to one address. */
extern Link D_800A7BB0;
extern Link D_800A7BB0_2;

void func_800880E0(List *list, void *owner, s32 capacity) {
    list->unk00 = &D_800A7BB0;
    list->unk04 = &D_800A7BB0_2;
    list->unk08 = 0;
    list->unk0C = 0;
    list->unk10 = capacity;
    list->unk14 = owner;
}
