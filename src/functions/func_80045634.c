/* Independently written from specs/functions/func_80045634.md. */

#include "podcruise/types.h"

typedef struct Table {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    void **unk18;
} Table;

void func_80045634(Table *table, void *previous, void *replacement) {
    s32 index;

    if (table != 0 && previous != 0 && replacement != 0) {
        for (index = 0; index < table->unk14; index++) {
            if (table->unk18[index] == previous) {
                table->unk18[index] = replacement;
            }
        }
    }
}
