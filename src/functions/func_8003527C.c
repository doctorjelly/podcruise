/* Recovered from the specification in worker notes specs/func_8003527C.md. */
#include "podcruise/types.h"

typedef struct {
    u32 hi;
    u32 lo;
} CommandWord;

typedef struct {
    u8 unk00[0x34];
    u32 unk34;
    u32 unk38;
} MatrixPair;

extern CommandWord *D_80112C90;

void func_8003527C(MatrixPair *arg0) {
    { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDA380003; cmd->lo = arg0->unk34; }
    { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDC38000E; cmd->lo = arg0->unk38; }
    { CommandWord *cmd = D_80112C90++; cmd->hi = 0xDB0C0000; cmd->lo = 0x00010000; }
}
