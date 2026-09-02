/* Independently written from specs/functions/recovered/medium_control_math_tranche.md. */
#include "podcruise/types.h"

typedef union {
    u16 half;
    struct {
        u8 hi;
        u8 lo;
    } byte;
} Link80089F70;

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    u8 pad0C[0x44];
    s32 unk50;
    u8 pad54[0x8];
    s32 unk5C;
    s32 unk60;
    u8 pad64[0x1];
    u8 unk65;
} Obj80089F70;

typedef struct {
    s32 unk00;
    u16 unk04;
    Link80089F70 unk06;
    s32 unk08;
    u8 unk0C[4];
    u8 unk10[16];
} Entry80089F70;

typedef struct {
    s32 unk00;
    s32 unk04;
    u16 unk08;
    u8 unk0A[4];
    u8 unk0E[16];
} Out80089F70;

extern s32 func_80091280(Obj80089F70 *);
extern s32 func_80091354(Obj80089F70 *, Link80089F70 *, u8, u8);
extern s32 func_80091FD0(Obj80089F70 *, s32);
extern s32 func_80092050(s32, s32, u16, Entry80089F70 *);
extern void func_80092250(void *, void *, s32);

s32 func_80089F70(Obj80089F70 *obj, s32 idx, Out80089F70 *out) {
    s32 count;
    s32 ret;
    Link80089F70 table[128];
    Entry80089F70 entry;
    Link80089F70 cur;
    s32 last;

    if (idx >= obj->unk50 || idx < 0) {
        return 5;
    }
    if ((obj->unk00 & 1) == 0) {
        return 5;
    }
    ret = func_80091280(obj);
    if (ret != 0) {
        return ret;
    }
    if (obj->unk65 != 0) {
        ret = func_80091FD0(obj, 0);
        if (ret != 0) {
            return ret;
        }
    }
    ret = func_80092050(obj->unk04, obj->unk08, (u16)(obj->unk5C + idx), &entry);
    if (ret != 0) {
        return ret;
    }
    if (entry.unk04 == 0 || entry.unk00 == 0) {
        return 5;
    }
    count = 0;
    last = 0xFF;
    cur = entry.unk06;
    for (;;) {
        if ((s32)cur.half < obj->unk60) {
            break;
        }
        if (last != cur.byte.hi) {
            last = cur.byte.hi;
            ret = func_80091354(obj, table, 0, last);
            if (ret != 0) {
                return ret;
            }
        }
        count++;
        cur = table[cur.byte.lo];
    }
    if (cur.half != 1) {
        return 3;
    }
    out->unk00 = count << 8;
    out->unk08 = entry.unk04;
    out->unk04 = entry.unk00;
    func_80092250(entry.unk10, out->unk0E, 16);
    func_80092250(entry.unk0C, out->unk0A, 4);
    return 0;
}
