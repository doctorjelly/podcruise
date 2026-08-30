/* Recovered from specification $S/specs/func_8008D5FC.md */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    f32 unk18;
    s32 unk1C;
    f32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
} Obj8008D5FC;

extern u32 *func_8008EADC(void *stream, s16 *state, s32 count, s32 arg3, u32 *list);
extern s32 func_8008E9F0(void *, s32, void *);
extern void func_80095AA0(Obj8008D5FC *, void *, void *, s32);
extern s32 func_80087FC0(s32, s32, s32, s32, s32);

void func_8008D5FC(Obj8008D5FC *arg0, s32 arg1) {
    func_80095AA0(arg0, func_8008EADC, func_8008E9F0, 1);
    arg0->unk14 = func_80087FC0(0, 0, arg1, 1, 0x20);
    arg0->unk24 = 1;
    arg0->unk30 = 0;
    arg0->unk1C = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk20 = 0.0f;
    arg0->unk18 = 1.0f;
}
