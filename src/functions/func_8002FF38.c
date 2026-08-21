/* Specification: $S/specs/func_8002FF38.md */
#include "podcruise/types.h"

#define PTR2INT(p) ((u32)(unsigned long)(p))
#define INT2PTR(x) ((u8 *)(unsigned long)(x))

typedef struct {
    s32 unk_0;
    s32 unk_4;
} Entry8002FF38;

typedef struct {
    s32 unk_0;
    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    s32 unk_8;
    s16 unk_C;
    s16 unk_E;
    Entry8002FF38 *unk_10;
} Object8002FF38;

extern u8 D_13307F0[];

extern void func_80011D60(u8 *source, u8 *destination, s32 length);
extern u8 *func_8002FAFC(void);
extern void func_8002FAC4(u8 *top);

Object8002FF38 *func_8002FF38(s32 index) {
    Object8002FF38 *obj;
    s32 size;
    u8 *dest;
    u8 *base;
    s32 i;
    s32 total;
    u32 range[4];

    dest = func_8002FAFC();
    base = D_13307F0;
    func_80011D60(base, (u8 *)&total, 4);
    if (index < 0 || index >= total) {
        return (Object8002FF38 *)0;
    }
    func_80011D60(base + index * 4 + 4, (u8 *)&range[2], 8);
    func_80011D60(base + range[2], dest, 0x14);
    obj = (Object8002FF38 *)dest;
    if (obj->unk_4 != 2 || obj->unk_8 != 0) {
        size = obj->unk_C * 8;
        dest += 0x14;
        func_80011D60(base + (range[2] + 0x14), dest, size);
        obj->unk_10 = (Entry8002FF38 *)dest;
        for (i = 0; i < obj->unk_C; i++) {
        }
        i = 0;
        if (obj->unk_8 != 0) {
            dest += size;
            dest = INT2PTR((PTR2INT(dest) + 0xF) & ~0xF);
            size = obj->unk_10->unk_4 - obj->unk_8;
            func_80011D60(base + (range[2] + obj->unk_8), dest, size);
            obj->unk_8 = (s32)PTR2INT(dest);
        }
        dest += size;
            dest = INT2PTR((PTR2INT(dest) + 0xF) & ~0xF);
        for (; i < obj->unk_C; i++) {
            size = (i + 1 == obj->unk_C ? (s32)(range[3] - range[2]) : obj->unk_10[i + 1].unk_4) - obj->unk_10[i].unk_4;
            func_80011D60(base + (range[2] + obj->unk_10[i].unk_4), dest, size);
            obj->unk_10[i].unk_4 = (s32)PTR2INT(dest);
            dest += size;
            dest = INT2PTR((PTR2INT(dest) + 0xF) & ~0xF);
        }
    }
    func_8002FAC4(dest);
    return obj;
}
