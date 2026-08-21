/* Recovered from specification func_80096AD0.md - buffer equality test. */
#include "podcruise/types.h"

/* The original reads the left operand a word at a time even when that operand
 * is not word aligned, which only happens for a word-sized object whose type
 * carries byte alignment. */
#pragma pack(1)
typedef struct {
    u32 word;
} UnalignedWord;
#pragma pack()

s32 func_80096AD0(const u8 *left, const u8 *right, s32 count) {
    const u8 *stop;
    u32 x;
    u32 y;
    s32 lead;
    s32 words;

    if (count >= 16) {
        if ((((s32)(long)left ^ (s32)(long)right) & 3) == 0) {
            lead = -(s32)(long)left & 3;
            count -= lead;
            if (lead != 0) {
                stop = lead + left;
                x = *left;
                do {
                    y = *right;
                    left++;
                    right++;
                    if (x != y) {
                        goto unequal;
                    }
                    x = *left;
                } while (left != stop);
            }
            words = count & ~3;
            count -= words;
            if (words != 0) {
                stop = words + left;
                x = *(const u32 *)left;
                do {
                    y = *(const u32 *)right;
                    left += 4;
                    right += 4;
                    if (x != y) {
                        goto unequal;
                    }
                    x = *(const u32 *)left;
                } while (left != stop);
            }
        } else {
            lead = -(s32)(long)right & 3;
            count -= lead;
            if (lead != 0) {
                stop = lead + left;
                x = *left;
                do {
                    y = *right;
                    left++;
                    right++;
                    if (x != y) {
                        goto unequal;
                    }
                    x = *left;
                } while (left != stop);
            }
            words = count & ~3;
            count -= words;
            if (words != 0) {
                stop = words + left;
                x = ((const UnalignedWord *)left)->word;
                do {
                    y = *(const u32 *)right;
                    left += 4;
                    right += 4;
                    if (x != y) {
                        goto unequal;
                    }
                    x = ((const UnalignedWord *)left)->word;
                } while (left != stop);
            }
        }
    }
    if (count > 0) {
        stop = count + left;
        x = *left;
        do {
            y = *right;
            left++;
            right++;
            if (x != y) {
                goto unequal;
            }
            x = *left;
        } while (left != stop);
    }
    return 0;
unequal:
    return 1;
}
