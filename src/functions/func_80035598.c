/* Specification: $S/specs/func_80035598.md */
#include "podcruise/types.h"

typedef struct {
    u32 hi;
    u32 lo;
} CommandWord;

extern CommandWord *D_80112C90;
extern s32 D_800A3D3C;
extern s32 D_800A3D40;
extern s32 D_800A3D60;
extern s32 D_800A3D64;
extern u8 D_800A3DB0[];
extern u8 D_800A3DB8[];
extern s32 D_800A4004;

extern void func_80038C3C(void);

void func_80035598(u32 flags) {
    if (flags & 0x1) {
        D_800A3D60 = !D_800A3D60;
    }
    if (flags & 0x8) {
        D_800A3D64 = 1;
    }
    if (flags & 0x10) {
        D_800A3D3C = 0;
        func_80038C3C();
    }
    if (flags & 0x100) {
        D_800A3D3C = 1;
        D_800A3D40 = 1;
    }
    if (flags & 0x4) {
        D_800A4004 = 0;
        { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDB020000; cmd->lo = 0x18; }
        { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDC08060A; cmd->lo = (u32)(unsigned long)D_800A3DB8; }
        { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDC08090A; cmd->lo = (u32)(unsigned long)D_800A3DB0; }
    }
}
