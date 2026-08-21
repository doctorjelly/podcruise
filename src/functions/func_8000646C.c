/* Independently written from scratchpad spec specs/func_8000646C.md. */

#include "podcruise/types.h"
typedef struct Unk8000646C { char unk_000[0x114]; f32 unk_114; s32 unk_118; f32 *unk_11C; s32 *unk_120; void **unk_124; } Unk8000646C;
extern void func_80017E70(void *object, s32 selector, s32 value);
void func_8000646C(Unk8000646C *arg0) {
    void **list;
    void **entry;
    s32 value;
    if (arg0->unk_11C[arg0->unk_118 + 1] < arg0->unk_114) {
        value = arg0->unk_120[arg0->unk_118 + 1];
    } else {
        value = arg0->unk_120[arg0->unk_118];
    }
    list = arg0->unk_124;
    if ((list != 0) && (list[0] != 0)) {
        entry = list;
        do {
            func_80017E70(*entry, 2, value);
            entry++;
        } while (*entry != 0);
    }
}
