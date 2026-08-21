/* Independently written from scratchpad spec specs/func_8003B184.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ u8 unk0C[0x24];
} PcMoveRequest;

extern void func_8003B02C(PcMoveRequest *request, void *context);

void func_8003B184(PcMoveRequest *source, void *context, f32 offset) {
    PcMoveRequest request;

    request = *source;
    request.unk08 = request.unk08 + offset;
    request.unk04 = 0.0f;
    func_8003B02C(&request, context);
}
