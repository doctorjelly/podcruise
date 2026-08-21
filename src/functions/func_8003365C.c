/* Implements the specification in specs/func_8003365C.md (worker batch 17). */
#include "podcruise/types.h"

typedef struct {
    void *unk00;
    void *unk04;
} Node8003365C;

typedef struct {
    u8 pad0[0x100];
    s32 unk100;
} Owner8003365C;

typedef struct {
    Owner8003365C *unk00;
} Holder8003365C;

extern void func_80017C18(void *, f32 (*)[4]);
extern void func_8001535C(f32 *, f32 *, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_80017BA8(void *, f32 (*)[4]);

void func_8003365C(Node8003365C *node, Holder8003365C *holder, f32 *out, f32 limit) {
    f32 second[4][4];
    f32 first[4][4];
    void *outer;
    void *inner;
    f32 delta[3];
    f32 position[3];

    if (node == 0) {
        return;
    }
    if (holder == 0) {
        return;
    }
    if (holder->unk00 == 0) {
        return;
    }
    outer = node->unk00;
    inner = node->unk04;
    if (outer == 0) {
        return;
    }
    if (inner == 0) {
        return;
    }
    func_80017C18(outer, second);
    func_80017C18(inner, first);
    position[0] = first[3][0];
    position[1] = first[3][1];
    position[2] = first[3][2];
    func_8001535C(delta, position, out);
    out[0] = position[0];
    out[1] = position[1];
    out[2] = position[2];
    if ((holder->unk00->unk100 & 0x40000000) || delta[1] < -limit || limit < delta[1]) {
        func_800155EC(second[3], second[3], -delta[1], second[1]);
        func_80017BA8(outer, second);
    }
}
