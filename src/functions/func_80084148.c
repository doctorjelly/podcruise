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
    s32 n3;
    s32 n2;
    s32 n1;
    s32 index0;
    s32 index1;
    s32 index2;
    s32 done;
    u8 *bytes;
    f32 *outPointLocal;
    f32 *extraLocal;
    u8 pad3[20];
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
                n1 = bytes[1] * 4;
                n2 = bytes[2] * 4;
                n3 = bytes[3] * 4;
                index0 = bytes[5];
                index1 = bytes[6];
                index2 = bytes[7];
                index0 *= 4;
                index1 *= 4;
                index2 *= 4;
                func_80083EFC(&vertices[n1], &vertices[n2], &vertices[n3], transform, best, reference, outPointLocal, extraLocal);
                func_80083EFC(&vertices[index0], &vertices[index1], &vertices[index2], transform, best, reference, outPointLocal, extraLocal);
                break;
            case 0x05000000:
                n1 = bytes[1] * 4;
                n2 = bytes[2] * 4;
                n3 = bytes[3] * 4;
                func_80083EFC(&vertices[n1], &vertices[n2],
                              &vertices[n3], transform, best,
                              reference, outPointLocal, extraLocal);
                break;
            }
            commands++;
        } while (done == 0);
    }
}
