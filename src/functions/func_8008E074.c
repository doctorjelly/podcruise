/* Recovered per $S/specs/func_8008E074.md (worker specification). */
#include "podcruise/types.h"

typedef struct Cmd8008E074 {
    u32 w0;
    u32 w1;
} Cmd8008E074;

typedef struct Buf8008E074 {
    s32 unk0;
    s32 unk4;
} Buf8008E074;

typedef struct State8008E074 {
    u8 pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    Buf8008E074 *unk28;
    u8 pad2C[4];
    s32 (*unk30)(s32, s32, void *);
    void *unk34;
    s32 unk38;
    u8 pad3C[8];
    s32 unk44;
} State8008E074;

Cmd8008E074 *func_8008E074(State8008E074 *state, s16 *countPtr, s32 count, s32 arg3,
                           Cmd8008E074 *cmd) {
    Cmd8008E074 *p;
    s32 length;
    s32 bytes;
    s32 address;
    s32 misalign;
    s32 dmem;
    s32 pad;
    s32 total;
    s32 limit;

    (void)arg3;
    p = cmd;
    if (count == 0) {
        return cmd;
    }

    {
        if ((u32)(state->unk38 + count) > (u32)state->unk20) {
            length = state->unk20 - state->unk38;
            if (state->unk24 != 0) {
                bytes = length * 2;
                if (length > 0) {
                    address = state->unk30(state->unk44, bytes, state->unk34);
                    misalign = address & 7;
                    total = bytes + misalign;
                    cmd[0].w1 = (u32)((total - (total & 7)) + 8) & 0xFFFF;
                    cmd[0].w0 = ((u32)*countPtr & 0xFFFF) | 0x08000000;
                    cmd[1].w1 = address - misalign;
                    cmd[1].w0 = 0x04000000;
                    p = cmd + 2;
                } else {
                    misalign = 0;
                }
                *countPtr = *countPtr + misalign;
                state->unk38 = state->unk1C;
                state->unk44 = state->unk28->unk0 + state->unk1C * 2;
                dmem = *countPtr;
                while (length < count) {
                    dmem += bytes;
                    count -= length;
                    if (state->unk24 != -1 && state->unk24 != 0) {
                        state->unk24 = state->unk24 - 1;
                    }
                    limit = state->unk20 - state->unk1C;
                    if ((u32)count < (u32)limit) {
                        length = count;
                    } else {
                        length = limit;
                    }
                    bytes = length * 2;
                    address = state->unk30(state->unk44, bytes, state->unk34);
                    misalign = address & 7;
                    total = bytes + misalign;
                    if ((dmem & 7) != 0) {
                        pad = 8 - (dmem & 7);
                    } else {
                        pad = 0;
                    }
                    p[0].w1 = (u32)((total - (total & 7)) + 8) & 0xFFFF;
                    p[0].w0 = ((u32)(dmem + pad) & 0xFFFF) | 0x08000000;
                    p[1].w0 = 0x04000000;
                    p[1].w1 = address - misalign;
                    p += 2;
                    if (misalign != 0 || pad != 0) {
                        p[0].w0 = ((u32)((dmem + misalign) + pad) & 0xFFFFFF) | 0x0A000000;
                        p[0].w1 = ((u32)dmem << 16) | ((u32)bytes & 0xFFFF);
                        p += 1;
                    }
                }
                state->unk38 = state->unk38 + count;
                state->unk44 = state->unk44 + count * 2;
                return p;
            }
        }
        bytes = count * 2;
        address = state->unk44 + bytes;
        length = (address - state->unk28->unk0) - state->unk28->unk4;
        if (length < 0) {
            length = 0;
        }
        if (bytes < length) {
            length = bytes;
        }
        if (length < bytes) {
            if (count > 0) {
                total = bytes - length;
                misalign = state->unk30(state->unk44, total, state->unk34);
                pad = misalign & 7;
                dmem = total + pad;
                cmd[0].w1 = (u32)((dmem - (dmem & 7)) + 8) & 0xFFFF;
                cmd[0].w0 = ((u32)*countPtr & 0xFFFF) | 0x08000000;
                cmd[1].w1 = misalign - pad;
                cmd[1].w0 = 0x04000000;
                p = cmd + 2;
            } else {
                pad = 0;
            }
            *countPtr = *countPtr + pad;
            state->unk38 = state->unk38 + count;
            state->unk44 = state->unk44 + bytes;
        } else {
            state->unk44 = address;
        }
        if (length != 0) {
            total = bytes - length;
            if (total < 0) {
                total = 0;
            }
            p[0].w0 = ((u32)(*countPtr + total) & 0xFFFFFF) | 0x02000000;
            p[0].w1 = length;
            p += 1;
        }
    }
    return p;
}
