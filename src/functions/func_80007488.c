/* Independently written from specs/functions/recovered/func_80007488.md. */

#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s16 unk04;
} Task80007488;

typedef struct {
    /* 0x00 */ u8 pad00[0x30];
    /* 0x30 */ u32 *unk30;
    /* 0x34 */ s32 unk34;
} Pool80007488;

extern void func_80006FDC(void);
extern void func_8002E5D4(void);
extern u32 func_80088360(u32 address);
extern u32 func_800883E0(void);
extern u32 *func_80088538(u32 *commands, s32 *countOut, void *state, s32 samples);
extern void func_80088AD0(void);

extern s32 D_8009A2CC;
extern Pool80007488 *D_8009A310;
extern u32 *D_800AFA60[];
extern s32 D_800AFE8C;
extern s32 D_800AFE90;

void func_80007488(Task80007488 *task) {
    Pool80007488 *pool;
    u32 physical;
    u32 available;
    s32 count;
    u32 *end;

    func_80006FDC();
    physical = func_80088360(task->unk00);
    available = func_800883E0();
    task->unk04 = ((D_800AFE90 - (available >> 2)) + 0x60) & 0xFFF0;
    if (task->unk04 < D_800AFE8C) {
        task->unk04 = D_800AFE8C;
    }
    end = func_80088538(D_800AFA60[D_8009A2CC], &count, (void *)(long)physical, task->unk04);
    if (count >= 3001) {
        for (;;) {
        }
    }
    pool = D_8009A310;
    pool->unk30 = D_800AFA60[D_8009A2CC];
    pool->unk34 = (s32)((((long)end - (long)D_800AFA60[D_8009A2CC]) >> 3) << 3);
    func_80088AD0();
    func_8002E5D4();
}
