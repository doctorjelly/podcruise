/* Specification: specs/func_80089144.md (scratchpad) */
#include "podcruise/types.h"

typedef struct {
    u32 unk00[7];
    u32 unk1C;
    u32 unk20[4];
} Element80089144;

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u32 unk14[5];
    /* 0x28 */ u32 unk28[4];
    /* 0x38 */ void *unk38;
    /* 0x3C */ s32 unk3C;
    /* 0x40 */ Element80089144 *unk40;
    /* 0x44 */ s32 unk44;
    /* 0x48 */ s32 unk48;
    /* 0x4C */ s32 unk4C;
} Object80089144;

typedef struct {
    /* 0x00 */ u32 count0;
    /* 0x04 */ u32 count1;
    /* 0x08 */ s32 unk08;
} Descriptor80089144;

extern Element80089144 *func_80087FC0(s32, s32, s32, s32, s32);
extern void func_8008FDEC(void *, void *, s32);
extern void func_8008FE60(void *, Object80089144 *);
extern void func_8008FC3C(void *, s16 *, s32);
extern s32 func_8008FD60(void *, void *);
extern void func_80088BFC(void);
extern void *D_800A6990;

void func_80089144(register Object80089144 *object, Descriptor80089144 *descriptor) {
    u32 index;
    Element80089144 *element;
    void *pool;
    s16 mode[6];

    object->unk3C = -1;
    object->unk48 = 0x3E80;
    object->unk44 = descriptor->count0;
    element = func_80087FC0(0, 0, descriptor->unk08, 1,
                            descriptor->count0 * sizeof(Element80089144));
    object->unk40 = element;
    for (index = 0; index < descriptor->count0; index++) {
        element->unk1C = 0;
        element++;
    }
    pool = (void *)func_80087FC0(0, 0, descriptor->unk08, 1, descriptor->count1 * 28);
    func_8008FDEC(&object->unk14, pool, descriptor->count1);
    object->unk00 = 0;
    object->unk08 = (void *)func_80088BFC;
    object->unk04 = object;
    object->unk38 = D_800A6990;
    func_8008FE60(D_800A6990, object);
    mode[0] = 5;
    func_8008FC3C(&object->unk14, mode, object->unk48);
    object->unk4C = func_8008FD60(&object->unk14, &object->unk28);
}
