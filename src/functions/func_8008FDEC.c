/* Recovered from specification scratchpad specs/func_8008FDEC.md */
#include "podcruise/types.h"

typedef struct Unk8008FDEC {
    s32 unk00[7];
} Unk8008FDEC;

extern void func_80088050(Unk8008FDEC *, s32 *);

void func_8008FDEC(s32 *arg0, Unk8008FDEC *arg1, s32 arg2) {
    s32 i;

    arg0[4] = 0;
    arg0[2] = arg0[3] = 0;
    arg0[0] = arg0[1] = 0;
    for (i = 0; i < arg2; i++) {
        func_80088050(&arg1[i], arg0);
    }
}
