/* Independently written from specification $S/specs/func_80080DB4.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ void *source;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
} PlayerDB4;

typedef struct {
    /* 0x00 */ s16 count;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 items[40];
} NodeDB4;

typedef struct {
    /* 0x00 */ s16 mode;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s32 count;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ NodeDB4 *nodes;
} GraphDB4;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} VecDB4;

typedef struct {
    f32 x;
    f32 y;
} PairDB4;

extern s32 D_800A6748;

extern PlayerDB4 *func_8007EE4C(PlayerDB4 *player, void *source);
extern void func_8003A4A0(void *graph, s32 index, VecDB4 *out);
extern void func_8003B02C(PlayerDB4 *player, f32 *matrix);

s32 func_80080DB4(GraphDB4 *graph, VecDB4 *origin, f32 range, s32 limit,
                  PairDB4 *out, f32 step) {
    PlayerDB4 *st;
    s32 padC;
    PlayerDB4 player;
    s32 i;
    s32 j;
    s32 padA;
    s32 padB;
    s32 found;
    VecDB4 vecA;
    VecDB4 vecB;
    f32 d[3];
    f32 e[3];
    f32 matrix[4][4];
    s32 skip;
    s32 n;
    s32 padD;

    (void)padC;
    (void)padD;
    (void)padA;
    (void)padB;
    found = 0;
    if (graph->mode != 1) {
        return 0;
    }
    st = func_8007EE4C(&player, graph);
    skip = 0;
    for (i = 0; i < graph->count; i++) {
        st->unk10 = i;
        n = graph->nodes[i].count;
        if (D_800A6748 != 0) {
            skip = 0;
            if (i == 1) {
                n = 1;
            } else if (D_800A6748 == 1) {
                if (i >= 0x63 && i < 0x72) {
                    skip = 1;
                }
            } else if (D_800A6748 == 2) {
                if (i >= 0x67 && i < 0x74) {
                    skip = 1;
                }
            } else if (D_800A6748 == 3) {
                if (i >= 0x84 && i < 0x91) {
                    skip = 1;
                }
            }
        }
        if (!skip) {
            st->unk2C = 0;
            func_8003A4A0(graph, st->unk10, &vecA);
            d[0] = vecA.x - origin->x;
            d[1] = vecA.y - origin->y;
            d[2] = vecA.z - origin->z;
            for (j = 0; j < n; j++) {
                st->unk2C &= ~1;
                if (j != 0) {
                    st->unk2C |= 1;
                }
                st->unk14 = graph->nodes[st->unk10].items[j];
                func_8003A4A0(graph, st->unk14, &vecB);
                e[0] = vecB.x - origin->x;
                e[1] = vecB.y - origin->y;
                e[2] = vecB.z - origin->z;
                if (!(d[0] < -range && e[0] < -range) && !(range < d[0] && range < e[0]) &&
                    !(d[1] < -range && e[1] < -range) && !(range < d[1] && range < e[1])) {
                    for (st->unk08 = 0.0f; st->unk08 < 1.0f; st->unk08 += 1.0f / step) {
                        func_8003B02C(st, &matrix[0][0]);
                        d[0] = matrix[3][0] - origin->x;
                        d[1] = matrix[3][1] - origin->y;
                        d[2] = matrix[3][2] - origin->z;
                        if (d[0] < range && -d[0] < range && d[1] < range && -d[1] < range) {
                            if (found < limit) {
                                out[found].x = d[0];
                                out[found].y = d[1];
                            }
                            found++;
                        }
                    }
                }
            }
        }
    }
    return found;
}
