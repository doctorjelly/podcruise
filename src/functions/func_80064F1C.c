/* Implements the specification in scratchpad specs/func_80064F1C.md */

#include "podcruise/types.h"

typedef struct Obj80064F1C {
    char unk_000[0x64];
    s32 unk_064;
    f32 unk_068;
    char unk_06C[0x3C];
    f32 unk_0A8;
    char unk_0AC[0x28];
    f32 unk_0D4;
    f32 unk_0D8;
    char unk_0DC[0x18];
    void *unk_0F4[5];
} Obj80064F1C;

extern f64 D_80120BF0;
extern s32 func_800181BC(void *entry, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_80064E90(s32 *arg0);

void func_80064F1C(Obj80064F1C *obj) {
    s32 i;

    if (0.0f < obj->unk_068) {
        obj->unk_068 = obj->unk_068 - D_80120BF0;
        if (obj->unk_0D8 < 1.0f) {
            obj->unk_0D8 = obj->unk_0D8 + (4.0 * D_80120BF0) / obj->unk_0A8;
        }
        if (obj->unk_068 < obj->unk_0A8) {
            obj->unk_0D4 = obj->unk_0D4 + (4.0 * D_80120BF0) / obj->unk_0A8;
        }
    } else {
        obj->unk_068 = 0.0f;
        if ((obj->unk_064 & 1) == 0) {
            for (i = 0; i < 5; i++) {
                if ((obj->unk_0F4[i] != 0) && (obj->unk_0F4[i] != 0)) {
                    func_800181BC(obj->unk_0F4[i], 2, -4, 0x10, 3);
                }
            }
            func_80064E90((s32 *)obj);
        }
    }
}
