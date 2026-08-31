/* Independently written from specs/functions/func_8001004C.md. */

#include "podcruise/types.h"

typedef struct {
    s32 unk00;
    s32 unk04;
} BankEntry;

extern BankEntry D_8009B888[];

s32 func_8001004C(s32 encoded) {
    BankEntry *entry;
    s32 result;

    entry = &D_8009B888[(encoded & 0xE000) >> 13];
    result = entry->unk04 + (((encoded & 0x1FFC) >> 2) << entry->unk00);
    /* Dead after result is computed; preserves IDO's original register choice. */
    entry = &D_8009B888[(encoded & 0xE000) >> 13];
    return result;
}
