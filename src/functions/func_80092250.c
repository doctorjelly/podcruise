/* Independently written from scratchpad spec specs/func_80092250.md. */

#include "podcruise/types.h"

void *func_80092250(void *arg0, void *arg1, s32 arg2);

void *func_80092250(void *arg0, void *arg1, s32 arg2) {
    u8 *from;
    u8 *to;
    void *result;
    u8 *end;
    s32 left;
    s32 misalign;

    result = arg1;
    if (arg2 == 0) {
        return result;
    }
    if (arg0 == arg1) {
        return result;
    }

    from = (u8 *)arg0;
    to = (u8 *)arg1;
    left = arg2;

    if (to < from || to >= from + left) {
        if (left >= 0x10) {
            misalign = (s32)((long)from & 3);
            if (misalign == (s32)((long)to & 3)) {
                if (misalign == 1) {
                    to[0] = from[0];
                    *(s16 *)(to + 1) = *(s16 *)(from + 1);
                    from += 3;
                    to += 3;
                    left -= 3;
                } else if (misalign == 2) {
                    *(s16 *)to = *(s16 *)from;
                    from += 2;
                    to += 2;
                    left -= 2;
                } else if (misalign != 0) {
                    to[0] = from[0];
                    from += 1;
                    to += 1;
                    left -= 1;
                }
                while (left >= 0x20) {
                    *(s32 *)(to + 0) = *(s32 *)(from + 0);
                    *(s32 *)(to + 4) = *(s32 *)(from + 4);
                    *(s32 *)(to + 8) = *(s32 *)(from + 8);
                    *(s32 *)(to + 12) = *(s32 *)(from + 12);
                    *(s32 *)(to + 16) = *(s32 *)(from + 16);
                    *(s32 *)(to + 20) = *(s32 *)(from + 20);
                    *(s32 *)(to + 24) = *(s32 *)(from + 24);
                    *(s32 *)(to + 28) = *(s32 *)(from + 28);
                    from += 0x20;
                    to += 0x20;
                    left -= 0x20;
                }
                while (left >= 0x10) {
                    *(s32 *)(to + 0) = *(s32 *)(from + 0);
                    *(s32 *)(to + 4) = *(s32 *)(from + 4);
                    *(s32 *)(to + 8) = *(s32 *)(from + 8);
                    *(s32 *)(to + 12) = *(s32 *)(from + 12);
                    from += 0x10;
                    to += 0x10;
                    left -= 0x10;
                }
                while (left >= 4) {
                    *(s32 *)to = *(s32 *)from;
                    from += 4;
                    to += 4;
                    left -= 4;
                }
            }
        }
        if (left != 0) {
            end = from + left;
            do {
                to[0] = from[0];
                from += 1;
                to += 1;
            } while (from != end);
        }
        return result;
    }

    from += left;
    to += left;
    if (left >= 0x10) {
        misalign = (s32)((long)from & 3);
        if (misalign == (s32)((long)to & 3)) {
            if (misalign == 3) {
                to[-1] = from[-1];
                *(s16 *)(to - 3) = *(s16 *)(from - 3);
                from -= 3;
                to -= 3;
                left -= 3;
            } else if (misalign == 2) {
                *(s16 *)(to - 2) = *(s16 *)(from - 2);
                from -= 2;
                to -= 2;
                left -= 2;
            } else if (misalign != 0) {
                to[-1] = from[-1];
                from -= 1;
                to -= 1;
                left -= 1;
            }
            while (left >= 0x20) {
                *(s32 *)(to - 4) = *(s32 *)(from - 4);
                *(s32 *)(to - 8) = *(s32 *)(from - 8);
                *(s32 *)(to - 12) = *(s32 *)(from - 12);
                *(s32 *)(to - 16) = *(s32 *)(from - 16);
                *(s32 *)(to - 20) = *(s32 *)(from - 20);
                *(s32 *)(to - 24) = *(s32 *)(from - 24);
                *(s32 *)(to - 28) = *(s32 *)(from - 28);
                *(s32 *)(to - 32) = *(s32 *)(from - 32);
                from -= 0x20;
                to -= 0x20;
                left -= 0x20;
            }
            while (left >= 0x10) {
                *(s32 *)(to - 4) = *(s32 *)(from - 4);
                *(s32 *)(to - 8) = *(s32 *)(from - 8);
                *(s32 *)(to - 12) = *(s32 *)(from - 12);
                *(s32 *)(to - 16) = *(s32 *)(from - 16);
                from -= 0x10;
                to -= 0x10;
                left -= 0x10;
            }
            while (left >= 4) {
                *(s32 *)(to - 4) = *(s32 *)(from - 4);
                from -= 4;
                to -= 4;
                left -= 4;
            }
        }
    }
    if (left != 0) {
        from -= 1;
        to -= 1;
        end = from - left;
        do {
            to[0] = from[0];
            from -= 1;
            to -= 1;
        } while (from != end);
    }
    return result;
}
