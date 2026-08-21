/* Independently written from $S/specs/func_8007B34C.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u8 unk00[0x20];
    /* 0x20 */ f32 unk20[4][4];
    /* 0x60 */ u8 unk60[0x4];
    /* 0x64 */ s32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ u8 unk70;
    /* 0x71 */ u8 unk71;
    /* 0x72 */ u8 unk72;
    /* 0x73 */ u8 unk73;
    /* 0x74 */ s32 unk74;
    /* 0x78 */ void *unk78;
} Entry;

extern s32 func_8000E8C4(void *arg0);
extern void func_800156DC(f32 output[4][4], f32 source[4][4]);
extern void func_800181BC(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern Entry *func_8003FBD4(s32 tag);

/* Note: when the size argument is below the threshold the original branches
   straight to the shared epilogue without setting the return register, so that
   path yields whatever the caller left there. That is a latent bug in the game
   rather than a recovery artefact, and reproducing the bytes requires the same
   fall-through — adding a return costs eight bytes. The host build therefore
   downgrades -Wreturn-type; see the Makefile. */
s32 func_8007B34C(f32 arg0[4][4], s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5, s32 arg6) {
    Entry *entry;

    if (arg4 >= 0x10) {
        entry = func_8003FBD4(0x546F7373);
        if (entry == 0) {
            return 0;
        }

        entry->unk6C = arg5;
        entry->unk68 = arg5;
        entry->unk64 = arg6;
        entry->unk70 = arg1;
        entry->unk71 = arg2;
        entry->unk72 = arg3;
        entry->unk73 = arg4;
        entry->unk74 = func_8000E8C4(entry->unk78);
        func_800156DC(entry->unk20, arg0);
        if (entry->unk78 != 0) {
            func_800181BC(entry->unk78, 2, 3, 0x10, 2);
        }
        return 1;
    }
}
