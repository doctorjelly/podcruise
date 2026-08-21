/* Recovery evidence: specs/functions/recovered/medium_system_tranche.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u32 word0;
    /* 0x4 */ s16 *word1;
} DisplayCommand;

extern void func_80083EFC(void *, void *, void *, void *, u32, u32, u32, u32);

void func_80084148(DisplayCommand *commands, void *arg1, u32 arg2, u32 arg3,
                   u32 arg4, u32 arg5) {
    s16 *vertices;
    s32 index0;
    s32 index1;
    s32 index2;
    DisplayCommand command;
    u8 *bytes;
    s32 done;

    done = 0;
    if (commands != 0) {
        bytes = (u8 *)&command;
        do {
            command = *commands;
            switch (commands->word0 & 0xFF000000) {
            case 0x01000000:
                vertices = commands->word1;
                break;
            case 0x03000000:
                break;
            case 0x05000000:
                func_80083EFC(&vertices[bytes[1] * 4], &vertices[bytes[2] * 4],
                              &vertices[bytes[3] * 4], arg1, arg2, arg3, arg4,
                              arg5);
                break;
            case 0x06000000:
                index0 = bytes[5] * 4;
                index1 = bytes[6] * 4;
                index2 = bytes[7] * 4;
                func_80083EFC(&vertices[bytes[1] * 4], &vertices[bytes[2] * 4],
                              &vertices[bytes[3] * 4], arg1, arg2, arg3, arg4,
                              arg5);
                func_80083EFC(&vertices[index0], &vertices[index1],
                              &vertices[index2], arg1, arg2, arg3, arg4, arg5);
                break;
            case 0xDF000000:
                done = 1;
                break;
            }
            commands++;
        } while (done == 0);
    }
}
