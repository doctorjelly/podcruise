/* Independently written from scratchpad spec specs/func_800926A0.md. */
#include "podcruise/types.h"

typedef struct Unk800926A0Entry {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u8 unk08[4];
    u8 unk0C[4];
    u8 unk10[16];
} Unk800926A0Entry;

typedef struct Unk800926A0Object {
    s32 flags;
    void *unk04;
    s32 unk08;
    u8 pad0C[0x44];
    s32 count;
    u8 pad54[8];
    s32 base;
} Unk800926A0Object;

extern s32 func_80091280(Unk800926A0Object *object);
extern s32 func_80092050(void *queue, s32 channel, u16 selector, void *buffer);

s32 func_800926A0(Unk800926A0Object *object, u16 tag, u32 key, u8 *name, u8 *extension, s32 *found) {
    s32 result;
    s32 i;
    s32 j;
    Unk800926A0Entry entry;
    u8 mismatch;

    if (!(object->flags & 1)) {
        return 5;
    }
    result = func_80091280(object);
    if (result != 0) {
        return result;
    }
    for (i = 0; i < object->count; i++) {
        result = func_80092050(object->unk04, object->unk08, (u16)(object->base + i), &entry);
        if (result != 0) {
            return result;
        }
        if (entry.unk04 == tag && entry.unk00 == key) {
            mismatch = 0;
            if (name != 0) {
                for (j = 0; j < 16; j++) {
                    if (entry.unk10[j] != name[j]) {
                        mismatch = 1;
                        break;
                    }
                }
            }
            if (extension != 0 && !mismatch) {
                for (j = 0; j < 4; j++) {
                    if (entry.unk0C[j] != extension[j]) {
                        mismatch = 1;
                        break;
                    }
                }
            }
            if (!mismatch) {
                *found = i;
                return result;
            }
        }
    }
    *found = -1;
    return 5;
}
