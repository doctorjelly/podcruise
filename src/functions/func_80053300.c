/* Recovered per specification specs/func_80053300.md. */
#include "podcruise/types.h"

typedef struct {
    u8 unk_000[0x124];
    s32 unk_124;
} Func80053300Object;

extern s32 D_800A52BC;
extern s32 func_80053220(s32);

void func_80053300(Func80053300Object *object) {
    if (func_80053220(0x40) != 0) {
        if (D_800A52BC >= 2) {
            object->unk_124 = object->unk_124 + 1;
            if (object->unk_124 >= 8) {
                object->unk_124 = 4;
            }
        } else {
            object->unk_124 = object->unk_124 + 1;
            if (object->unk_124 >= 5) {
                object->unk_124 = 0;
            }
        }
    }
}
