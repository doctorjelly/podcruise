/* Independently written from specs/functions/display_list_pipe_sync.md. */

#include "podcruise/types.h"

typedef struct {
    u32 command;
    u32 payload;
} PcDisplayWord;

extern PcDisplayWord *D_801217B0;

void func_80014C98(void) {
    PcDisplayWord *slot;

    slot = D_801217B0++;
    slot->payload = 0;
    slot->command = 0xE7000000;
}
