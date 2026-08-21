/* Independently written from scratchpad spec specs/func_8002DB20.md. */

#include "podcruise/types.h"

typedef struct Unk8002DB20 {
    char unk_00[0x5E];
    s8 unk_5E;
} Unk8002DB20;

extern s32 func_8002DAD0(Unk8002DB20 *arg0, s8 arg1, u8 arg2);
extern u8 D_800A21B4[];

s32 func_8002DB20(Unk8002DB20 *arg0, s32 arg1) {
    s32 index;
    s32 matches;

    matches = -1;
    for (index = 0; index < D_800A21B4[arg0->unk_5E]; index++) {
        if (func_8002DAD0(arg0, arg0->unk_5E, (u8)index) != 0) {
            matches++;
            if (matches == arg1) {
                return index;
            }
        }
    }
    return -1;
}
