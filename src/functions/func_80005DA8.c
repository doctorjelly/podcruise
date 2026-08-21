/* Recovered per specs/func_80005DA8.md */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad0[0x11C];
    f32 *unk11C;
    Vec3 *unk120;
} Obj;

extern f32 func_80005CAC(Obj *, f32, s32);
extern void func_800155EC(Vec3 *, Vec3 *, f32, Vec3 *);

void func_80005DA8(Vec3 *out, Obj *obj, f32 t, s32 index) {
    Vec3 head;
    f32 tail[3];
    f32 u;

    if (obj->unk11C[index + 1] < t) {
        out->x = obj->unk120[index + 1].x;
        out->y = obj->unk120[index + 1].y;
        out->z = obj->unk120[index + 1].z;
    } else if (t <= obj->unk11C[index]) {
        out->x = obj->unk120[index].x;
        out->y = obj->unk120[index].y;
        out->z = obj->unk120[index].z;
    } else {
        u = func_80005CAC(obj, t, index);
        head.x = obj->unk120[index].x;
        head.y = obj->unk120[index].y;
        head.z = obj->unk120[index].z;
        tail[0] = obj->unk120[index + 1].x;
        tail[1] = obj->unk120[index + 1].y;
        tail[2] = obj->unk120[index + 1].z;
        out->x = tail[0] * u;
        out->y = tail[1] * u;
        out->z = tail[2] * u;
        func_800155EC(out, out, 1.0f - u, &head);
    }
}
