/* Independently written from scratchpad spec specs/func_80095990.md. */

#include "podcruise/types.h"

typedef struct PodRecord {
    /* 0x00 */ struct PodRecord *unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ struct PodRecord **unk08;
    /* 0x0C */ struct PodRecord *unk0C;
    /* 0x10 */ u16 unk10;
} PodRecord;

extern PodRecord *D_800A7BBC;
extern PodRecord *D_800A7BC0;

extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32 arg0);
extern void func_8008CAC0(PodRecord **head, PodRecord *target);
extern void func_8008D284(void);

void func_80095990(PodRecord *arg0) {
    register s32 saved;
    register PodRecord *node;
    register PodRecord *next;

    saved = func_8008CA80();
    if (arg0 == 0) {
        arg0 = D_800A7BC0;
    } else if (arg0->unk10 != 1) {
        func_8008CAC0(arg0->unk08, arg0);
    }
    if (D_800A7BBC == arg0) {
        D_800A7BBC = D_800A7BBC->unk0C;
    } else {
        node = D_800A7BBC;
        while (node->unk04 != -1) {
            next = node->unk0C;
            if (next == arg0) {
                node->unk0C = arg0->unk0C;
                break;
            }
            node = next;
        }
    }
    if (arg0 == D_800A7BC0) {
        func_8008D284();
    }
    func_8008CAA0(saved);
}
