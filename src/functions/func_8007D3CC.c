/* Recovered from the specification in specs/func_8007D3CC.md (worker batch 08). */
#include "podcruise/types.h"

typedef struct Obj7D3CC {
    /* 0x00 */ f32 unk00;
    /* 0x04 */ f32 unk04;
    /* 0x08 */ f32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ void *unk20;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ struct Obj7D3CC *unk28;
} Obj7D3CC;

typedef struct Sub7D3CC {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ void *unk20;
} Sub7D3CC;

typedef struct Trig7D3CC {
    /* 0x00 */ u8 unk00[0xC];
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ u8 unk10[0x30];
    /* 0x40 */ void *unk40;
    /* 0x44 */ void *unk44;
    /* 0x48 */ void *unk48;
    /* 0x4C */ Sub7D3CC *unk4C;
} Trig7D3CC;

extern void func_80006EB4(void *, f32);
extern f32 func_800154D0(f32 *);
extern void func_80015538(f32 *, f32 *, f32 *);
extern void func_80017B7C(void *, f32, f32, f32);
extern void func_80017BA8(void *, f32 *);
extern void func_80017C18(void *, f32 *);
extern s32 func_800181BC(void *, s32, s32, s32, s32);
extern void func_8007B544(void *, s32, s32, f32);
extern Trig7D3CC *func_8007C4C8(void *);
extern void *func_8007D310(void *, void *, s32);
extern s32 func_80082BE0(void);

extern Obj7D3CC *D_800A66D4;
extern s32 D_800A66D8;

