/* Independently written from specs/functions/recovered/func_8005337C.md. */

#include "podcruise/types.h"

typedef struct Subject8005337C {
    u8 pad00[0x64];
    u32 flags64;
} Subject8005337C;

typedef struct Record8005337C {
    u8 pad00[8];
    u32 flags08;
    u8 pad0C[0x78];
    Subject8005337C *subject84;
} Record8005337C;

typedef struct Owner8005337C {
    u8 pad00[8];
    u32 flags08;
    f32 timer0C;
    u8 pad10[0x118];
    s32 tag128;
    u8 pad12C[4];
    s32 handle130;
    u8 pad134[0x20];
    s32 active154;
    u8 pad158[0x54];
    s32 effect1AC;
    u8 pad1B0[0x0C];
    s32 count1BC;
    u8 pad1C0[0x0C];
    f32 secondaryTimer1CC;
} Owner8005337C;

typedef struct Hang8005337C {
    u8 pad00[0x71];
    s8 count71;
    s8 values72[1];
} Hang8005337C;

extern s16 D_800A52DC[];
extern s16 D_800A530C[];
extern s32 D_800A533C;
extern s32 D_800A5998;
extern s32 D_800A59A0;
extern f32 D_800A59AC;
extern f32 D_800ACE88;
extern f32 D_800ACE8C;
extern f32 D_800ACE90;
extern s32 D_800D7700[2];
extern Record8005337C *D_8011B1B8;
extern f64 D_80120BF0;

extern void func_80007A44(void);
extern void func_800092EC(s32, s32, s32);
extern u32 func_80009524(s32, u32);
extern void func_8000953C(s32, u32);
extern void func_80009704(s32, s32, s32, s32, s32, s32);
extern void func_80009F6C(void);
extern void func_8000AB24(s32, s32, s32, s32, s32);
extern void func_8003F99C(Subject8005337C *, u32 *);
extern Hang8005337C *func_8003F800(u32, s32);
extern void func_8003FA24(u32, u32 *);
extern void func_80051C80(Owner8005337C *, s32);
extern s32 func_80051FF4(void);
extern void func_80052A08(Owner8005337C *, s32);
extern void func_80052E44(Owner8005337C *, s32);
extern void func_800530CC(Owner8005337C *);
extern s32 func_80053220(s32);
extern void func_80053300(Owner8005337C *);
extern void func_8007EB7C(s32, s32);
extern s32 func_80082BE0(void);
extern void func_80086730(s32, f32, f32, f32, f32, f32);

