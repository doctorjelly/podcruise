/* Independently written from $S/specs/func_80017B7C.md (near-miss rework). */

#include "podcruise/types.h"

typedef struct Obj {
    u8 unk_00[0xC];
    u16 unk_0C;
    u8 unk_0E[0x32];
    f32 unk_40;
    f32 unk_44;
    f32 unk_48;
} Obj;

void func_80017B7C(Obj *object, f32 first, f32 second, f32 third) {
    object->unk_40 = first; object->unk_44 = second; object->unk_48 = third;
    object->unk_0C |= 3;
}
