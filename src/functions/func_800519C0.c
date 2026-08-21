/* Recovered from specification scratchpad specs/func_800519C0.md. */

#include "podcruise/types.h"

typedef struct {
    f32 unk_00[15];
} Struct80032F2C;

typedef struct {
    u8 unk_00[52];
} Struct800A31E0;

extern void func_80032F2C(Struct80032F2C *target, Struct80032F2C *source,
                          u8 *modes, u8 *levels);
extern void func_800320E0(f32 *settings, f32 *source);

extern Struct800A31E0 D_800A31E0[];
extern Struct80032F2C D_800A368C[];
extern s32 D_80113E60;
extern void *D_80118F90[];
extern u8 *D_80118F9C;
extern Struct80032F2C D_80118FAC;
extern f32 D_80119838[];
extern f32 D_80119858[];
extern f32 D_80119878[];
extern s16 D_80119898[];
extern s16 D_801198A6;

void func_800519C0(s32 index, s32 slot, s32 mode, s32 level) {
    u8 levels[8];
    u8 modes[8];
    Struct80032F2C *source;
    f32 *destination;
    f32 *origin;
    s16 *flag;
    s32 i;

    D_80118F90[3] = &D_80113E60;
    D_80118F90[6] = &D_800A31E0[index];
    source = &D_800A368C[index];
    D_80118FAC = *source;

    for (i = 0; i < 7; i++) {
        modes[i] = D_80118F9C[0x1D + i];
        levels[i] = D_80118F9C[0x24 + i];
    }

    func_80032F2C(&D_80118FAC, source, modes, levels);
    func_800320E0(D_80119838, (f32 *)source);
    func_800320E0(D_80119858, (f32 *)&D_80118FAC);

    destination = D_80119878;
    origin = D_80119858;
    flag = D_80119898;
    while (flag < &D_801198A6) {
        *destination++ = *origin++;
        *flag++ = 0;
    }

    if (slot != -1) {
        modes[slot] = mode;
        levels[slot] = level;
        func_80032F2C(&D_80118FAC, source, modes, levels);
        func_800320E0(D_80119878, (f32 *)&D_80118FAC);
        for (i = 0; i < 7; i++) {
            modes[i] = D_80118F9C[0x1D + i];
            levels[i] = D_80118F9C[0x24 + i];
        }
        D_80119898[slot] = 1;
    }
}
