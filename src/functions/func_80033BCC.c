/* Spec: $S/specs/func_80033BCC.md */
#include "podcruise/types.h"

typedef struct Node {
    s32 unk_00;
    s32 unk_04;
    void *unk_08;
} Node;

extern void func_80017C18(void *, f32 *);
extern f32 func_80014F54(f32, f32);

f32 func_80033BCC(Node *arg0, s32 *arg1) {
    f32 work[18];

    if (arg1 == 0) {
        return 0.0f;
    }
    if (arg1[0] == 0) {
        return 0.0f;
    }
    if (arg0 == 0) {
        return 0.0f;
    }
    if (arg0->unk_04 == 0) {
        return 0.0f;
    }
    if (arg0->unk_08 == 0) {
        return 0.0f;
    }
    func_80017C18(arg0->unk_08, work);
    return func_80014F54(-work[4], work[5]);
}
