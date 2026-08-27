/* Independently written from the scratchpad specification specs/func_8004A880.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ u8 unk0C[8];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ u8 unk18[8];
    /* 0x20 */ void *unk20;
    /* 0x24 */ void *unk24;
    /* 0x28 */ u8 unk28[4];
    /* 0x2C */ void *unk2C;
    /* 0x30 */ u8 unk30[8];
    /* 0x38 */ s32 unk38;
    /* 0x3C */ u8 unk3C[0x24];
    /* 0x60 */ u8 unk60;
} Unk8004A880;

typedef struct {
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ void *unk08;
} Unk8011A510;

extern s32 D_800A4BB4;
extern s32 D_800A4BB8;
extern f32 D_80120BF8;
extern f32 D_800A4B50;
extern f32 D_800A4B54;
extern Unk8011A510 *D_8011A510;
extern s32 D_800A4BDC;
extern s16 D_800A219C;
extern u16 D_800A4BC0;
extern f32 D_8011A240;

extern void func_80008F28(void);
extern void func_80063AE0(void);
extern void func_8004E0A0(s32 index);
extern void func_8004A780(Unk8004A880 *);
extern void func_8000A920(s16 index, s32 flag);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern void func_80019B80(Unk8004A880 *);
extern void func_80019BB4(Unk8004A880 *);
extern void func_8001A408(Unk8004A880 *);
extern void func_8004A7F8(Unk8004A880 *);
extern void func_8001D05C(Unk8004A880 *);
extern void func_80024070(Unk8004A880 *);
extern void func_800228C0(Unk8004A880 *);
extern void func_8001F5AC(Unk8004A880 *);
extern void func_80020030(Unk8004A880 *);
extern void func_8001ADD4(Unk8004A880 *);
extern void func_80024954(Unk8004A880 *);
extern void func_80025148(Unk8004A880 *);
extern void func_80026644(Unk8004A880 *);
extern void func_80026B3C(Unk8004A880 *);
extern void func_80027150(Unk8004A880 *);
extern void func_80027A0C(Unk8004A880 *);
extern void func_80028498(Unk8004A880 *);
extern void func_8004850C(Unk8004A880 *);
extern void func_8001DD48(Unk8004A880 *);
extern s32 func_800290A4(void);
extern void func_8000953C(s32, s32);
extern void func_8000955C(s32, s32);
extern s32 func_80028E78(Unk8004A880 *);
extern void func_8005065C(Unk8004A880 *);
extern void func_800509E8(Unk8004A880 *);
extern void func_80050F88(Unk8004A880 *);
extern void func_80064AF4(void);
extern void func_80064034(s32);
extern void func_8002D4C4(s32);
extern void func_8002B574(Unk8004A880 *);
extern void func_8004A6A4(Unk8004A880 *, s32, s32);

/* Stand-in constant pool. In the original translation unit the bytes ahead
   of this function's jump tables belong to a neighbouring table; an
   isolated unit needs its own filler so the tables land on their address.
   The USA pool needs two words ahead of the tables, the JP and EU pools
   four, which those units select by remapping PAD_A to D_padIntl. */
enum { D_padIntl = 4 };
enum { D_countJpn = 0xB7 };

#ifndef PAD_A
#define PAD_A 2
#endif

/* The Japanese build sweeps two more entries here; that unit remaps
   COUNT_A to D_countJpn. */
#ifndef COUNT_A
#define COUNT_A 0xB5
#endif

static const u32 D_stand_in[PAD_A] = {0};

