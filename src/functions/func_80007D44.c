/* Specification: specs/func_80007D44.md (worker scratchpad) */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 *start;
    /* 0x04 */ u8 *end;
} PcBlobRange;

extern void *D_8009A32C[];
extern void *D_8009A388[];
extern PcBlobRange D_8009A3A8[];
extern s32 D_8009A460[];
extern PcBlobRange D_8009A4BC[];
extern s32 D_8009A574[];
extern PcBlobRange D_8009A5D0[];
extern s32 D_8009A688[];

extern void *func_8002FEE4(s32);
extern void func_80011D60(u8 *, void *, s32);
extern void func_80089384(void *, s32);

void func_80007D44(s32 kind, s32 index) {
    s32 scratch[3];
    void **slot;
    register u8 *start;
    u8 *end;
    s32 tag;
    void **buffer;

    (void)scratch;
    if (kind == 0) {
        slot = &D_8009A32C[index];
        start = D_8009A3A8[index].start;
        end = D_8009A3A8[index].end;
        tag = D_8009A460[index];
    } else if (kind == 1) {
        slot = &D_8009A32C[index];
        start = D_8009A4BC[index].start;
        end = D_8009A4BC[index].end;
        tag = D_8009A574[index];
    } else {
        slot = &D_8009A388[kind];
        start = D_8009A5D0[kind].start;
        end = D_8009A5D0[kind].end;
        tag = D_8009A688[kind];
    }
    if (*slot == 0) {
        buffer = func_8002FEE4(end - start + 0x10);
        if (buffer != 0) {
            buffer = (void **)(((unsigned long)buffer + 0xF) & ~0xFUL);
            func_80011D60(start, buffer, end - start);
            func_80089384(buffer, tag);
            *slot = buffer[1];
        }
    }
}
