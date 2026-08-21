/* Specification: specs/func_80091E34.md (worker-authored) */
#include "podcruise/types.h"

typedef union {
    u16 raw;
    struct {
        u8 a;
        u8 b;
    } p;
} Key80091E34;

typedef struct {
    u16 h[128];
    u8 cur;
    u8 mask[256];
} Entry80091E34;

typedef struct {
    u8 pad[0x60];
    s32 start;
    u8 count;
} Obj80091E34;

extern s32 func_80091354(Obj80091E34 *obj, Entry80091E34 *e, s32 arg2, u8 arg3);

s32 func_80091E34(Obj80091E34 *obj, Key80091E34 key, Entry80091E34 *e) {
    s32 found;
    s32 start;
    s32 slot;
    s32 ret;
    s32 j;
    u8 i;

    found = 0;
    slot = key.p.b / 4 + (key.p.a % 8) * 32;

    for (i = 0; i < obj->count; i++) {
        if (i > 0) {
            start = 1;
        } else {
            start = obj->start;
        }
        if (i == key.p.a || (e->mask[slot] & (1 << (i % 8))) != 0) {
            if (i != e->cur) {
                ret = func_80091354(obj, e, 0, i);
                if (ret != 0 && ret != 3) {
                    return ret;
                }
                e->cur = i;
            }
            if (found < 2) {
                if (start < 0x80) {
                    j = start * 2;
                    do {
                        if (key.raw == *(u16 *)((u8 *)e + j)) {
                            found++;
                        }
                        j += 2;
                        if (found >= 2) {
                            break;
                        }
                    } while (j < 0x100);
                }
            }
            if (found >= 2) {
                return 2;
            }
        }
    }
    return found;
}
