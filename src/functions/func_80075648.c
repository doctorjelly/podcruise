/* Implements the specification in specs/func_80075648.md (randomised orientation setup). */
#include "podcruise/types.h"

extern f32 D_800AD9B8;
extern f32 D_800AD9BC;
extern s32 D_8011C7A0;
extern s32 D_8011C7A4;
extern f32 D_8011C7A8[4][4];

extern void func_80015288(f32 *, f32 *);
extern void func_800154D0(f32 *);
extern void func_80015538(f32 *, f32 *, f32 *);
extern void func_800155C0(f32 *, f32, f32 *);
extern void func_800156DC(f32 (*)[4], f32 (*)[4]);
extern void func_80017874(f32 (*)[4]);
extern void func_80017BA8(s32, f32 (*)[4]);
extern void func_800181BC(s32, s32, s32, s32, s32);
extern void func_8003FA24(u32, u32 *);
extern void func_800735BC(s32, f32);
extern void func_80073640(s32);
extern s32 func_800736AC(s32);
extern void func_800755FC(s32, s32);
extern s32 func_80082BE0(void);

void func_80075648(u8 *obj, s32 index, f32 *fallback, f32 amount) {
    f32 m[4][4];
    u32 tag[2];

    if (D_8011C7A0 != 0) {
        if (D_8011C7A4 != 0) {
            if (func_800736AC(D_8011C7A4) != 0) {
                f32 range;
                f32 base;
                f32 denom;
                s32 i;

                tag[0] = 0x42697473;
                func_8003FA24(0x54657374, tag);
                *(s32 *)(obj + 0x324) = index;
                func_80017874(m);
                range = D_800AD9BC;
                base = D_800AD9B8;
                denom = 2147483648.0f;
                for (i = 0; i < 3; i++) {
                    m[0][i] = (f32)func_80082BE0() / denom * range + base;
                    if (func_80082BE0() & 1) {
                        m[0][i] = -m[0][i];
                    }
                    m[1][i] = (f32)func_80082BE0() / denom * range + base;
                    if (func_80082BE0() & 1) {
                        m[1][i] = -m[1][i];
                    }
                }
                func_80015538(m[2], m[0], m[1]);
                func_80015538(m[1], m[2], m[0]);
                func_800154D0(m[0]);
                func_800154D0(m[1]);
                func_800154D0(m[2]);
                func_800155C0(m[0], (f32)func_80082BE0() / denom * (1.5f * amount - amount) + amount, m[0]);
                func_800155C0(m[1], (f32)func_80082BE0() / denom * (1.5f * amount - amount) + amount, m[1]);
                func_800155C0(m[2], (f32)func_80082BE0() / denom * (1.5f * amount - amount) + amount, m[2]);
                func_80073640(D_8011C7A4);
                func_800735BC(D_8011C7A4, 3.0f);
                if (*(s32 *)(obj + 0x324) >= 0) {
                    func_80015288(m[3], ((f32 (*)[16])(obj + 0x380))[*(s32 *)(obj + 0x324)]);
                } else {
                    func_80015288(m[3], fallback);
                }
                if (*(s32 **)(obj + 0x344) != 0) {
                    func_800755FC(D_8011C7A0, (*(s32 **)(obj + 0x344))[1]);
                } else {
                    func_800755FC(D_8011C7A0, *(s32 *)(obj + 0x348));
                }
                func_800156DC(D_8011C7A8, m);
                func_80017BA8(D_8011C7A0, m);
                if (D_8011C7A0 != 0) {
                    func_800181BC(D_8011C7A0, 2, 3, 0x10, 2);
                }
            }
        }
    }
}
