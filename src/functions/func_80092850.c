/* Specification: scratchpad specs/func_80092850.md (buffer zero-fill helper). */
#include "podcruise/types.h"

#pragma pack(1)
typedef struct {
    u32 value;
} UnalignedWord;
#pragma pack()

void func_80092850(u8 *cursor, s32 length) {
    s32 head;
    s32 chunk;
    u8 *limit;
    u8 *end;

    if (length >= 12) {
        head = -(s32)(unsigned long)cursor & 3;
        length -= head;
        if (head != 0) {
            ((UnalignedWord *)cursor)->value = 0;
            cursor += head;
        }

        chunk = length & ~0x1F;
        length -= chunk;
        if (chunk != 0) {
            limit = chunk + cursor;
            do {
                ((u32 *)cursor)[0] = 0;
                ((u32 *)cursor)[1] = 0;
                ((u32 *)cursor)[2] = 0;
                ((u32 *)cursor)[3] = 0;
                ((u32 *)cursor)[4] = 0;
                ((u32 *)cursor)[5] = 0;
                ((u32 *)cursor)[6] = 0;
                ((u32 *)cursor)[7] = 0;
                cursor += 32;
            } while (cursor != limit);
        }

        chunk = length & ~3;
        length -= chunk;
        if (chunk != 0) {
            limit = chunk + cursor;
            do {
                *(u32 *)cursor = 0;
                cursor += 4;
            } while (cursor != limit);
        }
    }

    if (length > 0) {
        end = length + cursor;
        do {
            *cursor = 0;
            cursor++;
        } while (cursor != end);
    }
}
