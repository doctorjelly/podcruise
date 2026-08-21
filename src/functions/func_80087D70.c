/* Independently written from the specification scratchpad specs/func_80087D70.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s16 kind;
    /* 0x02 */ u8 channel;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
} Request80087D70;

extern s32 D_800A7B80;
extern s32 func_8008C900(void);
extern s32 func_8008C7B0(s32, void *, s32);
extern s32 func_8008C930(s32, void *, s32);

s32 func_80087D70(Request80087D70 *request, s32 channel, s32 direction, s32 arg3,
                  void *arg4, s32 arg5, void *arg6) {
    register s32 status;
    register s32 queue;

    if (D_800A7B80 == 0) {
        return -1;
    }
    if (direction == 0) {
        request->kind = 11;
    } else {
        request->kind = 12;
    }
    request->channel = channel;
    request->unk04 = arg6;
    request->unk08 = arg4;
    request->unk0C = arg3;
    request->unk10 = arg5;
    request->unk14 = 0;
    if (channel == 1) {
        queue = func_8008C900();
        status = func_8008C7B0(queue, request, 0);
    } else {
        queue = func_8008C900();
        status = func_8008C930(queue, request, 0);
    }
    return status;
}
