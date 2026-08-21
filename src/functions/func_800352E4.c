/* Recovered from the specification in worker notes specs/func_800352E4.md. */
#include "podcruise/types.h"

typedef struct {
    u32 hi;
    u32 lo;
} CommandWord;

extern CommandWord *D_80112C90;
extern u32 D_801134D0;
extern u32 D_801134D4;

void func_800352E4(void) {
    { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDA380003; cmd->lo = D_801134D0; }
    { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDC38000E; cmd->lo = D_801134D4; }
    { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDB0C0000; cmd->lo = 0x00010000; }
}
