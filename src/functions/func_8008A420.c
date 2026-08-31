/* Independently written from specs/functions/recovered/medium_control_math_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
} Slot8008A420;

typedef union {
    u16 half;
    struct {
        u8 hi;
        u8 lo;
    } byte;
} Link8008A420;

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    u8 pad0C[0x50];
    s32 unk5C;
    u8 unk60[4];
    u8 unk64;
    u8 unk65;
} Obj8008A420;

typedef struct {
    s32 unk00;
    u16 unk04;
    Link8008A420 unk06;
    s32 unk08;
    u8 unk0C[4];
    u8 unk10[16];
} Entry8008A420;

extern s32 func_800926A0(Obj8008A420 *, u16, void *, s32, s32, s32 *);
extern s32 func_80091FD0(Obj8008A420 *, s32);
extern s32 func_80092050(s32, s32, u16, Entry8008A420 *);
extern s32 func_80091354(Obj8008A420 *, Link8008A420 *, u8, u8);
extern s32 func_8008A5F8(Obj8008A420 *, Link8008A420 *, u8, u8, Link8008A420 *);
extern void func_80092850(Entry8008A420 *, s32);
extern s32 func_800928F0(s32, s32, u16, Entry8008A420 *, s32);

s32 func_8008A420(Obj8008A420 *obj, u16 n, void *p, s32 arg3, s32 arg4) {
    Slot8008A420 slot;
    Link8008A420 table[128];
    Entry8008A420 entry;
    Link8008A420 cur;
    s32 ret;
    u8 last;
    u8 lo;
    u8 limit;

    if (n == 0 || p == 0) {
        return 5;
    }
    ret = func_800926A0(obj, n, p, arg3, arg4, &slot.unk04);
    if (ret != 0) {
        return ret;
    }
    if (obj->unk65 != 0) {
        ret = func_80091FD0(obj, 0);
        if (ret != 0) {
            return ret;
        }
    }
    ret = func_80092050(obj->unk04, obj->unk08, (u16)(obj->unk5C + slot.unk04), &entry);
    if (ret != 0) {
        return ret;
    }
    last = entry.unk06.byte.hi;
    lo = entry.unk06.byte.lo;
    limit = obj->unk64;
    while (last < limit) {
        ret = func_80091354(obj, table, 0, last);
        if (ret != 0) {
            return ret;
        }
        ret = func_8008A5F8(obj, table, lo, last, &cur);
        if (ret != 0) {
            return ret;
        }
        ret = func_80091354(obj, table, 1, last);
        if (ret != 0) {
            return ret;
        }
        if (cur.half == 1) {
            break;
        }
        limit = obj->unk64;
        last = cur.byte.hi;
        lo = cur.byte.lo;
    }
    if (last >= obj->unk64) {
        return 3;
    }
    func_80092850(&entry, 0x20);
    return func_800928F0(obj->unk04, obj->unk08, (u16)(obj->unk5C + slot.unk04), &entry, 0);
}