void func_8005337C(Owner8005337C *owner) {
    u32 message[14];
    s32 mode;
    s32 index;

    mode = D_800A5998;
    if (mode == 0) {
        func_80053300(owner);
    }

    switch (owner->flags08 & 0xF) {
        case 0:
            func_8007EB7C(owner->effect1AC, 1);
            owner->timer0C = (f32)((f64)owner->timer0C - D_80120BF0);
            for (index = 0; index < owner->count1BC; index++) {
                Record8005337C *record =
                    (Record8005337C *)((u8 *)D_8011B1B8 + index * 0x88);
                Subject8005337C *subject = record->subject84;

                if (subject != 0) {
                    if (owner->timer0C > D_800ACE90 &&
                        owner->timer0C < D_800ACE8C) {
                        subject->flags64 |= 0x800;
                    } else {
                        subject->flags64 &= ~0x800;
                    }
                }
            }
            if (owner->timer0C < 0.0f) {
                owner->timer0C = 0.0f;
                owner->flags08 = (owner->flags08 & ~0xF) | 1;
                message[0] = 0x476F2121;
                for (index = 0; index < owner->count1BC; index++) {
                    Record8005337C *record =
                        (Record8005337C *)((u8 *)D_8011B1B8 + index * 0x88);

                    if (record->subject84 != 0) {
                        record->flags08 |= 1;
                        func_8003F99C(record->subject84, message);
                    }
                }
            }
            break;

        case 1:
            if (owner->flags08 & 0x20) {
                owner->secondaryTimer1CC =
                    (f32)((f64)owner->secondaryTimer1CC - D_80120BF0);
                owner->timer0C = (f32)((f64)owner->timer0C + D_80120BF0);
                if (D_800A5998 != 0 && D_800A59A0 == 0) {
                    return;
                }
                if (owner->secondaryTimer1CC < 0.0f || D_800D7700[0] != 0 ||
                    D_800D7700[1] != 0) {
                    func_80051C80(owner, 0x41627274);
                }
            } else {
                owner->timer0C = (f32)((f64)owner->timer0C + D_80120BF0);
                func_8007EB7C(owner->effect1AC, 0);
            }
            break;

        case 2:
            owner->timer0C = (f32)((f64)owner->timer0C + D_80120BF0);
            if (func_80053220(0x201) != 0) {
                func_80051C80(owner, 0x46696E69);
            }
            break;

        case 3:
            owner->timer0C = (f32)((f64)owner->timer0C + D_80120BF0);
            while (owner->timer0C > 3.0f) {
                owner->timer0C -= 3.0f;
            }
            if (func_80053220(1) != 0 || (owner->flags08 & 0x60) != 0) {
                func_800530CC(owner);
                func_80009F6C();
            }
            break;

        case 4:
            if (func_80053220(0x201) != 0 || (owner->flags08 & 0x60) != 0) {
                func_800530CC(owner);
                func_80009F6C();
                break;
            }

            if (owner->handle130 != 0) {
                if (owner->active154 != 0) {
                    if (!(owner->flags08 & 0x80)) {
                        owner->flags08 |= 0x80;
                        owner->timer0C = 0.0f;
                    } else {
                        owner->timer0C =
                            (f32)((f64)owner->timer0C + D_80120BF0);
                    }
                } else {
                    owner->timer0C = (f32)((f64)owner->timer0C - D_80120BF0);
                }
            }

            if (owner->handle130 != 0 &&
                (owner->active154 == 0 || owner->timer0C <= 0.5f)) {
                break;
            }

            func_8000AB24(-0x67, 0, 0, 0, 0xFF);
            owner->flags08 = (owner->flags08 & ~0xF) | 5;
            owner->timer0C = D_800ACE88;
            func_80052A08(owner, 3);
            func_80086730(1, 100.0f, -1.0f, -1.0f, -1.0f, -1.0f);
            message[0] = 0x53776565;
            message[1] = 1;
            func_8003FA24(0x634D616E, message);
            func_80007A44();
            D_800A59AC = 2.0f;
            break;

        case 5: {
            Hang8005337C *hang;
            s16 choice;
            s32 found;

            if (func_80053220(0x201) != 0) {
                func_800530CC(owner);
                func_80009F6C();
            } else {
                owner->timer0C = (f32)((f64)owner->timer0C - D_80120BF0);
                if (owner->timer0C < 0.0f) {
                    func_800530CC(owner);
                }
            }

            if (D_800A59AC > 0.0f) {
                D_800A59AC = (f32)((f64)D_800A59AC - D_80120BF0);
            }
            if (D_800A59AC > 0.0f || func_80051FF4() >= 2 ||
                owner->count1BC < 2 || func_80009524(0, 0x200000) != 0) {
                break;
            }

            found = 0;
            hang = func_8003F800(0x48616E67, 0);
            for (index = 0; index < hang->count71; index++) {
                if (hang->values72[index] == D_800A533C) {
                    found = 1;
                }
            }

            choice = D_800A530C[D_800A533C];
            if (choice != 0 &&
                (f64)((f32)func_80082BE0() / 2147483648.0f) >= 0.5 && found) {
                if (choice > 0) {
                    func_800092EC(5, 0, choice);
                } else {
                    func_800092EC(7, 0, -choice);
                }
            } else {
                func_80009704(5, 0, 1, 5, 0, D_800A52DC[D_800A533C]);
            }
            func_8000953C(0, 0x200000);
            break;
        }

        case 6:
            if (owner->timer0C < 0.0f) {
                func_80052E44(owner, owner->tag128);
            } else {
                owner->timer0C = (f32)((f64)owner->timer0C - D_80120BF0);
            }
            break;
    }
}
