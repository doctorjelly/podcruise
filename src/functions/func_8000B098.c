/* Specification: specs/func_8000B098.md (extends to 0x8000B0DC) */
#include "podcruise/types.h"

typedef struct Rec8000B098 {
    u32 flags;
    u8 rest[120];
} Rec8000B098;

extern Rec8000B098 *D_8009B790;

s32 func_8000B098(index)
s16 index;
{
    if (D_8009B790[index].flags & 1) {
        return 1;
    }
    return 0;
}
