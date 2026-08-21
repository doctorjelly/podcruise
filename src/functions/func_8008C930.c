/* Recovered per specs/func_8008C930.md (worker specification). */
#include "podcruise/types.h"

typedef struct Object {
    s32 unk_00;
    s32 unk_04;
    struct Object **unk_08;
    s32 unk_0C;
    u16 unk_10;
} Object;

typedef struct Queue {
    Object **unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    void **unk_14;
} Queue;

extern Object *D_800A7BC0;

extern void func_8008B960(Object *);
extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32);
extern void func_8008D12C(void *);
extern Object *func_8008D274(Queue *);

s32 func_8008C930(Queue *queue, void *value, s32 mode) {
    register s32 token;
    register s32 slot;
    register Object *object;

    token = func_8008CA80();
    while (queue->unk_08 >= queue->unk_10) {
        if (mode == 1) {
            D_800A7BC0->unk_10 = 8;
            func_8008D12C(&queue->unk_04);
        } else {
            func_8008CAA0(token);
            return -1;
        }
    }

    slot = (queue->unk_0C + queue->unk_08) % queue->unk_10;
    queue->unk_14[slot] = value;
    queue->unk_08++;
    if (queue->unk_00[0] != 0) {
        object = func_8008D274(queue);
        func_8008B960(object);
    }
    func_8008CAA0(token);
    return 0;
}
