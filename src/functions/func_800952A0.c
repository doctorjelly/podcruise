/* Independently written from specs/func_800952A0.md (worker batch_03).
 * Behavior-level recovery: exact length (1408 bytes, 352 instructions) and matching
 * structure; not byte-exact — see the spec for the residual register-class note. */

#include "podcruise/types.h"

typedef struct {
    u32 words[9];
} DdRecord;

typedef struct {
    s32 state;           /* 0x00 */
    u16 command;         /* 0x04 */
    u16 slot;            /* 0x06 */
    s32 counter;         /* 0x08 */
    s32 unused0C;        /* 0x0C */
    s32 block;           /* 0x10 */
    s32 unused14;        /* 0x14 */
    DdRecord records[2]; /* 0x18 */
} DdSub;

typedef struct {
    u8 unused00[0x14];
    DdSub sub;
} DdControl;

extern void func_800945C0(DdControl *control, s32 mode, u32 address,
                          u32 offset, u32 length);
extern void func_80095820(void);
extern void func_800958D4(void);

extern DdControl *D_8014D7D4;
extern u32 D_800A7B50;

#define PI_STATUS (*(volatile u32 *)0xA4600010)
#define DD_STATUS (*(volatile u32 *)0xA5000508)
#define DD_ASIC (*(u32 *)0xA5000510)

s32 func_800952A0(void) {
    u32 status;
    volatile u32 pi;
    DdRecord *first;
    DdSub *control;
    DdRecord *record;
    s32 state;
    s32 count;

    control = &D_8014D7D4->sub;
    record = &control->records[control->slot];

    pi = PI_STATUS;
    if (pi & 1) {
        D_800A7B50 = D_800A7B50 & ~0x800;
        record->words[0] = 0x1D;
        func_800958D4();
        return 1;
    }

    pi = PI_STATUS;
    while (pi & 3) {
        pi = PI_STATUS;
    }
    status = DD_STATUS;

    if (status & 0x02000000) {
        pi = PI_STATUS;
        while (pi & 3) {
            pi = PI_STATUS;
        }
        DD_ASIC = control->block | 0x01000000;
        record->words[0] = 0;
        return 0;
    }

    state = control->state;
    if (2 == state) {
        return 1;
    }

    if (status & 0x08000000) {
        pi = PI_STATUS;
        while (pi & 3) {
            pi = PI_STATUS;
        }
        (void)DD_STATUS;
        record->words[0] = 0x16;
        func_800958D4();
        PI_STATUS = 2;
        D_800A7B50 = D_800A7B50 | 0x100401;
        return 1;
    }

    if (1 == state) {
        if (!(status & 0x40000000)) {
            if (control->command * 85 != control->counter + 1) {
                record->words[0] = 0x18;
                func_80095820();
                return 1;
            }
            PI_STATUS = 2;
            D_800A7B50 = D_800A7B50 | 0x100401;
            record->words[0] = 0;
            func_800958D4();
            return 1;
        }
        record->words[1] = record->words[3] + record->words[1];
        control->counter = control->counter + 1;
        func_800945C0(D_8014D7D4, 1, 0x05000400, record->words[1],
                      record->words[3]);
        return 1;
    }

    if (state == 0) {

    if (control->command == 3) {
        if ((s32)record->words[4] + 0x11 < control->counter) {
            record->words[0] = 0;
            func_80095820();
            return 1;
        }
        if (!(status & 0x40000000)) {
            record->words[0] = 0x17;
            func_80095820();
            return 1;
        }
    } else {
        record->words[1] = record->words[3] + record->words[1];
    }

    if (((DD_ASIC & 0x00200000) && (DD_ASIC & 0x00400000)) ||
        (DD_ASIC & 0x02000000)) {
        if (record->words[4] >= 4) {
            if (control->command != 3 || control->counter >= 0x53) {
                record->words[0] = 0x17;
                func_80095820();
                return 1;
            }
        } else {
            record->words[5 + record->words[4]] = control->counter + 1;
        }
        record->words[4] = record->words[4] + 1;
    }

    if (status & 0x10000000) {
    if (control->counter != 0x57) {
        record->words[0] = 0x18;
        func_80095820();
    }

    if (control->command == 2 && control->slot == 0) {
        control->slot = 1;
        control->counter = -1;
        control->records[1].words[1] =
            control->records[1].words[1] - control->records[1].words[3];
        record->words[0] = 0x16;
    } else {
        PI_STATUS = 2;
        D_800A7B50 = D_800A7B50 | 0x100401;
        control->state = 2;
        record->words[0] = 0;
    }
    func_800945C0(D_8014D7D4, 0, 0x05000000, record->words[2],
                  record->words[3] << 2);
    return 1;
    }

        count = control->counter;
        if (count == -1 && (u32)control->command == 2 && (u32)control->slot == 1) {
            first = &control->records[0];
            if (first->words[4] == 0) {
                u32 *block = *(u32 **)&first->words[2];

                if ((block[0] | block[1] | block[2] | block[3]) != 0) {
                    first->words[0] = 0x17;
                    func_80095820();
                    return 1;
                }
            }
            first->words[0] = 0;
            func_800958D4();
            count = control->counter;
        }
        control->counter = count + 1;

        if (!(status & 0x40000000)) {
            if (control->counter >= 0x55) {
                record->words[0] = 0x18;
                func_80095820();
            } else {
                func_800945C0(D_8014D7D4, 0, 0x05000400, record->words[1],
                              record->words[3]);
                record->words[0] = 0;
            }
            return 1;
        }
        if (control->counter < 0x55) {
            record->words[0] = 0x18;
            func_80095820();
            return 1;
        }
        return 1;
    }
    record->words[0] = 4;
    func_80095820();
    return 1;
}
