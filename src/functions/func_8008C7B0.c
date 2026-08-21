/* Implements the specification in specs/func_8008C7B0.md (bounded queue append). */
#include "podcruise/types.h"

typedef struct Queue {
    s32 **unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 *unk14;
} Queue;

typedef struct Device {
    u8 pad0[0x10];
    s16 unk10;
} Device;

extern Device *D_800A7BC0;

extern s32 func_8008B960(s32);
extern s32 func_8008CA80(void);
extern s32 func_8008CAA0(s32);
extern s32 func_8008D12C(void *);
extern s32 func_8008D274(Queue *);

s32 func_8008C7B0(Queue *queue, s32 value, s32 mode) {
    register s32 saved;
    register s32 result;

    saved = func_8008CA80();
    while (queue->unk8 >= queue->unk10) {
        if (mode == 1) {
            D_800A7BC0->unk10 = 8;
            func_8008D12C(&queue->unk4);
        } else {
            func_8008CAA0(saved);
            return -1;
        }
    }

    queue->unkC = (queue->unkC + queue->unk10 - 1) % queue->unk10;
    queue->unk14[queue->unkC] = value;
    queue->unk8 = queue->unk8 + 1;
    if (queue->unk0[0] != 0) {
        result = func_8008D274(queue);
        func_8008B960(result);
    }
    func_8008CAA0(saved);
    return 0;
}
