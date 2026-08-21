/* Independently written from scratchpad spec specs/func_8007B430.md. */

#include "podcruise/types.h"

typedef struct Payload8007B430 {
    u8 unk_00[0xC];
    void *unk_0C;
} Payload8007B430;

typedef struct Node8007B430 {
    struct Payload8007B430 *unk_00;
    u8 unk_04[0x10];
    s32 unk_14;
    struct Node8007B430 **unk_18;
} Node8007B430;

extern u32 func_80017DA4(const void *object);
extern s32 func_80017DAC(const void *object);

void *func_8007B430(Node8007B430 *object) {
    void *result;
    Node8007B430 *child;
    Node8007B430 **cursor;
    Payload8007B430 *payload;
    void *value;
    Node8007B430 *node;
    s32 index;

    result = 0;
    if (object != 0) {
        if (func_80017DA4(object) == 0x3064) {
            node = object;
            if (object->unk_14 > 0) {
                cursor = object->unk_18;
                index = 0;
                do {
                    child = *cursor;
                    payload = child->unk_00;
                    if (payload != 0) {
                        value = payload->unk_0C;
                        if (value != 0) {
                            return value;
                        }
                    }
                    index++;
                    cursor++;
                } while (index < node->unk_14);
            }
        } else if (func_80017DA4(object) & 0x4000) {
            for (index = 0; index < func_80017DAC(object); index++) {
                result = func_8007B430(object->unk_18[index]);
                if (result != 0) {
                    return result;
                }
            }
        }
    }
    return result;
}
