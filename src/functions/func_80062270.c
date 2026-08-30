/* Independently written from specs/functions/recovered/func_80062270.md. */

#include "podcruise/types.h"
#include "podcruise/vector_math.h"

typedef struct {
    u8 pad00[0x08];
    s32 mode08;
    s32 variant0C;
    u8 pad10[0x04];
    s32 state14;
    f32 elapsed18;
    f32 limit1C;
    u8 pad20[0x10];
    void *node30;
    s32 *list34;
    PcVec3f vector38;
    PcVec3f position44;
    PcVec3f target50;
    PcVec3f vector5C;
    f32 angle68;
    f32 desiredAngle6C;
    u8 pad70[0x18];
    s32 variant88;
    u8 pad8C[0x08];
    f32 scale94;
    f32 turnProgress98;
    f32 turnDuration9C;
    s32 reachedA0;
    u8 padA4[0x04];
    f32 elapsedA8;
    f32 durationAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
} Object80062270;

extern PcVec3f D_800A5124;
extern PcVec3f D_800A5130;
extern PcVec3f D_800A513C;
extern f32 D_800A5B30;
extern f64 D_800AD328;
extern f64 D_800AD330;
extern f64 D_800AD338;
extern f64 D_800AD340;
extern f64 D_800AD348;
extern PcVec3f D_80118D90;
extern s32 D_80118EF8;
extern f32 D_80120BF8;

extern void func_80008B14(s32, s32, f32, f32, s32);
extern f32 func_80014F54(f32, f32);
extern void func_80015288(PcVec3f *, const PcVec3f *);
extern u8 func_800152CC(const PcVec3f *, const PcVec3f *);
extern void func_8001535C(PcVec3f *, const PcVec3f *, const PcVec3f *);
extern void func_800154D0(PcVec3f *);
extern void func_800155EC(PcVec3f *, const PcVec3f *, f32,
                          const PcVec3f *);
extern void func_80015630(PcVec3f *, f32, const PcVec3f *, f32,
                          const PcVec3f *);
extern void func_80033590(void *, PcVec3f *);
extern void func_8003365C(void *, s32 *, PcVec3f *, f32);
extern void func_80033780(void *, f32, f32);
extern void func_80033878(void *, PcVec3f *);
extern void func_80033928(s32 *, f32);
extern f32 func_80033B94(s32 *);
extern f32 func_80033BCC(void *, s32 *);
extern void func_80060DE4(Object80062270 *, s32);
extern void func_80063344(Object80062270 *, f32 *, f32 *);
extern s32 func_800636D0(Object80062270 *);
extern void func_8006373C(Object80062270 *);
extern void func_80063B60(Object80062270 *);
extern s32 func_80063D0C(Object80062270 *);
extern s32 func_80063E4C(Object80062270 *);
extern void func_80063EF4(Object80062270 *);
extern s32 func_80082BE0(void);

