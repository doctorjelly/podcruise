/* Recovered per specs/func_80063B60.md */
#include "podcruise/types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct {
    u8 pad0[0x30];
    void *unk30;
    u8 pad34[0x10];
    Vec3 unk44;
    Vec3 unk50;
} Obj;

extern Vec3 D_80118D90;
extern Vec3 D_80118E50;
extern f32 D_80120BF8;

extern void func_8001535C(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_80015390(Vec3 *, Vec3 *);
extern void func_800154D0(Vec3 *);
extern void func_800155EC(Vec3 *, Vec3 *, f32, Vec3 *);
extern void func_80033878(void *, Vec3 *);

void func_80063B60(Obj *obj) {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    s32 count;

    func_8001535C(&b, &obj->unk50, &obj->unk44);
    func_8001535C(&a, &D_80118E50, &D_80118D90);
    func_8001535C(&c, &obj->unk44, &D_80118D90);
    func_800154D0(&b);
    func_800154D0(&a);
    func_800154D0(&c);

    count = 0;
    while ((func_80015390(&a, &c) < 0.5) && (count != 40)) {
        func_800155EC(&obj->unk44, &obj->unk44, 130.0f * D_80120BF8, &b);
        func_8001535C(&a, &D_80118E50, &D_80118D90);
        func_8001535C(&c, &obj->unk44, &D_80118D90);
        func_800154D0(&a);
        func_800154D0(&c);
        count++;
    }

    if (count > 0) {
        func_80033878(obj->unk30, &obj->unk44);
    }
}
