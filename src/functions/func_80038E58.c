/* Recovered from the specification in worker notes specs/func_80038E58.md. */
#include "podcruise/types.h"

typedef struct {
    u8 col[3];
    u8 pad0;
    u8 colc[3];
    u8 pad1;
} AmbientEntry;

typedef struct {
    u8 col[3];
    u8 pad0;
    u8 colc[3];
    u8 pad1;
    u8 dir[3];
    u8 pad2;
} LightEntry;

typedef struct {
    AmbientEntry amb;
    LightEntry lit;
} LightSet;

extern LightSet D_800A3DB0;

void func_80038E58(s16 *arg0, s16 *arg1, s16 *arg2) {
    D_800A3DB0.amb.colc[0] = D_800A3DB0.amb.col[0] = arg0[0];
    D_800A3DB0.amb.colc[1] = D_800A3DB0.amb.col[1] = arg0[1];
    D_800A3DB0.amb.colc[2] = D_800A3DB0.amb.col[2] = arg0[2];
    D_800A3DB0.lit.colc[0] = D_800A3DB0.lit.col[0] = arg1[0];
    D_800A3DB0.lit.colc[1] = D_800A3DB0.lit.col[1] = arg1[1];
    D_800A3DB0.lit.colc[2] = D_800A3DB0.lit.col[2] = arg1[2];
    D_800A3DB0.lit.dir[0] = -arg2[0];
    D_800A3DB0.lit.dir[1] = -arg2[1];
    D_800A3DB0.lit.dir[2] = -arg2[2];
}
