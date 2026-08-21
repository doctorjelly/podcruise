/* Independently written from the specification for func_80065C98. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x68];
    /* 0x68 */ f32 unk68;
} Emitter;

void func_80065C98(Emitter *emitter, f32 value) {
    if (emitter != 0) {
        emitter->unk68 = value;
    }
}
