/* Independently written from specs/functions/recovered/medium_leaf_tranche.md. */

#include "podcruise/types.h"

struct PcEntity;

extern void func_80005BB8(struct PcEntity *entity);

extern u32 D_800D9DC4;
extern u32 D_800D9DC8;
extern u32 D_800D9DD0;

struct PcEntity **func_80030964(s32 *stream) {
    struct PcEntity *entity;
    struct PcEntity **list;
    struct PcEntity **cursor;
    s32 *word;
    u32 lowest;
    s32 count;

    word = stream;
    lowest = 0xFFFFFFFFU;
    while (*word != -1) {
        word++;
    }
    word++;
    if (*word == 0x44617461) {
        count = word[1];
        word += 2;
        while (count > 0) {
            count--;
            word++;
        }
    }
    if (*word == 0x416E696D) {
        cursor = (struct PcEntity **)(word + 1);
        list = cursor;
        entity = *cursor;
        while (entity != 0) {
            func_80005BB8(entity);
            if ((u32)(unsigned long)*cursor < lowest) {
                lowest = (u32)(unsigned long)*cursor;
            }
            cursor++;
            entity = *cursor;
        }
    } else {
        list = 0;
    }

    if (lowest == 0xFFFFFFFFU) {
        D_800D9DD0 = 0;
    } else {
        D_800D9DD0 = D_800D9DC4 - lowest;
        D_800D9DC8 -= D_800D9DD0;
    }
    return list;
}