void func_8004A880(Unk8004A880 *obj) {
    s32 i;
    s32 pending;
    f64 buffer[8];
    s32 previous;
    s32 current;

    (void)buffer;
    (void)D_stand_in;
    previous = obj->unk08;
    pending = 0;

    if (obj->unk14 & 1) {
        func_80008F28();
        if (obj->unk14 & 2) {
            obj->unk14 = obj->unk14 & ~2;
        }
        obj->unk60 = 0;
        func_80063AE0();
        for (i = 0; i < 4; i++) {
            func_8004E0A0(i);
        }
        D_800A4BB4 = 0;
        D_800A4BB8 = 0;
        func_80008F28();
        func_8004A780(obj);
        for (i = 0; i < COUNT_A; i++) {
            func_8000A920((s16)i, 0);
        }
        D_800A4B50 += D_80120BF8 * 40.0f;
        if (D_800A4B50 > 360.0f) {
            D_800A4B50 = D_800A4B50 - 360.0f;
        }
        func_80008F28();
        D_800A4B54 += D_80120BF8;
        while (D_800A4B54 > 1.0f) {
            D_800A4B54 -= 1.0f;
        }
        switch (obj->unk08) {
        case 14:
            func_80019B80(obj);
            return;
        case 0:
            func_80019BB4(obj);
            break;
        case 1:
            func_8001A408(obj);
            break;
        case 2:
            func_8004A7F8(obj);
            func_8001D05C(obj);
            break;
        case 8:
            if (obj->unk20 != 0) {
                func_800181BC(obj->unk20, 2, 3, 0x10, 2);
            }
            func_80020030(obj);
            break;
        case 7:
            if (obj->unk24 != 0) {
                func_800181BC(obj->unk24, 2, 3, 0x10, 2);
            }
            func_8001F5AC(obj);
            break;
        case 4:
            if (obj->unk2C != 0) {
                func_800181BC(obj->unk2C, 2, 3, 0x10, 2);
            }
            func_80024070(obj);
            break;
        case 3:
            switch (obj->unk38) {
            case 0:
                if (obj->unk24 != 0) {
                    func_800181BC(obj->unk24, 2, 3, 0x10, 2);
                }
                func_80028498(obj);
                func_8004850C(obj);
                break;
            case 1:
                if (obj->unk2C != 0) {
                    func_800181BC(obj->unk2C, 2, 3, 0x10, 2);
                }
                func_8004850C(obj);
                break;
            case 2:
                if (obj->unk20 != 0) {
                    func_800181BC(obj->unk20, 2, 3, 0x10, 2);
                }
                func_80020030(obj);
                break;
            case 3:
                func_8004A7F8(obj);
                break;
            }
            func_8001DD48(obj);
            break;
        case 5:
            func_8004A7F8(obj);
            func_800228C0(obj);
            break;
        case 12:
            func_8004A7F8(obj);
            func_80024954(obj);
            break;
        case 13:
            func_8004A7F8(obj);
            func_80025148(obj);
            break;
        case 9:
            func_8004A7F8(obj);
            func_8001ADD4(obj);
            break;
        case 18:
            func_8004A7F8(obj);
            func_80026644(obj);
            break;
        case 15:
            if (obj->unk20 != 0) {
                func_800181BC(obj->unk20, 2, 3, 0x10, 2);
            }
            func_80026B3C(obj);
            break;
        case 16:
            func_80027150(obj);
            break;
        case 17:
            if (obj->unk20 != 0) {
                func_800181BC(obj->unk20, 2, 3, 0x10, 2);
            }
            func_80027A0C(obj);
            break;
        case 6:
        case 10:
        case 11:
            break;
        }

        func_80008F28();
        if (obj->unk38 == 2) {
            if (D_8011A510->unk08 != 0) {
                if (D_8011A510->unk08 != 0) {
                    func_800181BC(D_8011A510->unk08, 2, -4, 0x10, 3);
                }
            }
        }
        func_80008F28();
        if (D_800A4BDC == 1) {
            if (func_800290A4() != 0) {
                func_8000953C(0, 0x10);
            }
        }
        func_80008F28();
        if (D_800A4BDC == -1) {
            func_8000955C(0, 0x10);
            pending = func_80028E78(obj);
        }
        func_80008F28();
        if (D_800A219C == 0) {
            switch (D_800A4BC0) {
            case 3:
                func_8005065C(obj);
                break;
            case 1:
            case 2:
                func_800509E8(obj);
                break;
            case 5:
                func_80050F88(obj);
                break;
            case 0:
            case 4:
                break;
            }
        }
        func_80008F28();
        func_80064AF4();
        if (obj->unk38 == 3) {
            func_80064034(obj->unk08);
            if (D_8011A240 > 0.0f) {
                if (obj->unk08 != 1) {
                    func_8002D4C4(0x4F);
                }
            }
        }
        if (obj->unk14 & 4) {
            current = obj->unk08;
            if (previous == current) {
                func_8002B574(obj);
            }
        }
    }

    if (pending != 0) {
        func_8004A6A4(obj, 1, 0);
    }
    func_80008F28();
}
