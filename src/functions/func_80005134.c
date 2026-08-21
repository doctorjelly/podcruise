/* Independently written from scratchpad spec specs/func_80005134.md. */

#include "podcruise/types.h"

typedef struct PcProbe80005134 {
    f32 origin[3];    /* 0x00 */
    f32 heading[3];   /* 0x0C */
    f32 reach;        /* 0x18 */
} PcProbe80005134;

extern f32 D_800AE8B0;
extern s32 D_800AE8D8;
extern PcProbe80005134 D_800AE8E8;
extern s16 D_800AE934;
extern void (*D_800AE93C)(void);
extern void (*D_800AE940)(void);
extern s32 D_800AEC78;
extern s32 D_800AEC7C;

extern void func_800020D8(void);
extern void func_800026BC(void);
extern void func_8000550C(void);
extern void func_80004DFC(void *arg0, PcProbe80005134 *arg1, s32 arg2);

s32 func_80005134(void *arg0, PcProbe80005134 *arg1) {
    if (arg0 == 0) {
        return 0;
    }

    D_800AE8B0 = arg1->reach + 200.0f;
    D_800AE8D8 = 0;
    D_800AE8E8.reach = arg1->reach;
    D_800AE8E8.heading[0] = arg1->heading[0];
    D_800AE8E8.heading[1] = arg1->heading[1];
    D_800AE8E8.heading[2] = arg1->heading[2];
    D_800AE8E8.origin[0] = arg1->origin[0];
    D_800AE8E8.origin[1] = arg1->origin[1];
    D_800AE8E8.origin[2] = arg1->origin[2];
    D_800AE934 = 1;
    D_800AE93C = func_800026BC;
    D_800AE940 = func_800020D8;
    D_800AEC78 = 0;
    D_800AEC7C = 0;

    func_8000550C();
    func_80004DFC(arg0, arg1, 0);

    if (arg1->reach < D_800AE8B0) {
        return 0;
    }
    return D_800AE8D8;
}
