/* Independently written from the specification for func_8000AC0C. */
#include "podcruise/types.h"

typedef struct {
    void *unk_0;
    u8 pad[0x1C];
} Slot8000AC0C;

extern Slot8000AC0C D_800D21AC[];

void func_8000AC0C(index, value)
s16 index;
void *value;
{
    if (index >= 0) {
        D_800D21AC[index].unk_0 = value;
    }
}
