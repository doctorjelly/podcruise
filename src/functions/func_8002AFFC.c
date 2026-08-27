/* Recovered from specification specs/func_8002AFFC.md (camera anchor placement). */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ u8 pad04[0x30];
} Anchor8002AFFC; /* size 0x34 */

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_80017C18(void *, f32 (*)[4]);
extern void func_80033590(void *, f32 *);
extern void func_8005058C(void *, void *, s32, s32, s32);
extern f32 func_80051934(void);
extern s32 func_80082BE0(void);

extern Anchor8002AFFC D_800A3200[];
extern u8 D_80118D90[];
extern void **D_8011A544;
extern void *D_8011A570[];
extern void *D_8011A578;

void func_8002AFFC(void *arg0, s32 code, s32 arg2) {
    f32 pos[3];
    f32 point[3];
    f32 matrix[4][4];
    f32 scale1;
    f32 scale2;
    s32 value;

    switch (code) {
        case 20:
            func_80015268(pos, 0.0f, 0.0f, 0);
            break;
        case 21:
            func_80017C18(D_8011A544[5], matrix);
            func_80015288(pos, matrix[3]);
            break;
        case 22:
            func_80017C18(D_8011A544[1], matrix);
            func_80015288(pos, matrix[3]);
            break;
        case 23:
            func_80017C18(D_8011A544[2], matrix);
            func_80015288(pos, matrix[3]);
            break;
        case 24:
            func_80017C18(D_8011A544[3], matrix);
            func_80015288(pos, matrix[3]);
            break;
        case 25:
            func_80017C18(D_8011A544[4], matrix);
            func_80015288(pos, matrix[3]);
            break;
        case 30:
            func_80033590(D_8011A578, pos);
            pos[2] = (f32)((f64)D_800A3200[((s8 *)arg0)[0x72]].unk00 * 0.6667 + -157.0);
            break;
        case 26:
        case 27:
        case 28:
        case 29:
            func_80033590(D_8011A570[code], pos);
            if (pos[2] == -157.0f) {
                pos[2] += 60.0f;
            } else {
                pos[2] += 30.0f;
            }
            break;
    }

    if (arg2 != 0) {
        func_8005058C(D_80118D90, pos, 3, 1, 0);
        return;
    }

    value = func_80082BE0();
    func_80015268(point, pos[0] + ((f32)value / 2147483648.0f * 500.0f + -250.0f),
                  pos[1] + ((f32)func_80082BE0() / 2147483648.0f * 500.0f + -250.0f), pos[2] + 400.0f);

    if (code >= 26 && code < 31) {
        scale1 = func_80051934();
        value = func_80082BE0();
        scale2 = func_80051934();
        func_80015268(point, pos[0] + ((f32)value / 2147483648.0f * 150.0f + 200.0f) * scale1,
                      pos[1] + ((f32)func_80082BE0() / 2147483648.0f * 150.0f + 200.0f) * scale2, pos[2]);
        if (pos[2] == -97.0f) {
            point[2] -= 30.0f;
        } else {
            point[2] += 400.0f;
        }
    }

    func_8005058C(point, pos, 1, 0, 0);
}
