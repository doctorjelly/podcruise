/* Independently written from specs/functions/func_80075490.md. */

#include "podcruise/types.h"

typedef struct Node80075490 {
    s32 unk00[5];
    s32 count;
    s32 **items;
} Node80075490;

extern s32 D_800A66C4;
extern s32 D_8011C8B0[];
extern s32 D_8011C8D8;
extern s32 D_8011C8DC;

extern s32 func_80017DA4(Node80075490 *node);
extern s32 func_80017DAC(Node80075490 *node);

void func_80075490(Node80075490 *node) {
    volatile Node80075490 *view;
    s32 index;
    s32 i;
    s32 *entry;

    if (D_8011C8DC < 5 && node != 0) {
        if (func_80017DA4(node) == 0x3064) {
            view = node;
            index = D_800A66C4;
            for (i = 0; i < view->count; i++) {
                entry = node->items[i];
                if (entry[0] != 0) {
                    index = (index + 1) % D_8011C8D8;
                    entry[0] = D_8011C8B0[index];
                    D_8011C8DC = D_8011C8DC + 1;
                }
            }
            D_800A66C4 = index;
        } else if (func_80017DA4(node) & 0x4000) {
            for (i = 0; i < func_80017DAC(node); i++) {
                func_80075490((Node80075490 *)node->items[i]);
            }
        }
    }
}
