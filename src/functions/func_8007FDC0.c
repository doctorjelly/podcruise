/* Independently written from scratchpad spec specs/func_8007FDC0.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 count;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 ent[40];
} PcGraphNode;

typedef struct {
    /* 0x00 */ s16 mode;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ PcGraphNode *nodes;
} PcGraph;

typedef struct {
    /* 0x00 */ PcGraph *graph;
    /* 0x04 */ u8 unk04[0xC];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u8 unk20[0xC];
    /* 0x2C */ s32 unk2C;
} PcGraphWalk;

extern f32 D_80120408[][2];
extern void func_80008F28(void);
extern s32 func_8003A50C(PcGraph *graph, s32 key, s32 start);
extern void *func_8007EE4C(void *walk, void *graph);
extern void func_8007FD98(PcGraphWalk *walk, f32 arg1, s16 *out, s16 *state);

void func_8007FDC0(PcGraph *graph, f32 arg1, s16 *out) {
    PcGraphWalk walk;
    PcGraphWalk *w;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s16 state;

    for (i = 0; i < graph->unk08; i++) {
        out[i] = -1;
        D_80120408[i][0] = -1.0f;
    }

    state = 0;
    w = func_8007EE4C(&walk, graph);

    for (j = 0; j < graph->unk04; j++) {
        func_80008F28();
        w->unk10 = func_8003A50C(w->graph, j, 0);
        while (w->unk10 != -1) {
            w->unk2C = 0;
            for (k = 0; k < graph->nodes[w->unk10].count; k++) {
                w->unk2C &= ~1;
                if (k != 0) {
                    w->unk2C |= 1;
                }
                w->unk14 = graph->nodes[w->unk10].ent[k];
                if (graph->mode == 1) {
                    func_8007FD98(w, arg1, out, &state);
                } else {
                    for (m = 0; m < graph->nodes[w->unk14].count; m++) {
                        w->unk2C &= ~2;
                        if (m != 0) {
                            w->unk2C |= 2;
                        }
                        w->unk18 = graph->nodes[w->unk14].ent[m];
                        if (w->unk10 != w->unk18) {
                            for (n = 0; n < graph->nodes[w->unk18].count; n++) {
                                w->unk2C &= ~4;
                                if (n != 0) {
                                    w->unk2C |= 4;
                                }
                                w->unk1C = graph->nodes[w->unk18].ent[n];
                                if (w->unk14 != w->unk1C) {
                                    func_8007FD98(w, arg1, out, &state);
                                }
                            }
                        }
                    }
                }
            }
            w->unk10 = func_8003A50C(w->graph, j, w->unk10 + 1);
        }
    }
}
