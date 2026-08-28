/* Recovered from specs/functions/recovered/medium_spatial_tranche.md. */
#include "podcruise/types.h"

extern void **D_8011A654[];
extern f32 D_800A4B50;
extern f32 D_800AB0D0;
extern f32 D_80118D60[4][4];
extern f32 D_80118D70[3];
extern f32 D_80118D80[3];
extern f32 D_80118D90[3];

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_800156DC(f32 [4][4], f32 [4][4]);
extern void func_800174B8(f32 *, f32 *);
extern void func_800178C4(f32 *, f32 *, f32, f32, f32, f32);
extern void func_80017918(f32 *, f32, f32, f32, f32 *);
extern void func_80017BA8(void *, f32 *);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_80028D60(void);

void func_8004A36C(s32 index, f32 spread, f32 lift, f32 scale) {
    f32 accum[3];
    f32 padA[1];
    f32 copy[3];
    f32 work[12];
    f32 basis[4][4];
    f32 sweep;
    void *target;
    f32 origin[3];
    f32 start[3];

    (void)padA;
    target = *D_8011A654[index];
    if (target == 0) {
        return;
    }
    if (target != 0) {
        func_800181BC(target, 2, -4, 0x10, 3);
    }
    func_80028D60();
    func_800156DC(basis, D_80118D60);
    func_80015288(accum, D_80118D90);
    func_800155EC(accum, accum, spread, D_80118D60[0]);
    func_800155EC(accum, accum, 30.0f, D_80118D70);
    func_800155EC(accum, accum, lift, D_80118D80);
    func_80015288(start, accum);
    func_80015268(origin, 0.0f, 0.0f, 0.0f);
    func_800174B8(work, start);
    sweep = index * 15;
    func_800178C4(work, work, (sweep + D_800A4B50) * 4.0f, basis[2][0], basis[2][1], basis[2][2]);
    func_800178C4(work, work, 45.0f, basis[1][0], basis[1][1], basis[1][2]);
    func_800178C4(work, work, (sweep + D_800A4B50) * -1.0f, basis[2][0], basis[2][1], basis[2][2]);
    func_80017918(work, D_800AB0D0 * scale, D_800AB0D0 * scale, D_800AB0D0 * scale, work);
    func_80015288(copy, accum);
    func_80017BA8(target, work);
    if (target != 0) {
        func_800181BC(target, 2, 3, 0x10, 2);
    }
}
