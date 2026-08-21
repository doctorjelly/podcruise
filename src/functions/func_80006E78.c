/* Specification: specs/func_80006E78.md (entry corrected to 0x80006E74) */
#include "podcruise/types.h"

typedef struct Obj80006E74 {
    u8 pad[0x100];
    u32 flags;
    u8 pad2[0x10];
    f32 value;
    s32 result;
} Obj80006E74;

extern s32 func_80006704(Obj80006E74 *);

void func_80006E74(Obj80006E74 *obj, f32 value) {
    obj->value = value;
    obj->result = func_80006704(obj);
    obj->flags |= 0x1000000;
}
