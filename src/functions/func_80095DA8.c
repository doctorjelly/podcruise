/* Specification: specs/func_80095DA8.md (func_80095DA8) */
#include "podcruise/types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Cmd80095DA8;

typedef struct {
    u8 pad0[0x14];
    u32 unk14;
    u8 pad18[0x4];
    u32 unk1C;
} Obj80095DA8;

extern u32 func_80088360(u32);

#define CMD_SPAN(pkt, base, len) { Cmd80095DA8 *_c = (Cmd80095DA8 *)(pkt); _c->w0 = 0x08000000 | ((u32)(base) & 0xFFFF); _c->w1 = (u32)(len) & 0xFFFF; }
#define CMD_LOAD(pkt, addr) { Cmd80095DA8 *_c = (Cmd80095DA8 *)(pkt); _c->w0 = 0x04000000; _c->w1 = func_80088360(addr); }

Cmd80095DA8 *func_80095DA8(Obj80095DA8 *obj, u32 pos, u32 arg2, u32 count, Cmd80095DA8 *cmd) {
    u32 end;
    u32 span;
    u32 limit;
    u32 n;
    Cmd80095DA8 *p;

    p = cmd;
    end = obj->unk14 + obj->unk1C * 2;
    if (pos < obj->unk14) {
        pos += obj->unk1C * 2;
    }
    span = count * 2;
    limit = span + pos;
    if (end < limit) {
        n = ((s32)(end - pos) >> 1) * 2;
        CMD_SPAN(p++, arg2, n);
        CMD_LOAD(p++, pos);
        CMD_SPAN(p++, arg2 + n, ((s32)(limit - end) >> 1) * 2);
        CMD_LOAD(p++, obj->unk14);
    } else {
        CMD_SPAN(p++, arg2, span);
        CMD_LOAD(p++, pos);
    }
    CMD_SPAN(p++, 0, span);
    return p;
}
