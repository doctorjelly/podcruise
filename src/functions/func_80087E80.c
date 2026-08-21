/* Specification: specs/func_80087E80.md (worker scratchpad) */
#include "podcruise/types.h"

typedef struct PcQueueNode {
    struct PcQueueNode *next;
} PcQueueNode;

typedef struct {
    /* 0x00 */ PcQueueNode *unk00;
    /* 0x04 */ PcQueueNode *unk04;
    /* 0x08 */ s32 count;
    /* 0x0C */ s32 first;
    /* 0x10 */ s32 total;
    /* 0x14 */ void **slots;
} PcQueue;

typedef struct {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ s16 unk10;
} PcActor;

extern PcActor *D_800A7BC0;
extern void *func_8008CA80(void);
extern void func_8008CAA0(void *);
extern void func_8008D12C(PcQueue *);
extern PcQueueNode *func_8008D274(PcQueueNode **);
extern void func_8008B960(PcQueueNode *);

s32 func_80087E80(PcQueue *queue, void **out, s32 blocking) {
    register void *saved;
    register PcQueueNode *node;

    saved = func_8008CA80();
    while (queue->count == 0) {
        if (blocking == 0) {
            func_8008CAA0(saved);
            return -1;
        }
        D_800A7BC0->unk10 = 8;
        func_8008D12C(queue);
    }
    if (out != 0) {
        *out = queue->slots[queue->first];
    }
    queue->first = (queue->first + 1) % queue->total;
    queue->count--;
    if (queue->unk04->next != 0) {
        node = func_8008D274(&queue->unk04);
        func_8008B960(node);
    }
    func_8008CAA0(saved);
    return 0;
}
