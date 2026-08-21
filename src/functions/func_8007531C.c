/* Implements specification $S/specs/func_8007531C.md */
#include "podcruise/types.h"

typedef struct Entry {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Entry;

typedef struct Child {
    Entry *unk0;
} Child;

typedef struct Node {
    s32 unk0[5];
    s32 count;
    Child **children;
} Node;

extern s32 D_8011C8D8;
extern Entry *D_8011C8B0[10];

extern s32 func_80017DA4(Node *node);
extern s32 func_80017DAC(Node *node);

void func_8007531C(Node *node) {
    s32 i;
    s32 j;
    s32 found;
    Entry *entry;
    Child *child;
    volatile Node *view;
    s32 value;

    if ((u32)D_8011C8D8 < 10U) {
        if (node != 0) {
            if (func_80017DA4(node) == 0x3064) {
                view = node;
                for (i = 0; i < view->count; i++) {
                    if ((u32)D_8011C8D8 >= 10U) {
                        return;
                    }
                    child = node->children[i];
                    entry = child->unk0;
                    if (entry != 0) {
                        value = entry->unk8;
                        if (value != 0) {
                            found = 0;
                            for (j = 0; j < D_8011C8D8; j++) {
                                if (value == D_8011C8B0[j]->unk8) {
                                    found = 1;
                                }
                                if (found) {
                                    break;
                                }
                            }
                            if (!found) {
                                D_8011C8B0[D_8011C8D8] = entry;
                                D_8011C8D8 = D_8011C8D8 + 1;
                            }
                        }
                    }
                }
            } else if (func_80017DA4(node) & 0x4000) {
                for (i = 0; i < func_80017DAC(node); i++) {
                    func_8007531C((Node *)node->children[i]);
                }
            }
        }
    }
}
