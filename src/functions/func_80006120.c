/* Implements the specification in specs/func_80006120.md (worker-authored). */
#include "podcruise/types.h"

struct Obj80006120 {
    u8 pad0[0xE4];
    f32 unkE4;
    s32 unkE8;
    s32 unkEC;
    u8 padF0[0x10];
    s32 unk100;
    u8 pad104[0x10];
    f32 unk114;
    s32 unk118;
    u8 pad11C[0x8];
    void *unk124;
};

extern void func_80005DA8(f32 *out, struct Obj80006120 *obj, f32 amount, s32 index);
extern void func_800155EC(f32 *out, f32 *a, f32 t, f32 *b);
extern void func_80017B7C(void *target, f32 x, f32 y, f32 z);

void func_80006120(struct Obj80006120 *obj) {
    f32 first[3];
    f32 second[3];

    func_80005DA8(first, obj, obj->unk114, obj->unk118);
    if ((obj->unk100 << 2) < 0) {
        func_80005DA8(second, obj, (f32)obj->unkEC, obj->unkE8);
        first[0] = first[0] * obj->unkE4;
        first[1] = first[1] * obj->unkE4;
        first[2] = first[2] * obj->unkE4;
        func_800155EC(first, first, 1.0f - obj->unkE4, second);
    }
    if (obj->unk124 != 0) {
        func_80017B7C(obj->unk124, first[0], first[1], first[2]);
    }
}
