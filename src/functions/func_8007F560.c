/* Independently written from scratchpad spec specs/func_8007F560.md. */

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
} PlayerB05;

typedef struct {
    /* 0x00 */ s16 count;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 items[40];
} NodeB05;

typedef struct {
    /* 0x00 */ s16 mode;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s32 count;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ NodeB05 *nodes;
} GraphB05;

extern PlayerB05 *func_8007EE4C(PlayerB05 *player, void *source);
extern void func_80008F28(void);

void func_8007F560(GraphB05 *graph, f32 arg1, s32 arg2, s32 arg3,
                   void (*visit)(PlayerB05 *, f32, s32, s32)) {
    PlayerB05 *st;
    PlayerB05 player;
    s32 i;
    s32 j;
    s32 m;
    s32 n;
    s32 padA;

    (void)padA;

    st = func_8007EE4C(&player, graph);
    for (i = 0; i < graph->count; i++) {
        func_80008F28();
        st->unk10 = i;
        st->unk2C = 0;
        {
            for (j = 0; j < graph->nodes[st->unk10].count; j++) {
                st->unk2C &= ~1;
                if (j != 0) {
                    st->unk2C |= 1;
                }
                st->unk14 = graph->nodes[st->unk10].items[j];
                if (graph->mode == 1) {
                    for (st->unk08 = 0.0f; st->unk08 < 1.0f; st->unk08 += 1.0f / arg1) {
                        visit(st, arg1, arg2, arg3);
                    }
                } else {
                    for (m = 0; m < graph->nodes[st->unk14].count; m++) {
                        st->unk2C &= ~2;
                        if (m != 0) {
                            st->unk2C |= 2;
                        }
                        st->unk18 = graph->nodes[st->unk14].items[m];
                        if (st->unk10 != st->unk18) {
                            for (n = 0; n < graph->nodes[st->unk18].count; n++) {
                                st->unk2C &= ~4;
                                if (n != 0) {
                                    st->unk2C |= 4;
                                }
                                st->unk1C = graph->nodes[st->unk18].items[n];
                                if (st->unk14 != st->unk1C) {
                                    for (st->unk08 = 0.0f; st->unk08 < 1.0f;
                                         st->unk08 += 1.0f / arg1) {
                                        visit(st, arg1, arg2, arg3);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
