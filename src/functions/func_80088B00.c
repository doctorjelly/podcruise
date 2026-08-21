/* Independently written from the specification for func_80088B00. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[0x3C];
    /* 0x3C */ s32 unk3C;
} Manager;

void func_80088B00(Manager *manager, s16 index) {
    manager->unk3C = index;
}
