/* Implements specification $S/specs/func_80094028.md */
#include "podcruise/types.h"

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    s32 unk08;
    s32 unk0C;
    u64 time;
} Node;

extern Node *D_800A7FC0;
extern s32 func_8008CA80(void);
extern void func_8008CAA0(s32 saved);

u64 func_80094028(Node *node) {
    Node *entry;
    u64 time;
    s32 saved;

    saved = func_8008CA80();
    entry = D_800A7FC0->next;
    time = node->time;
    if (entry != D_800A7FC0 && time > entry->time) {
        do {
            time -= entry->time;
        } while ((entry = entry->next) != D_800A7FC0 && time > entry->time);
    }
    node->time = time;
    if (entry != D_800A7FC0) {
        entry->time -= time;
    }
    node->next = entry;
    node->prev = entry->prev;
    entry->prev->next = node;
    entry->prev = node;
    func_8008CAA0(saved);
    return time;
}
