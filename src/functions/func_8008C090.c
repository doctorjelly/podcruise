/* Specification: specs/func_8008C090.md (worker scratchpad) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ u8 pad04[0xC];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} Struct8008C090;

extern Struct8008C090 *D_800A7F54;
extern void *func_8008CA80(void);
extern void func_8008CAA0(void *);

void func_8008C090(s32 arg0, s32 arg1, s32 arg2) {
    register void *sp;

    sp = func_8008CA80();
    D_800A7F54->unk10 = arg0;
    D_800A7F54->unk14 = arg1;
    D_800A7F54->unk02 = arg2;
    func_8008CAA0(sp);
}
