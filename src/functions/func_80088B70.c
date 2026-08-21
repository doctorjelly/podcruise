/* Independently written from scratchpad spec specs/func_80088B70.md. */

#include "podcruise/types.h"

/*
 * Packaging note.  The translation unit that holds this body was built one
 * optimisation level above the rest of the ROM.  At that level the compiler
 * allocates registers across every function of a unit at once, so a file-local
 * routine whose call sites are all visible receives its arguments in whatever
 * registers the allocator chose and is free to destroy callee-saved registers
 * that its caller reloads afterwards.  Both call sites of this routine spill
 * and reload one such register around the call, which is what made the body
 * look hand-written.  Reproducing the convention needs the routine to stay
 * file-local and to have a caller in the same unit; func_80088B70_call_context
 * below is a minimal stand-in for the real caller, func_80088BFC.
 */

typedef struct Block {
    /* 0x00 */ struct Block *unk00;
    /* 0x04 */ struct Block *unk04;
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ void *unk10;
} Block;

typedef struct Arena {
    /* 0x00 */ Block *unk00;
    /* 0x04 */ Block *unk04;
    /* 0x08 */ Block *unk08;
} Arena;

extern s32 func_80090500(s32 mask);
extern void func_80088020(Block *block);
extern void func_80088050(Block *block, Arena *anchor);

static void func_80088B70(Arena *arena, void *owner) {
    Block *block;
    Block *next;
    s32 saved;

    saved = func_80090500(1);
    block = arena->unk08;
    while (block != 0) {
        next = block->unk00;
        if (block->unk10 == owner) {
            if (next != 0) {
                next->unk08 += block->unk08;
            }
            func_80088020(block);
            func_80088050(block, arena);
        }
        block = next;
    }
    func_80090500(saved);
}

void func_80088B70_call_context(Arena *arena, void *owner);

void func_80088B70_call_context(Arena *arena, void *owner) {
    func_80088B70(arena, owner);
    func_80088B70(arena, (void *)0);
}
