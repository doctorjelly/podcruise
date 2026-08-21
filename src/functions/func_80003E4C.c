/* Recovered from specification specs/func_80003E4C.md */
#include "podcruise/types.h"

typedef struct Object {
    u8 unk00[0xC];
    u16 unk0C;
    u8 unk0E[0xA];
    struct Object **unk18;
} Object;

extern s32 D_8009A28C;
extern s32 D_8009A290;
extern s32 D_800AEC78;

extern s32 func_80017DA4(Object *obj);
extern s32 func_80017DAC(Object *obj);
extern s32 func_800182FC(Object *obj, s32 arg1);
extern void func_80017C18(Object *obj, void *buffer);
extern void func_80017C98(Object *obj, void *buffer);
extern void func_8000556C(void *buffer);
extern void func_80005AFC(void);
extern void func_80003BF8(Object *obj, s32 arg1, s32 arg2);

void func_80003E4C(Object *obj, s32 arg1, s32 arg2) {
    s32 count;
    s32 type;
    u8 buffer[0x40];
    Object *child;
    s32 index;

    type = func_80017DA4(obj);
    if (type == 0x3064) {
        func_80003BF8(obj, arg1, arg2);
        return;
    }
    if (type & 0x4000) {
        if (type & 0x8000) {
            if (obj->unk0C & 8) {
                arg2 |= 1;
            } else {
                arg2 |= 3;
            }
            if (type == 0xD064) {
                func_80017C98(obj, buffer);
            } else {
                func_80017C18(obj, buffer);
            }
            func_8000556C(buffer);
            D_800AEC78 = 1;
        }
        count = func_80017DAC(obj);
        for (index = 0; index < count; index++) {
            child = obj->unk18[index];
            if (child != 0) {
                if ((func_800182FC(child, 0) & D_8009A28C) == D_8009A28C) {
                    if (func_800182FC(child, 0) & D_8009A290) {
                        func_80003E4C(child, arg1, arg2);
                    }
                }
            }
        }
        if (type & 0x8000) {
            func_80005AFC();
            D_800AEC78 = 1;
        }
    }
}
