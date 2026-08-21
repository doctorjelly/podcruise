/* Specification: $S/specs/func_80075A3C.md */
#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct Obj80075A3C {
    u8 pad000[0x390];
    PcVec3f unk390;
    u8 pad39C[0x3C0 - 0x39C];
    PcVec3f unk3C0;
    u8 pad3CC[0x3D0 - 0x3CC];
    PcVec3f unk3D0;
    u8 pad3DC[0x400 - 0x3DC];
    PcVec3f unk400;
    u8 pad40C[0x1E64 - 0x40C];
    f32 unk1E64;
    u8 pad1E68[0x1E70 - 0x1E68];
    s32 **unk1E70;
} Obj80075A3C;

void func_80075A3C(Obj80075A3C *obj, PcVec3f *point, PcVec3f *output) {
    PcVec3f local;
    f32 firstDot;
    f32 secondDot;
    f32 push;
    PcVec3f first;
    PcVec3f second;

    if (obj->unk1E70[6][0] == 14) {
        return;
    }

    local.x = point->x;
    local.y = point->y;
    local.z = point->z;

    func_8001535C(&first, &local, &obj->unk3C0);
    func_8001535C(&second, &local, &obj->unk400);

    firstDot = obj->unk390.z * first.z + (first.x * obj->unk390.x + first.y * obj->unk390.y);
    secondDot = obj->unk3D0.z * second.z + (second.x * obj->unk3D0.x + second.y * obj->unk3D0.y);

    if (firstDot * firstDot < secondDot * secondDot) {
        push = -(firstDot - obj->unk1E64 * 0.5f);
        if (push < 0.0f) {
            func_800155EC(output, &local, push, &obj->unk390);
        }
    } else {
        push = -(obj->unk1E64 * 0.5f + secondDot);
        if (0.0f < push) {
            func_800155EC(output, &local, push, &obj->unk3D0);
        }
    }
}
