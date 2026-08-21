/* Specification: $S/specs/func_8005ED70.md */
#include "podcruise/types.h"

extern void *func_800305E8(s32);
extern void *func_80030964(void *);
extern void func_80073640(void *);
extern void func_800181BC(void *, s32, s32, s32, s32);
extern void func_80017874(void *);

extern void *D_8011ACAC;
extern void *D_8011C7A0;
extern void *D_8011C7A4;
extern u8 D_8011C7A8[];

void func_8005ED70(s32 arg0) {
    struct { s32 a; s32 b; } unusedRecord;
    void *entry;

    (void)arg0;
    (void)unusedRecord;
    D_8011ACAC = (void *)0;
    func_80030964(func_800305E8(0x93));
    entry = func_800305E8(0x12E);
    if (entry != (void *)0) {
        D_8011C7A4 = func_80030964(entry);
        D_8011C7A0 = *(void **)entry;
        func_80073640(D_8011C7A4);
        D_8011ACAC = D_8011C7A0;
        if (D_8011C7A0 != (void *)0) {
            func_800181BC(D_8011C7A0, 2, -4, 0x10, 3);
        }
        func_80017874(D_8011C7A8);
    }
}
