/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

typedef struct Obj8004AE74 {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18[7];
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38[2];
    /* 0x40 */ s32 unk40;
    /* 0x44 */ s32 unk44;
} Obj8004AE74;

extern f32 D_800A4BF0;
extern f32 D_800A4BF4;
extern void *D_8011A508[];

extern void func_8002AD70(Obj8004AE74 *);
extern void func_8002B3C8(Obj8004AE74 *, s32);
extern void func_80033590(void *, void *);
extern void func_80047DB0(Obj8004AE74 *);

void func_8004AE74(Obj8004AE74 *object) {
    if (object->unk14 & 1) {
        if (D_800A4BF4 >= 5.0f) {
            if (object->unk08 == 8) {
                func_8002AD70(object);
            }
        }
        if (D_800A4BF0 > 0.0) {
            if (object->unk08 == 8) {
                func_8002B3C8(object, object->unk34);
                if (object->unk10 == 1) {
                    func_80047DB0(object);
                }
            }
        }
        if (object->unk40 != -1) {
            func_80033590(D_8011A508[object->unk40], &object->unk44);
        }
    }
}
