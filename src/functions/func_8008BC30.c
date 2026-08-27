/* Independently written from specs/functions/recovered/func_8008BC30.md. */
#include "podcruise/types.h"

typedef struct Message8008BC30 {
    u16 unk0;
} Message8008BC30;

typedef struct Schedule8008BC30 {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    void *unk10;
    void *unk14;
} Schedule8008BC30;

typedef struct Context8008BC30 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void *unkC;
} Context8008BC30;

extern u16 D_8014B0E0;
extern u64 D_8014C510;
extern u32 D_8014C518;
extern s32 D_8014C51C;

extern Schedule8008BC30 *func_800941D0(void);
extern void func_800941E0(void);
extern s32 func_80087E80(void *, void *, s32);
extern s32 func_8008C930(void *, void *, s32);
extern void func_80093E3C(void);
extern u32 func_8008C550(void);

void func_8008BC30(Context8008BC30 *arg0) {
    Schedule8008BC30 *schedule;
    Message8008BC30 *message;
    u16 count;
    u32 now;
    u32 previous;

    message = 0;
    schedule = func_800941D0();
    count = schedule->unk2;
    D_8014B0E0 = count;
    if (count == 0) {
        D_8014B0E0 = 1;
    }
    for (;;) {
        func_80087E80(arg0->unkC, &message, 1);
        if (message->unk0 == 13) {
            func_800941E0();
            D_8014B0E0--;
            if (D_8014B0E0 == 0) {
                schedule = func_800941D0();
                if (schedule->unk10 != 0) {
                    func_8008C930(schedule->unk10, schedule->unk14, 0);
                }
                D_8014B0E0 = schedule->unk2;
            }
            D_8014C51C++;
            previous = D_8014C518;
            now = func_8008C550();
            D_8014C518 = now;
            D_8014C510 += now - previous;
        } else if (message->unk0 == 14) {
            func_80093E3C();
        }
    }
}