void func_80062270(Object80062270 *object) {
    PcVec3f delta;
    f32 low;
    f32 high;
    f32 time;
    s32 mode;

    low = 0.0f;
    high = 0.0f;
    object->elapsed18 += D_80120BF8;
    func_8003365C(object->node30, object->list34, &object->vector38, 30.0f);
    func_80033590(object->node30, &object->position44);
    func_80063344(object, &low, &high);

    switch (object->state14) {
    case 0:
        return;
    case 3:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 2);
        }
        break;
    case 1:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 6);
        }
        break;
    case 6:
        if (object->variant88 == 12) {
            func_8006373C(object);
            if (object->state14 != 6) {
                return;
            }
        } else if (high <= func_80033B94(object->list34)) {
            object->unkB4 = -78;
            object->unkB0 = 0;
            func_80060DE4(object, 10);
        }
        break;
    case 7:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 8);
        }
        break;
    case 8:
        func_80008B14(0x33, 6, 0.25f, 0.5f, 1);
        if ((s32)((f32)func_80082BE0() / 2147483648.0f * 3.0f) == 0 &&
            (f64)high - D_800AD328 <=
                (f64)func_80033B94(object->list34)) {
            func_80060DE4(object, 9);
        }
        break;
    case 9:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 7);
        }
        break;
    case 10:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 11);
        }
        break;
    case 11:
        func_80063EF4(object);
        func_800636D0(object);
        if (object->reachedA0 != 0 &&
            (f64)high - D_800AD330 <=
                (f64)func_80033B94(object->list34) &&
            func_80063E4C(object) == 0) {
            return;
        }
        break;
    case 12:
        if (high <= func_80033B94(object->list34) &&
            func_80063E4C(object) == 0) {
            return;
        }
        break;
    case 13:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 14);
        }
        break;
    case 14:
        if ((f64)high - D_800AD338 <=
                (f64)func_80033B94(object->list34) &&
            object->limit1C < object->elapsed18) {
            func_80060DE4(object, 15);
        }
        break;
    case 15:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 13);
        }
        break;
    case 19:
        func_8001535C(&delta, &object->target50, &object->position44);
        delta.z = 0.0f;
        object->angle68 = func_80014F54(-delta.x, delta.y);
        if (func_800636D0(object) != 0) {
            if (func_80063E4C(object) != 0) {
                return;
            }
            func_80060DE4(object, 20);
            return;
        }
        if (D_80118EF8 == 4) {
            func_80063B60(object);
        }
        break;
    case 20:
        func_8006373C(object);
        if (object->state14 != 20) {
            return;
        }
        time = func_80033B94(object->list34);
        if (!(high <= time && object->variant88 != 1)) {
            func_80033B94(object->list34);
        }
        break;
    case 17:
        func_80033928(object->list34, D_800A5B30);
        object->elapsedA8 += D_80120BF8;
        if (object->durationAC <= object->elapsedA8) {
            func_80033928(object->list34, 1.0f);
            if (func_80063E4C(object) != 0) {
                return;
            }
            func_80060DE4(object, 18);
            return;
        }
        if ((s32)((f32)func_80082BE0() / 2147483648.0f * 101.0f) == 0 &&
            object->variant0C == 28) {
            func_80015630(&object->position44, 0.95f,
                          &object->position44, 0.05f, &object->target50);
        }
        func_80033878(object->node30, &object->position44);
        break;
    case 18:
        if (high <= func_80033B94(object->list34)) {
            object->elapsedA8 = 0.0f;
            object->durationAC =
                (f32)func_80082BE0() / 2147483648.0f * 2.0f + 3.0f;
            func_80060DE4(object, 17);
            return;
        }
        break;
    case 25:
    case 26:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 17);
        }
        break;
    case 30:
        if (func_800636D0(object) == 0) {
            func_8001535C(&delta, &object->target50, &object->position44);
            func_800154D0(&delta);
            func_800155EC(&object->position44, &object->position44,
                          130.0f * D_80120BF8, &delta);
            func_80033878(object->node30, &object->position44);
        } else {
            object->desiredAngle6C =
                func_80014F54(object->position44.x - 12.0f,
                              -116.0f - object->position44.y);
            if (func_800152CC(&object->target50, &D_800A513C)) {
                object->desiredAngle6C =
                    func_80014F54(object->position44.x - D_80118D90.x,
                                  D_80118D90.y - object->position44.y);
            }
            func_80060DE4(object, 34);
        }
        break;
    case 34:
        func_8006373C(object);
        if (object->state14 != 34) {
            return;
        }
        break;
    case 35:
    case 36:
    case 39:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 29);
        }
        break;
    case 37:
    case 38:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 32);
        }
        break;
    case 29:
        if ((f64)high - D_800AD340 <=
                (f64)func_80033B94(object->list34) &&
            object->limit1C < object->elapsed18) {
            mode = func_80063D0C(object);
            if (mode == 4) {
                if ((s32)((f32)func_80082BE0() / 2147483648.0f * 6.0f) ==
                    0) {
                    func_80015288(&object->target50, &D_800A5124);
                    func_80060DE4(object, 34);
                } else {
                    func_80060DE4(object, 39);
                }
            } else if (func_80063D0C(object) == 5) {
                func_80060DE4(object, 39);
            }
        }
        break;
    case 32:
        if ((f64)high - D_800AD348 <=
                (f64)func_80033B94(object->list34) &&
            object->limit1C < object->elapsed18) {
            func_80060DE4(object, 33);
        }
        break;
    case 31:
        if (high <= func_80033B94(object->list34)) {
            func_80060DE4(object, 32);
        }
        break;
    case 33:
        if (high <= func_80033B94(object->list34)) {
            func_80015288(&object->target50, &D_800A5130);
            func_80060DE4(object, 34);
        }
        break;
    case 40:
    case 41:
    case 42:
    case 50:
    case 55:
    case 60:
    case 65:
        func_80033928(object->list34, D_800A5B30);
        break;
    case 46:
        func_80033928(object->list34, D_800A5B30 * 0.5f);
        break;
    case 67:
        func_80033928(object->list34, 0.0f);
        break;
    }

    if (object->state14 == 27) {
        return;
    }
    if (object->mode08 == 2) {
        func_80033780(object->node30, object->scale94,
                      object->angle68 -
                          func_80033BCC(object->node30, object->list34));
    } else {
        func_80033780(object->node30, object->scale94, object->angle68);
    }
}