void func_8007D3CC(Obj7D3CC *object, void *arg1) {
    Trig7D3CC *trig;
    void *node;
    f32 matrix[4][4];

    while (object != 0) {
        if (object->unk24 == 0x6C) {
            node = func_8007D310(object, arg1, 3);
            if (node != 0) {
                func_80017B7C(node, object->unk00 + 8.0f, object->unk04,
                              object->unk08 - 24.0f);
            }
        }
        if (object->unk24 == 0x64) {
            object->unk26 |= 2;
        }
        if (object->unk24 == 0x69) {
            object->unk26 |= 0x20;
            func_8007B544(object->unk20, 0x10000010, 0, 0.6f);
        }
        if (object->unk24 == 0x68) {
            D_800A66D4 = object;
        }
        if (object->unk24 == 0xC9) {
            func_800181BC(object->unk20, 0, -3, 0x10, 3);
        }
        if (object->unk24 == 0xCA) {
            func_800181BC(object->unk20, 0, -5, 0x10, 3);
            object->unk26 |= 2;
            if (D_800A66D8 == 1) {
                D_800A66D4 = object;
            }
        }
        if (object->unk24 == 0xCB) {
            object->unk26 |= 0x20;
        }
        if (object->unk24 == 0xD0) {
            node = func_8007D310(object, arg1, 2);
            trig = func_8007C4C8(object);
            trig->unk0C |= 1;
            trig->unk48 = node;
            if (trig->unk44 != 0) {
                func_80006EB4(trig->unk44, (f32)1.0);
            }
            if (trig->unk40 != 0) {
                func_80006EB4(trig->unk40, (f32)1.0);
            }
            if (node != 0) {
                if (object->unk20 != 0) {
                    func_80017C18(trig->unk4C->unk20, &matrix[0][0]);
                    if (trig->unk48 != 0) {
                        if (trig->unk48 != 0) {
                            func_800181BC(trig->unk48, 2, 3, 0x10, 2);
                        }
                        func_80017BA8(trig->unk48, &matrix[0][0]);
                    }
                }
            }
        }
        if (object->unk24 == 0xD4) {
            func_800181BC(object->unk20, 0, -5, 0x10, 3);
            object->unk26 |= 2;
        }
        if (object->unk24 == 0xD3) {
            node = func_8007D310(object, arg1, 2);
            if (node != 0) {
                matrix[0][0] = 1.0f;
                matrix[0][1] = 0.0f;
                matrix[0][2] = 0.0f;
                matrix[0][3] = 0.0f;
                matrix[1][0] = 0.0f;
                matrix[1][1] = 1.0f;
                matrix[1][2] = 0.0f;
                matrix[1][3] = 0.0f;
                matrix[2][0] = 0.0f;
                matrix[2][1] = 0.0f;
                matrix[2][2] = 1.0f;
                matrix[2][3] = 0.0f;
                matrix[3][0] = 0.0f;
                matrix[3][1] = 0.0f;
                matrix[3][2] = 0.0f;
                matrix[3][3] = 1.0f;
                matrix[1][0] = object->unk0C;
                matrix[1][1] = object->unk10;
                matrix[1][2] = object->unk14;
                func_80015538(&matrix[0][0], &matrix[1][0], &matrix[2][0]);
                func_80015538(&matrix[2][0], &matrix[0][0], &matrix[1][0]);
                func_800154D0(&matrix[0][0]);
                func_800154D0(&matrix[1][0]);
                matrix[3][0] = object->unk00;
                matrix[3][1] = object->unk04;
                matrix[3][2] = object->unk08;
                matrix[3][2] = matrix[3][2] - object->unk1C * 0.5f;
                func_80017BA8(node, &matrix[0][0]);
                if (object->unk20 != 0) {
                    func_800181BC(object->unk20, 2, -4, 0x10, 3);
                }
            }
            object->unk26 |= 1;
        }
        if (object->unk24 == 0xD5) {
            object->unk26 |= 0x24;
        }
        if (object->unk24 == 0x132) {
            object->unk26 |= 0x24;
            if ((f32)func_80082BE0() / (f32)2147483648.0 > 0.5f) {
                object->unk26 |= 8;
            }
        }
        if (object->unk24 == 0x133) {
            func_8007B544(object->unk20, 0x10, 0, (f32)1.0);
        }
        if (object->unk24 == 0x134) {
            node = func_8007D310(object, arg1, 0);
            trig = func_8007C4C8(object);
            trig->unk0C |= 1;
            trig->unk48 = node;
            if (trig->unk44 != 0) {
                func_80006EB4(trig->unk44, (f32)1.0);
            }
            if (trig->unk40 != 0) {
                func_80006EB4(trig->unk40, (f32)1.0);
            }
            if (node != 0) {
                if (object->unk20 != 0) {
                    func_80017C18(trig->unk4C->unk20, &matrix[0][0]);
                    if (trig->unk48 != 0) {
                        if (trig->unk48 != 0) {
                            func_800181BC(trig->unk48, 2, 3, 0x10, 2);
                        }
                        func_80017BA8(trig->unk48, &matrix[0][0]);
                    }
                }
            }
        }
        if (object->unk24 == 0x136) {
            node = func_8007D310(object, arg1, 0);
            if (node != 0) {
                if (object->unk20 != 0) {
                    func_80017C18(object->unk20, &matrix[0][0]);
                    if (node != 0) {
                        func_800181BC(node, 2, 3, 0x10, 2);
                    }
                    func_80017BA8(node, &matrix[0][0]);
                }
            }
            object->unk26 |= 1;
        }
        if (object->unk24 == 0x138) {
            object->unk26 |= 0x20;
            func_8007B544(object->unk20, 0x10000010, 0, (f32)1.0);
        }
        if (object->unk24 == 0x13A) {
            object->unk26 |= 0x20;
            if (object->unk20 != 0) {
                if (object->unk20 != 0) {
                    func_800181BC(object->unk20, 2, -4, 0x10, 3);
                }
            }
        }
        if (object->unk24 == 0x1F5) {
            if (object->unk20 != 0) {
                if (object->unk20 != 0) {
                    func_800181BC(object->unk20, 2, -4, 0x10, 3);
                }
            }
        }
        object = object->unk28;
    }
}
