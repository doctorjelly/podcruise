/* Recovered from specs/functions/recovered/medium_spatial_tranche.md. */
#include "podcruise/types.h"

typedef struct Leaf80003BF8 {
    char unk_00[0x8];
    f32 box[6];
} Leaf80003BF8;

typedef struct Node80003BF8 {
    char unk_00[0x18];
    Leaf80003BF8 **unk_18;
    f32 box[6];
} Node80003BF8;

extern void func_800035BC(Leaf80003BF8 *leaf);
extern void func_800038E8(s32 flags, f32 *out, f32 *in, f32 *vec, f32 *ref);
extern void func_80003B44(s32 flags);
extern s32 func_80017E54(Node80003BF8 *node);

extern s32 D_800AEC78;
extern s32 D_800AEC7C;
extern f32 D_800AE8E0;
extern f32 D_800AE908[3];
extern f32 D_800AE948[3];
extern f32 D_800AE960[3];

void func_80003BF8(Node80003BF8 *node, f32 *arg1, s32 flags) {
    f32 x;
    f32 y;
    f32 z;
    f32 radius;
    s32 count;
    s32 index;
    Leaf80003BF8 *leaf;
    f32 *box;
    f32 high[3];
    f32 low[3];

    if (node != 0) {
        if (D_800AEC78 != 0) {
            D_800AEC78 = 0;
            func_800038E8(flags, D_800AE908, arg1, D_800AE948, D_800AE960);
        }

        radius = D_800AE8E0;
        x = D_800AE908[0];
        y = D_800AE908[1];
        z = D_800AE908[2];
        low[0] = x - radius;
        high[0] = x + radius;
        low[1] = y - radius;
        high[1] = y + radius;
        low[2] = z - radius;
        high[2] = z + radius;

        box = node->box;
        if (box != 0) {
            if (box[3] < low[0]) {
                return;
            }
            if (high[0] < box[0]) {
                return;
            }
            if (box[4] < low[1]) {
                return;
            }
            if (high[1] < box[1]) {
                return;
            }
            if (box[5] < low[2]) {
                return;
            }
            if (high[2] < box[2]) {
                return;
            }
        }

        count = func_80017E54(node);
        for (index = 0; index < count; index++) {
            leaf = node->unk_18[index];
            box = leaf->box;
            if (box[3] < low[0]) {
                continue;
            }
            if (high[0] < box[0]) {
                continue;
            }
            if (box[4] < low[1]) {
                continue;
            }
            if (high[1] < box[1]) {
                continue;
            }
            if (box[5] < low[2]) {
                continue;
            }
            if (high[2] < box[2]) {
                continue;
            }
            func_800035BC(leaf);
        }

        if (D_800AEC7C != 0) {
            func_80003B44(flags);
            D_800AEC7C = 0;
        }
    }
}
