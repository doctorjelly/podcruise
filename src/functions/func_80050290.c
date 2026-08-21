/* Recovered from specification $S/specs/func_80050290.md (batch_06). */
#include "podcruise/types.h"

typedef struct {
    f32 unk00[3];
    f32 unk0C[3];
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
} PcNode;

typedef struct {
    s32 pad[13];
    s32 unk34;
} PcHolder;

extern PcNode D_800A4C00[];

extern u8 func_800152CC(f32 *left, f32 *right);
extern void func_80050450(PcHolder *holder);
extern void func_8005058C(PcNode *node, f32 *point, s32 arg2, s32 arg3, s32 arg4);

void func_80050290(holder, step, flag)
PcHolder *holder;
s16 step;
s32 flag;
{
    s32 next;
    s32 changed;
    PcNode *node;
    PcNode *current;

    changed = 0;
    next = holder->unk34 + step;
    if (flag == 0) {
        if (next < 0 || next >= 40) {
            return;
        }
        if (D_800A4C00[next].unk18 != D_800A4C00[holder->unk34].unk18) {
            return;
        }
    }

    current = &D_800A4C00[holder->unk34];
    next -= step;
    do {
        next += step;
        if (next < 0) {
            next = 39;
        } else if (next >= 40) {
            next = 0;
        }
        node = &D_800A4C00[next];
    } while (current->unk18 != node->unk18);

    if (node->unk1C != 0) {
        if (func_800152CC(node->unk00, current->unk00) == 0 ||
            func_800152CC(node->unk0C, D_800A4C00[holder->unk34].unk0C) == 0) {
            changed = 1;
            func_8005058C(node, node->unk0C, 1, 0, 0);
        }
    }
    holder->unk34 = next;
    if (changed != 0) {
        func_80050450(holder);
    }
}
