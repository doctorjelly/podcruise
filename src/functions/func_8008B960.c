/* Recovered per specs/func_8008B960.md (worker specification). */
#include "podcruise/types.h"

typedef struct Object {
    s32 unk_00;
    s32 unk_04;
    struct Object **unk_08;
    s32 unk_0C;
    u16 unk_10;
} Object;

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);
extern void func_8008D12C(Object **);
extern void func_8008D22C(Object **, Object *);
extern Object *func_8008D274(Object **);
extern void func_8008D284(void);

extern Object *D_800A7BB8;
extern Object *D_800A7BC0;

void func_8008B960(Object *object) {
    register s32 token;
    register s32 state;

    token = func_8008CA80();
    state = object->unk_10;
    if (state != 1) {
        if (state != 8) {
        } else {
            object->unk_10 = 2;
            func_8008D22C(&D_800A7BB8, object);
        }
    } else if ((object->unk_08 == 0) || (object->unk_08 == &D_800A7BB8)) {
        object->unk_10 = 2;
        func_8008D22C(&D_800A7BB8, object);
    } else {
        object->unk_10 = 8;
        func_8008D22C(object->unk_08, object);
        state = (s32)(long)func_8008D274(object->unk_08);
        func_8008D22C(&D_800A7BB8, (Object *)(long)state);
    }

    if (D_800A7BC0 == 0) {
        func_8008D284();
    } else if (D_800A7BC0->unk_04 < D_800A7BB8->unk_04) {
        D_800A7BC0->unk_10 = 2;
        func_8008D12C(&D_800A7BB8);
    }

    func_8008CAA0(token);
}
