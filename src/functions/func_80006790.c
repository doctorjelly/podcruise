/* Recovered from specification specs/func_80006790.md */
#include "podcruise/types.h"

typedef struct Obj80006790 {
    u8 pad0[0xDC];
    f32 unkDC;
    f32 unkE0;
    f32 unkE4;
    s32 unkE8;
    s32 unkEC;
    u8 padF0[0x10];
    u32 unk100;
    u8 pad104[0x10];
    f32 unk114;
    s32 unk118;
} Obj80006790;

extern f64 D_80120BF0;
extern s32 func_80006704(Obj80006790 *);
extern void func_80006848(Obj80006790 *);

void func_80006790(Obj80006790 *obj, f32 start, f32 end) {
    f32 span;

    obj->unk100 |= 0x20000000;
    obj->unkE0 = obj->unkDC;
    if (obj->unk114 < start) {
        span = -(obj->unk114 - start);
    } else {
        span = obj->unk114 - start;
    }
    obj->unkE4 = (span - D_80120BF0) / obj->unkE0;
    obj->unk114 = start;
    obj->unkE8 = func_80006704(obj);
    obj->unkEC = (s32)obj->unk114;
    obj->unk114 = end;
    obj->unk118 = func_80006704(obj);
    func_80006848(obj);
}
