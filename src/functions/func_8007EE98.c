/* Recovered from specification specs/func_8007EE98.md (worker scratchpad). */

#include "podcruise/types.h"

typedef struct {
    s16 unk_00[2];
    s16 unk_04[2];
    s16 unk_08[29];
    s16 unk_42[8];
    s16 unk_52;
} Entry;

typedef struct {
    s16 unk_00;
    s16 unk_02;
    s32 unk_04;
    s32 unk_08;
    Entry *unk_0C;
} Table;

typedef struct {
    Table *unk_00;
    s32 unk_04;
    f32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
    s32 unk_20[3];
    s32 unk_2C;
} Cursor;

void func_8007EE98(Cursor *cursor, s32 value) {
    Table *table;
    s32 group;
    s32 row;
    s32 column;

    group = value / 10;
    table = cursor->unk_00;
    if (group >= table->unk_04) {
        for (row = 0; row < table->unk_04; row++) {
            for (column = 0; column < 8; column++) {
                if (group == table->unk_0C[row].unk_42[column]) {
                    cursor->unk_2C = column;
                    cursor->unk_10 = row;
                    cursor->unk_08 = ((f32)value - (f32)group * 10.0f) / 10.0f;
                    cursor->unk_14 = table->unk_0C[row].unk_04[column & 1];
                    if (table->unk_00 != 1) {
                        cursor->unk_18 = table->unk_0C[cursor->unk_14].unk_04[(column >> 1) & 1];
                        cursor->unk_1C = table->unk_0C[cursor->unk_18].unk_04[(column >> 2) & 1];
                    }
                    row = 99999;
                    column = 99999;
                }
            }
        }
    } else {
        cursor->unk_10 = group;
        cursor->unk_14 = table->unk_0C[group].unk_04[0];
        if (table->unk_00 != 1) {
            cursor->unk_18 = table->unk_0C[cursor->unk_14].unk_04[0];
            cursor->unk_1C = table->unk_0C[cursor->unk_18].unk_04[0];
        }
        cursor->unk_2C = 0;
        cursor->unk_08 = ((f32)value - (f32)group * 10.0f) / 10.0f;
    }
}
