/* Independently written from the specification for the object retire request (specs/func_80041058.md). */

#include "podcruise/types.h"

typedef struct Obj80041058 Obj80041058;

typedef struct {
    /* 0x00 */ u8 pad00[0x60];
    /* 0x60 */ u32 unk60;
} Obj80041058Sub;

struct Obj80041058 {
    /* 0x00 */ u8 pad00[0x74];
    /* 0x74 */ s32 unk74;
    /* 0x78 */ u8 pad78[0x4];
    /* 0x7C */ s32 unk7C;
    /* 0x80 */ u8 pad80[0x74];
    /* 0xF4 */ Obj80041058Sub *unkF4;
};

extern void func_80040050(Obj80041058 *, f32);

void func_80041058(Obj80041058 *object) {
    if (object->unk7C != 0) {
        if (object->unk74 >= 0) {
            func_80040050(object, -2.0f);
            switch (object->unk7C) {
                case 1:
                    break;
                case 4:
                    break;
                case 5:
                    if (object->unkF4 != 0) {
                        object->unkF4->unk60 |= 0x80000;
                    }
                    break;
            }
        }
    }
}
