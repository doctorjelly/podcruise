/* Recovered from specification $S/specs/func_80033590.md */
#include "podcruise/types.h"

typedef struct {
    void *unk00;
    void *unk04;
} Node80033590;

extern void func_80015268(f32 *, f32, f32, f32);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_80017C18(void *, f32 (*)[4]);

void func_80033590(Node80033590 *node, f32 *out) {
    f32 second[4][4];
    f32 first[4][4];
    void *outer;
    void *inner;

    if (node == 0) {
        func_80015268(out, 0.0f, 0.0f, 0.0f);
        return;
    }
    outer = node->unk00;
    inner = node->unk04;
    if (outer == 0) {
        func_80015268(out, 0.0f, 0.0f, 0.0f);
        return;
    }
    func_80017C18(outer, second);
    out[0] = second[3][0];
    out[1] = second[3][1];
    out[2] = second[3][2];
    if (inner != 0) {
        func_80017C18(inner, first);
        func_800155EC(out, out, first[3][1], second[1]);
    }
}
