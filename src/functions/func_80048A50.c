/* Recovered from specification: specs/func_80048A50.md (worker batch 05) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x30];
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
} Node;

typedef struct {
    /* 0x00 */ u8 pad0[0x50];
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
} Info;

typedef struct {
    /* 0x00 */ u8 pad0[0x34];
    /* 0x34 */ void *unk34;
} Item;

extern Node D_80118D60;
extern Node D_80118E20;
extern u8 D_80113E7C;
extern f32 D_800AAFB8;
extern f32 D_800AAFBC;
extern f32 D_800AAFC0;
extern f32 D_800AAFC4;
extern Info D_800A3090;
extern void **D_8011A508[];

extern f32 func_80014F54(f32, f32);
extern void func_80015288(f32 *, f32 *);
extern void func_8001745C(f32 *, f32, f32, f32);
extern void func_80017918(f32 *, f32, f32, f32, f32 *);
extern void func_80017BA8(void *, f32 *);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_8000EA4C(void *, s32, s32, s32, s32, s32, s32);
extern void func_80033590(void *, f32 *);
extern f32 func_80033B94(void *);
extern Item *func_8003F800(u32, s32);
extern void func_80086A20(s32, f32 *, f32 *, f32 *);
extern s32 func_80082BE0(void);

void func_80048A50(s32 arg0) {
    register s32 i;
    void *obj;
    f32 sp104[3];
    f32 spD4[12];
    f32 spB8[7];
    f32 spB4;
    Item *item;
    f32 spA4[3];
    f32 sp98[3];
    f32 sp8C[3];
    f32 value;
    f32 scale;

    (void)arg0;
    spB4 = func_80014F54(D_80118D60.unk30 - D_80118E20.unk30, D_80118E20.unk34 - D_80118D60.unk34);
    spA4[0] = 80.0f;
    spA4[1] = 75.0f;
    spA4[2] = 50.0f;
    if (D_80113E7C > 0) {
        i = 0;
        scale = D_800AAFB8;
        do {
        value = (f32)((f64)((f32)func_80082BE0() / 2147483648.0f) * 2.5 + 2.0);
        func_80033590(D_8011A508[i + 52], spB8);
        if (spB8[2] <= -157.0f) {
            goto next;
        }
        if (D_8011A508[i + 93] == 0) {
            return;
        }
        obj = D_8011A508[i + 93][0];
        if (obj != 0) {
            if (obj != 0) {
                func_800181BC(obj, 2, -4, 0x10, 3);
            }
            func_8000EA4C(obj, 0, 0, 200, 200, 255, 255);
            item = func_8003F800(0x456C6D6F, i + 0x34);
            if ((f32)D_800A3090.unk50 * D_800AAFBC <= func_80033B94(item->unk34)) {
                if (func_80033B94(item->unk34) <= (f32)D_800A3090.unk52 * D_800AAFC0) {
                    spA4[0] = 80.0f;
                    spA4[1] = 75.0f;
                    spA4[2] = (f32)((f64)((f32)func_80082BE0() / 2147483648.0f) * 120.0 + -30.0) + 50.0f;
                    func_8001745C(spD4, spB4, 0.0f, -90.0f);
                    func_80015288(sp104, spB8);
                    if (sp104[0] < 0.0f) {
                        sp104[0] = sp104[0] + 30.0f;
                    } else {
                        sp104[0] = sp104[0] - 30.0f;
                    }
                    sp104[2] = sp104[2] + 13.0f;
                    func_80017918(spD4, value, value, value, spD4);
                    func_80017BA8(obj, spD4);
                    if (obj != 0) {
                        func_800181BC(obj, 2, 3, 0x10, 2);
                    }
                }
            }
        }
        obj = D_8011A508[i + 89][0];
        if (obj == 0) {
            goto next;
        }
        value = 100.0f * scale;
        if (obj != 0) {
            func_800181BC(obj, 2, -4, 0x10, 3);
        }
        func_8001745C(spD4, 0.0f, 0.0f, 0.0f);
        func_80015288(sp104, spB8);
        func_80017918(spD4, scale, scale, scale, spD4);
        sp104[2] = sp104[2] - value;
        func_80017BA8(obj, spD4);
        if (obj != 0) {
            func_800181BC(obj, 2, 3, 0x10, 2);
        }
        obj = D_8011A508[i + 11][0];
        if (obj == 0) {
            goto next;
        }
        if (obj != 0) {
            func_800181BC(obj, 2, -4, 0x10, 3);
        }
        func_8001745C(spD4, 0.0f, 0.0f, 0.0f);
        func_80015288(sp104, spB8);
        func_80017918(spD4, scale, scale, scale, spD4);
        sp104[2] = -157.0f;
        func_80017BA8(obj, spD4);
        if (obj != 0) {
            func_800181BC(obj, 2, 3, 0x10, 2);
        }
        next: ; } while (++i < D_80113E7C);
    }
    sp98[0] = 255.0f;
    sp98[1] = 255.0f;
    sp98[2] = 200.0f;
    sp8C[0] = 0.0f;
    sp8C[1] = 0.0f;
    sp8C[2] = D_800AAFC4;
    func_80086A20(-1, spA4, sp98, sp8C);
}
