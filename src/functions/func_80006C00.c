/* Independently written from specs/functions/recovered/func_80006C00.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x000 */ u8 pad000[0x100];
    /* 0x100 */ u32 unk100;
} Entry80006C00;

extern s32 D_8009A2A0;
extern Entry80006C00 *D_800AF4C0[];

extern void func_80006120(Entry80006C00 *);
extern void func_80006200(Entry80006C00 *);
extern void func_8000630C(Entry80006C00 *);
extern void func_8000646C(Entry80006C00 *);
extern void func_8000651C(Entry80006C00 *, s32);
extern void func_80006848(Entry80006C00 *);

void func_80006C00(void) {
    Entry80006C00 *entry;
    s32 count;
    s32 index;
    s32 type;

    count = D_8009A2A0;
    index = 0;
    if (count <= 0) {
        return;
    }
    do {
        entry = D_800AF4C0[index];
        if (entry != 0 && !(entry->unk100 & 0x80000000) &&
            (entry->unk100 & 0x10000000)) {
            func_80006848(entry);
            type = entry->unk100 & 0xF;
            switch (type) {
            case 2:
                func_8000646C(entry);
                break;
            case 11:
            case 12:
                if (type == 11) {
                    func_8000651C(entry, 0);
                } else {
                    func_8000651C(entry, 1);
                }
                break;
            case 8:
                func_8000630C(entry);
                break;
            case 9:
                func_80006120(entry);
                break;
            case 10:
                func_80006200(entry);
                break;
            }
            count = D_8009A2A0;
        }
        index++;
    } while (index < count);
}
