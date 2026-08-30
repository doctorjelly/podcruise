/* Independently written from specs/functions/recovered/func_80063084.md. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct {
    void *unk00;
    void *unk04;
} Node80063084;

typedef struct {
    u8 pad00[0x08];
    s32 state08;
    u8 pad0C[0x30 - 0x0C];
    Node80063084 *unk30;
    s32 *unk34;
    u8 pad38[0x44 - 0x38];
    PcVec3f unk44;
    PcVec3f unk50;
    PcVec3f unk5C;
    f32 unk68;
    f32 unk6C;
    u8 pad70[0x78 - 0x70];
    f32 unk78;
    u8 pad7C[0x94 - 0x7C];
    f32 unk94;
} Object80063084;

typedef struct {
    PcVec3f position;
    PcVec3f rotation;
} Transform80063084;

extern void *func_8003F800(u32 tag, s32 index);
extern void func_800174B8(f32 *matrix, f32 *source);
extern void func_80017BA8(void *destination, const void *source);
extern s32 func_800181BC(void *object, s32 which, u32 value, s32 flags, s32 mode);
extern s32 func_80082BE0(void);
extern void func_80033780(Node80063084 *node, f32 scale, f32 angle);
extern void func_80033878(Node80063084 *node, PcVec3f *position);
extern void func_80033928(s32 *list, f32 amount);
extern void func_80060DE4(Object80063084 *object, s32 code);

void func_80063084(s32 arg0, s32 arg1, PcVec3f *arg2, PcVec3f *arg3, f32 arg4,
                   f32 arg5) {
    Object80063084 *object;
    f32 matrix[16];
    Transform80063084 transform;
    void *handle;
    s32 active;

    object = func_8003F800(0x456C6D6F, arg0);
    if (object == 0) {
        return;
    }

    func_80015288(&object->unk44, arg2);
    func_80015288(&object->unk50, arg3);
    func_80015288(&object->unk5C, arg2);
    object->unk68 = arg4;
    object->unk6C = arg5;

    handle = object->unk30->unk00;
    active = handle != 0;
    if (active) {
        if (active) {
            func_800181BC(handle, 2, -4, 0x10, 3);
        }
        func_80015288(&transform.position, &object->unk44);
        func_80015268(&transform.rotation, object->unk68, 0.0f, 0.0f);
        func_800174B8(matrix, (f32 *)&transform);
        func_80017BA8(handle, matrix);
    }

    switch (object->state08) {
    case 1:
        if (arg0 < 0x37) {
            object->unk78 =
                (f32)(((func_80082BE0() / 2147483648.0f) * 0.4000000476837158) + 0.8);
        }
        object->unk94 = 0.3f;
        break;
    case 2:
        if (arg1 == 0x1B) {
            object->unk94 = 0.1f;
        } else if (arg1 == 0x1C) {
            object->unk94 = 0.1f;
        } else {
            object->unk94 = 0.3f;
        }
        break;
    case 3:
        object->unk94 = 0.24f;
        break;
    case 4:
        object->unk94 = 2.5f;
        break;
    case 5:
        object->unk94 = 0.4f;
        break;
    case 6:
        object->unk94 = 0.2f;
        break;
    case 7:
        object->unk94 = 0.23f;
        break;
    case 8:
        object->unk94 = 1.8f;
        break;
    case 9:
        object->unk94 = 1.7f;
        break;
    case 10:
        object->unk94 = 1.5f;
        break;
    case 11:
        object->unk94 = 2.0f;
        break;
    case 12:
        object->unk94 = 1.7f;
        break;
    }

    func_80033878(object->unk30, &object->unk44);
    func_80033780(object->unk30, object->unk94, object->unk68);
    func_80033928(object->unk34, object->unk78);
    func_80060DE4(object, arg1);
}
