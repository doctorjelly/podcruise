/* Independently written from specs/functions/func_8001004C.md. */

#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
} BankEntry;

extern BankEntry D_8009B888[];

s32 func_8001004C(s32 encoded) {
    BankEntry *entry;

    entry = &D_8009B888[(encoded & 0xE000) >> 13];
    return entry->unk04 + (((encoded & 0x1FFC) >> 2) << entry->unk00);
}
