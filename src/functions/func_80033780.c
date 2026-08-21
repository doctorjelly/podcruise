/* Recovered from specification $S/specs/func_80033780.md */
#include "podcruise/types.h"

typedef struct {
    void *unk00;
    void *unk04;
} Node80033780;

extern void func_80015288(f32 *, f32 *);
extern void func_800155EC(f32 *, f32 *, f32, f32 *);
extern void func_8001745C(f32 (*)[4], f32, f32, f32);
extern void func_80017918(f32 (*)[4], f32, f32, f32, f32 (*)[4]);
extern void func_80017BA8(void *, f32 (*)[4]);
extern void func_80017C18(void *, f32 (*)[4]);

void func_80033780(Node80033780 *node, f32 scale, f32 angle) {
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
    func_8001745C(result, angle, 0.0f, 0.0f);
    func_80017918(result, scale, scale, scale, result);
    func_80017C18(outer, outerMatrix);
    func_80015288(result[3], outerMatrix[3]);
    if (inner == 0) {
        func_80017BA8(outer, result);
        return;
    }
    func_80017C18(inner, innerMatrix);
    func_800155EC(result[3], result[3], innerMatrix[3][1], outerMatrix[1]);
    func_800155EC(result[3], result[3], -innerMatrix[3][1], result[1]);
    func_80017BA8(outer, result);
}
