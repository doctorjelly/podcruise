/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */

#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
} Counter;

typedef struct {
    u8 unk000[0x108];
    f32 unk108;
} Entry;

typedef struct {
    u8 unk00[0xC];
    f32 unk0C;
    u8 unk10[0x40];
    s32 unk50;
    u8 unk54[0x4];
    f32 unk58;
    u8 unk5C[0x68];
    Counter *unkC4;
    u8 unkC8[0xA60];
    u8 unkB28[0x40];
    f32 unkB68;
} Owner;

extern void func_8000AEFC(s16 arg0, s32 arg1, void *arg2, s32 arg3);
extern void func_8000AB24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void func_800454A8(Owner *owner, Entry **list) {
    f32 best;
    f32 value;
    s32 stop;
    Entry **cursor;
    Entry *entry;

    value = 0.0f;
    best = value;
    stop = 0;
    if (list != 0) {
        cursor = list;
        while (*cursor != 0 && stop == 0) {
            entry = *cursor;
            if (best < entry->unk108) {
                best = entry->unk108;
            }
            cursor++;
        }
    }
    owner->unkB68 = best;
    owner->unk0C = value;
    if (owner->unk50 != 0) {
        owner->unk58 = ((f32)owner->unkC4->unk04 - 1.0f) / best;
    }
    func_8000AEFC(5, 1, owner->unkB28, 0);
    func_8000AB24(-0x67, 0, 0, 0, 0xFF);
}
