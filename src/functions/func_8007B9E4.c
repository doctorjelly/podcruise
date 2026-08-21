/* Recovered from specification specs/func_8007B9E4.md */
#include "podcruise/types.h"

typedef struct Sub8007B9E4 {
    u8 pad0[0x24];
    s16 unk24;
} Sub8007B9E4;

typedef struct Ent8007B9E4 {
    u8 pad0[0x6];
    s16 unk6;
    u8 pad8[0x4];
    u32 unkC;
    u8 pad10[0x3C];
    Sub8007B9E4 *unk4C;
} Ent8007B9E4;

extern s32 func_8003F7B8(u32);
extern Ent8007B9E4 *func_8003F800(u32, s32);
extern void func_8007B828(Ent8007B9E4 *);

void func_8007B9E4(s32 key) {
    Ent8007B9E4 *entry;
    s32 count;
    s32 index;

    count = func_8003F7B8(0x54726967);
    for (index = 0; index < count; index++) {
        entry = func_8003F800(0x54726967, index);
        if (entry != 0) {
            if ((entry->unk6 & 0x100) == 0) {
                if ((entry->unkC & 1) != 0) {
                    if (key == entry->unk4C->unk24) {
                        func_8007B828(entry);
                        return;
                    }
                }
            }
        }
    }
}
