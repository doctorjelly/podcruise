/* Specification: $S/specs/func_80030174.md */
#include "podcruise/types.h"

typedef struct {
    s32 unk_0;
    s32 unk_4;
    s32 unk_8;
    u8 *unk_C;
} Object80030174;

extern u8 D_12C7F30[];

extern void func_80011D60(u8 *source, u8 *destination, s32 length);
extern u8 *func_8002FAFC(void);
extern void func_8002FAC4(u8 *top);

void func_80030174(s32 index, Object80030174 **out) {
    s32 start;
    s32 size;
    u8 *dest;
    s32 count;
    u32 range[2];
    Object80030174 *obj;
    s32 i;
    u8 *table[1];

    table[0] = D_12C7F30;
    func_80011D60(table[0], (u8 *)&count, 4);
    if (index < 0 || index >= count) {
        *out = (Object80030174 *)0;
        return;
    }
    func_80011D60(table[0] + index * 4 + 4, (u8 *)range, 8);
    start = range[0];
    dest = func_8002FAFC();
    size = range[1] - range[0];
    func_80011D60(table[0] + start, dest, size);
    *out = (Object80030174 *)func_8002FAFC();
    (*out)->unk_C = func_8002FAFC() + 0x10;
    obj = *out;
    for (i = 0; i < obj->unk_4; i++) {
    }
    func_8002FAC4(dest + size);
}
