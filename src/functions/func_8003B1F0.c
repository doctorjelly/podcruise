/* Implements specification $S/specs/func_8003B1F0.md (track-frame request builder). */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    f32 unk04;
    f32 unk08;
    f32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
} PcTrackRequest;

extern void func_8003B02C();

void func_8003B1F0(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    PcTrackRequest request;

    request.unk00 = arg0;
    request.unk04 = 0.0f;
    request.unk08 = arg6;
    request.unk0C = 0.0f;
    request.unk10 = arg2;
    request.unk14 = arg3;
    request.unk18 = arg4;
    request.unk1C = arg5;
    request.unk20 = 0;
    request.unk24 = 0;
    request.unk28 = 0;
    func_8003B02C(&request, arg1);
}
