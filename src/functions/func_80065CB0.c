/* Independently written from the specification for func_80065CB0. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0xF0];
    /* 0xF0 */ void *unkF0;
} Emitter;

void func_80065CB0(Emitter *emitter, void *owner) {
    if (emitter != 0) {
        emitter->unkF0 = owner;
    }
}
