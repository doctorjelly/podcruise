/* Recovered per $S/specs/func_8000AEB4.md */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    u8 unk04[0x78];
} Entry8000AEB4;

extern Entry8000AEB4 *D_8009B790;

s32 func_8000AEB4(s32 index) {
    return D_8009B790[index].unk00;
}
