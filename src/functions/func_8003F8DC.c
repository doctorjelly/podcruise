/* Recovered per specs/func_8003F8DC.md (boundary corrected: real entry is func_8003F890). */
#include "podcruise/types.h"

typedef struct {
    u8 unk00[8];
    s32 count;
    s32 stride;
    u8 *base;
} Cursor8003F890;

extern Cursor8003F890 *D_800A4AA4;
extern s32 D_80118D10;

u8 *func_8003F890(void) {
    Cursor8003F890 *cursor = D_800A4AA4;

    if (cursor == 0) {
        return (u8 *)0;
    }
    D_80118D10 = D_80118D10 + 1;
    if (D_80118D10 >= cursor->count) {
        D_800A4AA4 = 0;
        return (u8 *)0;
    }
    return cursor->base + cursor->stride * D_80118D10;
}
