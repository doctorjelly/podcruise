/* Implements specification $S/specs/func_8007B544.md */
#include "podcruise/types.h"

typedef struct Leaf {
    u8 unk000[0x100];
    s32 flags;
    u8 unk104[0xC];
    f32 level;
} Leaf;

typedef struct Node {
    s32 unk0[5];
    s32 count;
    struct Node **children;
} Node;

extern s32 func_80017DA4(Node *node);
extern s32 func_80017DAC(Node *node);
extern Leaf *func_80006D5C(Node *node, s32 kind);
extern void func_80006EB4(Leaf *leaf, f32 value);

void func_8007B544(Node *node, s32 clear, s32 set, f32 value) {
    Leaf *leaf;
    s32 i;

    if (node != 0) {
        if (func_80017DA4(node) & 0x4000) {
            if (func_80017DA4(node) == 0xD065) {
                leaf = func_80006D5C(node, 8);
                if (leaf != 0) {
                    leaf->flags = leaf->flags & ~clear;
                    leaf->flags = leaf->flags | set;
                    if (leaf->level <= 0.0f) {
                        func_80006EB4(leaf, value);
                    } else {
                        func_80006EB4(leaf, -value);
                    }
                }
                leaf = func_80006D5C(node, 9);
                if (leaf != 0) {
                    leaf->flags = leaf->flags & ~clear;
                    leaf->flags = leaf->flags | set;
                    if (leaf->level <= 0.0f) {
                        func_80006EB4(leaf, value);
                    } else {
                        func_80006EB4(leaf, -value);
                    }
                }
            }
            for (i = 0; i < func_80017DAC(node); i++) {
                func_8007B544(node->children[i], clear, set, value);
            }
        }
    }
}
