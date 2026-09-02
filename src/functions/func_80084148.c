/* Independently written from the specification in scratchpad specs/func_80084148.md. */
#include "podcruise/types.h"

typedef struct {
    /* 0x0 */ u32 word0;
    /* 0x4 */ s16 *word1;
} DisplayCommand;

extern void func_80083EFC(s16 *pointA, s16 *pointB, s16 *pointC, void *object,
                          f32 *best, void *arg5, f32 *hitOut, f32 *normalOut);

void func_80084148(DisplayCommand *commands, f32 (*transform)[4], f32 *best, f32 *reference,
                   f32 *outPoint, f32 *extra) {
    s16 *vertices;
    register s32 index0;
    register s32 index1;
    register s32 index2;
    register u8 *bytes;
    register f32 *outPointLocal;
    register f32 *extraLocal;
    s32 done;
    u8 pad3[32];
    DisplayCommand command;

    (void)pad3;
    done = 0;
    if (commands != 0) {
        bytes = (u8 *)&command;
        outPointLocal = outPoint;
        extraLocal = extra;
        do {
            command.word0 = commands->word0; command.word1 = commands->word1;
            switch (commands->word0 & 0xFF000000) {
            case 0xDF000000:
                done = 1;
                break;
            case 0x01000000:
                vertices = commands->word1;
                break;
            case 0x03000000:
                break;
            case 0x06000000:
                index0 = bytes[5] * 4;
                index1 = bytes[6] * 4;
                index2 = bytes[7] * 4;
                func_80083EFC(&vertices[bytes[1] * 4], &vertices[bytes[2] * 4],
                              &vertices[bytes[3] * 4], transform, best,
                              reference, outPointLocal, extraLocal);
                func_80083EFC(&vertices[index0], &vertices[index1],
                              &vertices[index2], transform, best, reference,
                              outPointLocal, extraLocal);
                break;
            case 0x05000000:
                func_80083EFC(&vertices[bytes[1] * 4], &vertices[bytes[2] * 4],
                              &vertices[bytes[3] * 4], transform, best,
                              reference, outPointLocal, extraLocal);
                break;
            }
            commands++;
        } while (done == 0);
    }
}
