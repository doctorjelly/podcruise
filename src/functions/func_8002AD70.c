/* Recovered per specs/func_8002AD70.md (timed random selection with rejection). */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x34];
    s32 unk34;
    u8 pad38[0x3A];
    s8 unk72;
} Actor8002AD70;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[0x2C];
} Entry8002AD70;

extern f32 D_800A2610;
extern f32 D_800A2614;
extern Entry8002AD70 D_800A31E0[];
extern s16 D_800A4BC0;
extern u8 D_80113E60[];
extern f32 D_80120BF8;

extern s32 func_80082BE0(void);
extern void func_8002AFFC(Actor8002AD70 *, s32, s32);
extern void func_8002B3C8(Actor8002AD70 *);

void func_8002AD70(Actor8002AD70 *actor) {
    s32 choice;
    f32 timer;

    choice = actor->unk34;
    if (D_800A2614 == -1.0f) {
        D_800A2614 = (f32)(((f32)func_80082BE0() / (f32)2147483648.0) * 4.0 + 3.0);
    }
    func_8002B3C8(actor);
    if (D_800A4BC0 != 1) {
        timer = D_800A2610 + D_80120BF8;
        D_800A2610 = timer;
        if (D_800A2614 <= timer) {
            D_800A2610 = 0.0f;
            D_800A2614 = (f32)(((f32)func_80082BE0() / (f32)2147483648.0) * 4.0 + 3.0);
            do {
                choice = (s32)(((f32)func_80082BE0() / (f32)2147483648.0) * 10.0f) + 0x15;
                if ((choice >= 0x16) && (choice < 0x1A) && (D_800A31E0[actor->unk72].unk4 == 0x1E)) {
                    choice = actor->unk34;
                }
                if ((choice >= 0x18) && (choice < 0x1A) && (D_800A31E0[actor->unk72].unk4 != 0x28)) {
                    choice = actor->unk34;
                }
                if ((choice < 0x1E) && (D_80113E60[0x1C] < choice - 0x19)) {
                    choice = actor->unk34;
                }
            } while (choice == actor->unk34);
            D_800A4BC0 = 1;
        }
    }
    if (choice != actor->unk34) {
        func_8002AFFC(actor, choice, 0);
        actor->unk34 = choice;
    }
}
