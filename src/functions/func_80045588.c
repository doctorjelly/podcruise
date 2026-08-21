/* Implements the specification in specs/func_80045588.md */
#include "podcruise/types.h"

typedef struct {
    void *unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
} Sub80045588;

typedef struct {
    u8 pad0[0x50];
    s32 unk50;
    Sub80045588 unk54;
    u8 pad64[0x10];
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
    u8 pad88[0x3C];
    void *unkC4;
} Obj80045588;

extern s32 D_800A4B0C;
extern void *func_80030274(s32 index);
extern void func_8003B02C(Sub80045588 *sub, s32 *other);
extern void func_8003B250(Sub80045588 *sub, s32 mode);

void func_80045588(Obj80045588 *object) {
    void *entry;

    object->unk50 = 0;
    if (D_800A4B0C >= 0) {
        entry = func_80030274(D_800A4B0C);
        object->unkC4 = entry;
        if (entry != 0) {
            Sub80045588 *sub;

            object->unk50 = 1;
            object->unk54.unk0 = entry;
            object->unk74 = 0;
            object->unk78 = 0;
            object->unk7C = 0;
            object->unk80 = 0;
            object->unk54.unk4 = 0.0f;
            object->unk54.unk8 = 0.0f;
            object->unk54.unkC = 0.0f;
            if (object->unk54.unk0 != 0) {
                func_8003B250(&object->unk54, 0);
            }
            sub = &object->unk54;
            func_8003B02C(sub, &object->unk84);
            sub->unk4 = 1.0f;
        }
    }
}
