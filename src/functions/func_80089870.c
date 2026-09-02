/* Independently written from the specification in specs/func_80089870.md. */
#include "podcruise/types.h"

extern s32 D_800A69B0;
extern u32 D_80149C70[15];
extern u8 D_80149CB0;
extern u8 D_80149CB1;
extern s32 D_80149CD8[6];
extern s32 D_80149CF0[8];

extern s32 func_80087E80(void *, void **, s32);
extern void func_800880E0(void *, void *, s32);
extern void func_800899E0(void *, void *);
extern void func_80089AB0(s32);
extern void func_800905A0(void);
extern unsigned long long func_80090660(void);
extern s32 func_800906F0(void *, unsigned long long, unsigned long long, void *, void *);
extern s32 func_800907D0(s32, void *);

s32 func_80089870(void *arg0, void *arg1, void *arg2) {
    void *message;
    s32 result;
    unsigned long long time;
    s32 timer[8];
    s32 queue[6];

    result = 0;
    if (D_800A69B0 != 0) {
        return 0;
    }
    D_800A69B0 = 1;
    time = func_80090660();
    if (time < 0x165A0BCULL) {
        func_800880E0(queue, &message, 1);
        func_800906F0(timer, 0x165A0BCULL - time, 0, queue, &message);
        func_80087E80(queue, &message, 1);
    }
    D_80149CB1 = 4;
    func_80089AB0(0);
    result = func_800907D0(1, D_80149C70);
    func_80087E80(arg0, &message, 1);
    result = func_800907D0(0, D_80149C70);
    func_80087E80(arg0, &message, 1);
    func_800899E0(arg1, arg2);
    D_80149CB0 = 0;
    func_800905A0();
    func_800880E0(D_80149CD8, D_80149CF0, 1);
    return result;
}
