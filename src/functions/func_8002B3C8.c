/* Independently written from specs/functions/recovered/func_8002B3C8.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec8002B3C8;

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ u8 pad04[0x30];
} Entry8002B3C8;

extern Entry8002B3C8 D_800A3200[];
extern s16 D_800A4BC0;
extern Vec8002B3C8 D_80118D90;
extern Vec8002B3C8 D_80118E10;
extern Vec8002B3C8 D_80118E50;
extern void *D_8011A570[];
extern void *D_8011A578;

extern void func_80015288(Vec8002B3C8 *, const Vec8002B3C8 *);
extern void func_80015328(Vec8002B3C8 *, const Vec8002B3C8 *,
                          const Vec8002B3C8 *);
extern void func_8001535C(Vec8002B3C8 *, const Vec8002B3C8 *,
                          const Vec8002B3C8 *);
extern void func_80033590(void *, Vec8002B3C8 *);
extern void func_8005058C(void *, Vec8002B3C8 *, s32, s32, s32);

void func_8002B3C8(void *object, s32 selector) {
    Vec8002B3C8 position;
    Vec8002B3C8 offset;

    switch (selector) {
    case 0x1E:
        func_80033590(D_8011A578, &position);
        position.z = (f32)((f64)D_800A3200[((s8 *)object)[0x72]].unk00 *
                             0.6667 + -157.0);
        break;
    case 0x1A:
    case 0x1B:
    case 0x1C:
    case 0x1D:
        func_80033590(D_8011A570[selector], &position);
        if (((f32 *)&position)[2] == -157.0f) {
            position.z += 60.0f;
        } else {
            position.z += 30.0f;
        }
        break;
    default:
        return;
    }

    if (D_800A4BC0 == 1) {
        func_8005058C(&D_80118E10, &position, 1, 0, 1);
    } else if (D_800A4BC0 == 3) {
        func_8005058C(&D_80118D90, &position, 3, 1, 1);
    } else {
        func_8001535C(&offset, &D_80118D90, &D_80118E50);
        func_80015288(&D_80118E50, &position);
        func_80015328(&D_80118D90, &D_80118E50, &offset);
    }
}
