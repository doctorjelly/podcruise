/* Independently written from $S/specs/func_8005DBAC.md */
#include "podcruise/types.h"

typedef struct {
    u8 unk_00[0x2C];
    s32 unk_2C;
    u8 unk_30[0x04];
} Slot8005DBAC; /* 0x34 bytes */

typedef struct {
    u8 unk_00[0x18];
    Slot8005DBAC *unk_18;
} Holder8005DBAC;

extern Slot8005DBAC D_800A31E0[];
extern s32 D_800A52BC;
extern Holder8005DBAC *D_8011B1BC;
extern Holder8005DBAC *D_8011B1C0;

extern void func_8000A4D8(void);
extern void func_8000A44C(s16 index, s32 value);
extern void func_8000AC34(s16 index, s32 bits);
extern s32 func_80030154(s32 id);
extern void func_8005D310(s32 first, s32 second);
extern void func_8005D324(s32 first, s32 second);

void func_8005DBAC(s32 first, s32 second) {
    s32 head0;
    s32 head1;
    s32 head2;
    s32 primary;
    s32 secondary;
    s32 tail;
    s32 shared;
    s32 i;

    (void)head0;
    (void)head1;
    (void)head2;
    (void)tail;
    func_8000A4D8();
    primary = func_80030154(0x4B);
    secondary = func_80030154(0x65);
    if (D_800A52BC < 2) {
        func_8000A44C(0, func_80030154(0x64));
        func_8000A44C(1, func_80030154(0x64));
        shared = func_80030154(0x66);
        func_8000A44C(3, shared);
        func_8000A44C(0xA, shared);
        func_8000AC34(0xA, 4);
        func_8000A44C(2, func_80030154(0x67));
        func_8000A44C(4, func_80030154(0x69));
        func_8000A44C(5, 0);
        func_8000A44C(6, 0);
        shared = func_80030154(0x6A);
        func_8000A44C(0xB, shared);
        func_8000A44C(0xC, shared);
        shared = func_80030154(0x6B);
        func_8000A44C(7, shared);
        func_8000A44C(8, shared);
        func_8000A44C(9, func_80030154(0x6C));
        func_8000A44C(0xD, primary);
        func_8000A44C(0xE, func_80030154(0x4A));
        for (i = 0; i != 0xE; i++) {
            func_8000AC34(i, 0x8000);
        }
        shared = func_80030154(0x68);
    } else {
        shared = func_80030154(0xA6);
        func_8000A44C(0x15, shared);
        func_8000A44C(0x16, secondary);
        func_8000A44C(0x13, func_80030154(0x63));
        func_8000A44C(0x14, func_80030154(0x63));
        func_80030154(0x69);
        func_8000A44C(0x17, 0);
        for (i = 0x15; i != 0x18; i++) {
            func_8000AC34(i, 0x8000);
        }
    }
    func_8000A44C(0x11, shared);
    func_8000A44C(0x12, secondary);
    func_8000A44C(0xF, func_80030154(0x63));
    func_8000A44C(0x10, func_80030154(0x63));
    for (i = 0x11; i < 0x13; i++) {
        func_8000AC34(i, 0x8000);
    }
    func_8000A44C(0x18, secondary);
    func_8000A44C(0x19, primary);
    func_8000AC34(0x19, 0);
    func_8000A44C(0x1A, primary);
    func_8000AC34(0x1A, 0x1800);
    for (i = 0x18; i < 0x1B; i++) {
        func_8000AC34(i, 0x8000);
    }
    func_8000A44C(0xA6, func_80030154(0x13));
    func_8000AC34(0xA6, 0x9200);
    func_8000A44C(0xA7, func_80030154(0x14));
    func_8000AC34(0xA7, 0x9200);
    func_8000A44C(0xA8, func_80030154(0x15));
    func_8000AC34(0xA8, 0x9200);
    func_8000A44C(0xA9, func_80030154(0x5C));
    func_8000AC34(0xA6, 0x1200);
    func_8000A44C(0xAA, func_80030154(0x5D));
    func_8000AC34(0xA7, 0x1200);
    func_8000A44C(0xAB, func_80030154(0x5E));
    func_8000AC34(0xA8, 0x1200);
    shared = func_80030154(0x2E);
    func_8000A44C(0x1B, shared);
    func_8000A44C(0x1E, shared);
    func_8000AC34(0x1E, 4);
    if (D_800A52BC >= 2) {
        func_8000A44C(0x23, shared);
        func_8000A44C(0x26, shared);
        func_8000AC34(0x26, 4);
    }
    shared = func_80030154(0x2F);
    func_8000A44C(0x1C, shared);
    func_8000A44C(0x1F, shared);
    func_8000AC34(0x1F, 4);
    if (D_800A52BC >= 2) {
        func_8000A44C(0x24, shared);
        func_8000A44C(0x27, shared);
        func_8000AC34(0x27, 4);
    }
    shared = func_80030154(0x30);
    func_8000A44C(0x1D, shared);
    func_8000A44C(0x20, shared);
    func_8000AC34(0x20, 4);
    if (D_800A52BC >= 2) {
        func_8000A44C(0x25, shared);
        func_8000A44C(0x28, shared);
        func_8000AC34(0x28, 4);
    }
    shared = func_80030154(0x31);
    func_8000A44C(0x21, shared);
    func_8000A44C(0x22, shared);
    if (D_800A52BC >= 2) {
        func_8000A44C(0x29, shared);
        func_8000A44C(0x2A, shared);
    }
    for (i = 0; i != 0x17; i++) {
        shared = func_80030154(D_800A31E0[i].unk_2C);
        func_8000A44C(i + 0x2B, shared);
        if (D_8011B1BC != 0) {
            if (D_8011B1BC->unk_18->unk_2C == D_800A31E0[i].unk_2C) {
                func_8000A44C(0x42, shared);
            }
        }
        if (D_8011B1C0 != 0) {
            if (D_8011B1C0->unk_18->unk_2C == D_800A31E0[i].unk_2C) {
                func_8000A44C(0x43, shared);
            }
        }
    }
    func_8005D324(first, second);
    func_8005D310(first, second);
}
