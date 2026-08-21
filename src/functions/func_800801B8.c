/* Independently written from scratchpad spec specs/func_800801B8.md. */

#include "podcruise/types.h"

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

extern s32 D_800A6704;
extern s32 D_8011DCB0;

extern void func_80008F28(void);
extern void func_80080148(s32 index);
extern void func_8007FDC0(GraphB05 *graph, f32 arg1, s16 *out);
extern void func_8007F560(GraphB05 *graph, f32 arg1, s32 arg2, s16 *arg3,
                          void (*visit)(void *, f32, s32, s32));
extern void func_8007F098(void *, f32, s32, s32);
extern void func_8007F430(void *, f32, s32, s32);

void func_800801B8(GraphB05 *graph, s32 arg1) {
    s16 out[252];
    s32 i;

    D_800A6704 = -1;
    if (graph == 0) {
        return;
    }
    if (graph->unk08 >= 0xFB) {
        return;
    }
    if (graph->nodes->unk02 == 0) {
        D_800A6704 = -2;
        for (i = 0; i < graph->count; i++) {
            func_80008F28();
            if (D_800A6704 == -3 && graph->nodes[i].count == 0) {
                func_80080148(i);
            }
        }
    } else {
        for (i = 0; i < graph->count; i++) {
            func_80008F28();
            if (graph->nodes[i].count == 0) {
                func_80080148(i);
            }
        }
    }
    func_8007FDC0(graph, 100.0f, out);
    func_8007F560(graph, 10.0f, arg1, out, func_8007F098);
    if (D_8011DCB0 != 0) {
        func_8007F560(graph, 10.0f, 0, 0, func_8007F430);
    }
}
