/* Independently written from specs/functions/recovered/medium_leaf_tranche.md. */

#include "podcruise/types.h"

typedef struct Item {
    char unk_00[0x30];
} Item;

typedef struct Session {
    char unk_000[0xEC];
    s32 unk_0EC[6];
    char unk_104[0x6C0];
    Item unk_7C4[6];
    char unk_8D4[0x2A8];
    f32 unk_B7C[6];
} Session;

extern void func_80008B14(s32 id, s32 channel, f32 volume, f32 pan, s32 flag);
extern void func_80083190(Item *item, void *work);

void func_80045004(Session *session) {
    s32 i;
    u8 work[0x54];

    func_80008B14(0x93, 6, 0.25f, 0.8f, 1);
    for (i = 0; i < 6; i++) {
        if (session->unk_0EC[i] != 0) {
            func_80083190(&session->unk_7C4[i], work);
        }
    }
    func_80008B14(0x7E, 7, 0.25f, 0.3f, 1);
    func_80008B14(0x78, 7, 0.25f, 0.5f, 1);
}
