/* Independently written from scratchpad specs/func_8007BB30.md (corrected boundary: entry 0x8007BB28). */

#include "podcruise/types.h"

typedef struct Record {
    u8 unk00[88];
} Record;

extern s32 D_8011CA58[];
extern Record D_8011CB20[];
extern void func_80018324(void *object, u32 flags);

Record *func_8007BB28(s32 key) {
    Record *record;
    s32 index;


    for (index = 0; index < 0x32 && D_8011CA58[index] != 0 && key != D_8011CA58[index]; index++) {
    }
    if (D_8011CA58[index] == 0) {
        record = &D_8011CB20[index];
        func_80018324(record, 0xD065);
        D_8011CA58[index] = key;
        return record;
    }
    return 0;
}
