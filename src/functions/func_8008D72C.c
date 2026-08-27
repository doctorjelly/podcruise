/* Specification: $S/specs/func_8008D72C.md */
#include "podcruise/types.h"

typedef struct {
    u8 pad0[0x14];
    s32 unk14;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    s16 unk2E;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
} Obj8008D72C;

extern void func_80095AA0(Obj8008D72C *, void *, void *, s32);
extern s32 func_80087FC0(s32, s32, s32, s32, s32);
extern void *func_8008F3FC(void *obj, s32 arg1, s32 count, s32 time, void *cmd);
extern void func_8008EE04(void);

void func_8008D72C(Obj8008D72C *obj, s32 arg1) {
    func_80095AA0(obj, func_8008F3FC, func_8008EE04, 4);
    obj->unk14 = func_80087FC0(0, 0, arg1, 1, 0x50);
    obj->unk38 = 1;
    obj->unk48 = 0;
    obj->unk1A = 1;
    obj->unk28 = 1;
    obj->unk2E = 1;
    obj->unk1C = 1;
    obj->unk1E = 1;
    obj->unk20 = 0;
    obj->unk22 = 0;
    obj->unk26 = 1;
    obj->unk24 = 0;
    obj->unk30 = 0;
    obj->unk34 = 0;
    obj->unk18 = 0;
    obj->unk3C = 0;
    obj->unk40 = 0;
    obj->unk44 = 0;
}
