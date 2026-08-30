/* Independently written from scratchpad spec specs/func_8008D5A8.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ s32 unk14;
    /* 0x18 */ void *unk18;
    /* 0x1C */ void *unk1C;
} PcHandler;

extern void func_80095AA0(PcHandler *handler, void *enter, void *leave, s32 kind);
extern u32 *func_8008F980(void *, s32, s32, s32, u32 *);
extern s32 func_8008F950(PcHandler *handler, s32 kind, void *value);

void func_8008D5A8(PcHandler *handler, void *arg1, void *arg2) {
    func_80095AA0(handler, (void *)func_8008F980, (void *)func_8008F950, 6);
    handler->unk14 = 0;
    handler->unk18 = arg2;
    handler->unk1C = arg1;
}
