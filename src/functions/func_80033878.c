/* Recovered from specification $S/specs/func_80033878.md */
#include "podcruise/types.h"

typedef struct {
    void *unk00;
    void *unk04;
} Node80033878;

extern void func_80015288(f32 *, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_800156DC(f32 (*)[4], f32 (*)[4]);
extern void func_80017BA8(void *, f32 (*)[4]);
extern void func_80017C18(void *, f32 (*)[4]);

void func_80033878(Node80033878 *node, f32 *position) {
    f32 result[4][4];
    f32 outerMatrix[4][4];
    f32 innerMatrix[4][4];
    void *outer;
    void *inner;

    if (node == 0) {
        return;
    }
    outer = node->unk00;
    inner = node->unk04;
    if (outer == 0) {
        return;
    }
    func_80017C18(outer, outerMatrix);
    func_800156DC(result, outerMatrix);
    func_80015288(result[3], position);
    if (inner == 0) {
        func_80017BA8(outer, result);
        return;
    }
    func_80017C18(inner, innerMatrix);
    func_800155EC(result[3], result[3], -innerMatrix[3][1], result[1]);
    func_80017BA8(outer, result);
}
