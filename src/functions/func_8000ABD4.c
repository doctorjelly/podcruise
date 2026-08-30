/* Independently written from specs/functions/recovered/func_8000ABD4.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ u16 *data;
} PcResource8000ABD4;

typedef struct {
    /* 0x00 */ PcResource8000ABD4 *resource;
    /* 0x04 */ u8 pad04[0x1C];
} PcSlot8000ABD4;

extern PcSlot8000ABD4 D_800D21AC[];

u16 *func_8000ABD4(s16 index) {
    PcResource8000ABD4 *resource = D_800D21AC[index].resource;

    if (resource != 0) {
        goto present;
    }
    return 0;

present:
    return resource->data;
}
