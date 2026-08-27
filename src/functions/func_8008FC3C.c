/* Independently written from scratchpad spec specs/func_8008FC3C.md. */

#include "podcruise/types.h"

typedef struct Node8008FC3C {
    struct Node8008FC3C *next;
    struct Node8008FC3C *prev;
    s32 count;
    u8 data[0x10];
} Node8008FC3C;

typedef struct {
    Node8008FC3C *pending;
    s32 unk4;
    Node8008FC3C list;
} Head8008FC3C;

extern void func_80088020(Node8008FC3C *node);
extern void func_80088050(Node8008FC3C *node, Node8008FC3C *anchor);
extern s32 func_80090500(s32 arg0);
extern void func_80096710(void *dst, void *src, s32 len);

void func_8008FC3C(Head8008FC3C *arg0, void *arg1, s32 arg2) {
    Node8008FC3C *node;
    Node8008FC3C *p;
    Node8008FC3C *t;
    s32 flag;
    s32 prev;

    flag = 0;
    prev = func_80090500(1);
    node = arg0->pending;
    if (node == 0) {
        func_80090500(prev);
        return;
    }
    func_80088020(node);
    func_80096710(arg1, node->data, 0x10);
    if (arg2 == 0x7FFFFFFF) {
        flag = -1;
    }
    for (p = &arg0->list; p != 0; p = t) {
        t = p->next;
        if (t == 0) {
            if (flag != 0) {
                node->count = 0;
            } else {
                node->count = arg2;
            }
            func_80088050(node, p);
            break;
        }
        if (arg2 < t->count) {
            node->count = arg2;
            t->count = t->count - arg2;
            func_80088050(node, p);
            break;
        }
        arg2 -= t->count;
    }
    func_80090500(prev);
}
