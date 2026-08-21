/* Independently written from scratchpad spec specs/func_80037C8C.md. */

#include "podcruise/types.h"

typedef struct Node80037C8C {
    u8 pad0[0xC];
    u16 flags;
    u8 padE[0xA];
    void **children;
} Node80037C8C;

typedef struct Mask80037C8C {
    u8 pad0[0x158];
    u32 required;
    u32 wanted;
} Mask80037C8C;

extern s16 D_800A3FD8;
extern s32 D_800A3FE8;
extern u8 D_800D9DB1;
typedef struct CommandWord80037C8C {
    u32 hi;
    u32 lo;
} CommandWord80037C8C;

extern CommandWord80037C8C *D_80112C90;
extern Mask80037C8C *D_80112C94;

extern u32 func_80033E08(void);
extern void func_80034650(u32 destination, f32 source[4][3]);
extern void func_80033F94(f32 source[4][3]);
extern void func_800344C8(void);
extern s32 func_80017DAC(Node80037C8C *node);
extern u32 func_800182FC(void *object, s32 selector);
extern void func_80038388(void *object);

void func_80037C8C(void *arg0, f32 arg1[4][3], Node80037C8C *arg2) {
    s32 skip;
    CommandWord80037C8C *gfx;
    s32 count;
    s32 index;
    u32 slot;
    void *child;






    if (D_800A3FE8 == 0) {
        slot = func_80033E08();
        if ((arg2->flags & 3) != 0) {
            func_80034650(slot, arg1);
            if (D_800D9DB1 != 0) {
                arg2->flags = arg2->flags & 0xFFFE;
            } else {
                arg2->flags = arg2->flags & 0xFFFD;
            }
        }
    }

    D_800A3FD8 = D_800A3FD8 + 1;
    if (D_800A3FD8 > 0x20) {
        skip = 1;
    } else {
        skip = 0;
        if (D_800A3FE8 != 0) {
            func_80033F94(arg1);
        } else {
            gfx = D_80112C90; D_80112C90 = gfx + 1; gfx->hi = 0xDA380000; gfx->lo = slot;
        }
    }

    count = func_80017DAC(arg2);
    {
        for (index = 0; index < count; index++) {
            child = arg2->children[index];
            if (child != 0) {
                if ((func_800182FC(child, 2) & D_80112C94->required) == D_80112C94->required) {
                    if ((func_800182FC(child, 2) & D_80112C94->wanted) != 0) {
                        func_80038388(child);
                    }
                }
            }
        }
    }

    if (skip == 0) {
        if (D_800A3FE8 != 0) {
            func_800344C8();
        } else {
            gfx = D_80112C90; D_80112C90 = gfx + 1; gfx->hi = 0xD8380002; gfx->lo = 0x40;
        }
    }
    D_800A3FD8 = D_800A3FD8 - 1;
    (void)arg0;
}
