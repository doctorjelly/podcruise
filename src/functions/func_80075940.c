/* Independently written from scratchpad spec specs/func_80075940.md. */

#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3_80075940;

typedef struct {
    Vec3_80075940 value;
    f32 padding;
} Slot_80075940;

extern void *D_8011C7A0;
extern void *D_8011C7A4;
extern Slot_80075940 D_8011C7A8[4];
extern f32 D_8011C7E0;
extern f32 D_800AD9C0;

extern void func_800156DC(Slot_80075940 *output, const Slot_80075940 *source);
extern void func_80015288(Vec3_80075940 *output, const Vec3_80075940 *source);
extern void func_80017BA8(void *destination, const void *source);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern s32 func_800736AC(void *object);

void func_80075940(void *arg0) {
    Slot_80075940 slots[4];
    s32 index;
    s32 result;
    s32 result2;

    if (D_8011C7A0 != 0) {
        if (D_8011C7A4 != 0) {
            if (func_800736AC(D_8011C7A4) != 0) {
                if (D_8011C7A0 != 0) {
                    result = func_800181BC(D_8011C7A0, 2, -4, 0x10, 3);
                }
                *(s32 *)((u8 *)arg0 + 0x324) = -1;
                D_8011C7E0 = D_800AD9C0;
            } else {
                func_800156DC(slots, D_8011C7A8);
                index = *(s32 *)((u8 *)arg0 + 0x324);
                if (index >= 0) {
                    func_80015288(&slots[3].value,
                                  (Vec3_80075940 *)((u8 *)arg0 + 0x380 + (index << 6)));
                }
                func_800156DC(D_8011C7A8, slots);
                func_80017BA8(D_8011C7A0, slots);
                if (D_8011C7A0 != 0) {
                    result2 = func_800181BC(D_8011C7A0, 2, 3, 0x10, 2);
                }
            }
        }
    }
    (void)result;
    (void)result2;
}
