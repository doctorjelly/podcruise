/* Specification: specs/func_80035354.md (state-transition request handler) */
#include "podcruise/types.h"

typedef struct {
    u32 words[2];
} GfxWord;

typedef struct {
    u8 pad0[8];
    u8 partA[16];
    u8 partB[16];
} Entry;

extern s32 D_800A3D3C;
extern s32 D_800A3D40;
extern s32 D_800A3D60;
extern s32 D_800A3D64;
extern Entry D_800A3DC8[];
extern s32 D_800A3FA8[];
extern s32 D_800A4004;
extern GfxWord *D_80112C90;
extern void func_80038C3C(void);

#define EMIT(w0v, w1v) { GfxWord *g = D_80112C90++; g->words[0] = (u32)(w0v); g->words[1] = (u32)(unsigned long)(w1v); }

s32 func_80035354(request, index)
s32 request;
s16 index;
{
    s32 result = 0;

    if (request & 8) {
        if (D_800A3D64 != 0) {
            D_800A3D64 = 0;
            result = 8;
        }
    }
    if (request & 0x10) {
        if (D_800A3D3C == 0) {
            D_800A3D3C = 1;
            D_800A3D40 = 1;
            result |= 0x10;
        }
    }
    if (request & 0x100) {
        if (D_800A3D3C != 0) {
            func_80038C3C();
            D_800A3D3C = 0;
            result |= 0x100;
        }
    }
    if (request & 1) {
        D_800A3D60 = !D_800A3D60;
        result |= 1;
    }
    if (request & 4) {
        if (D_800A4004 == 0) {
            D_800A4004 = 1;
            if (D_800A3FA8[index] == 1) {
                EMIT(0xDB020000, 0x18)
                EMIT(0xDC08060A, D_800A3DC8[index].partA)
                EMIT(0xDC08090A, &D_800A3DC8[index])
            } else {
                EMIT(0xDB020000, 0x30)
                EMIT(0xDC08060A, D_800A3DC8[index].partA)
                EMIT(0xDC08090A, D_800A3DC8[index].partB)
                EMIT(0xDC080C0A, &D_800A3DC8[index])
            }
            result |= 4;
        }
    }
    return result;
}
