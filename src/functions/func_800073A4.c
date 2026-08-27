/* Recovered from specification specs/func_800073A4.md */
#include "podcruise/types.h"

typedef struct {
    /* 0x00 */ void *unk00;
    /* 0x04 */ s16 unk04;
} PcDisplayList;

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ PcDisplayList *slots[22];
    /* 0x5C */ s16 index;
} PcFrameSet;

extern PcFrameSet D_800AFA60;
extern void *D_8009A2C8;
extern s32 D_8009A2C0;
extern volatile s32 D_8009A2CC;
extern s32 D_800AFE88;
extern s32 D_800B05B0;

extern void func_80007488(PcDisplayList *list);
extern void func_80007728(void *arg0);
extern void func_80008090(void);
extern void func_80008530(void);
extern void func_8002E644(void);
extern void func_8002E6E0(void);
extern void func_800882B0(void *start, s32 length);

void func_800073A4(void) {
    PcDisplayList *list;
    s32 count;

    D_800B05B0++;
    if (D_8009A2C0 == 0) {
        func_80008090();
        func_80007728(D_8009A2C8);
        D_8009A2C8 = 0;
        list = D_800AFA60.slots[D_800AFA60.index];
        func_8002E644();
        func_80007488(list);
        func_8002E6E0();
        func_800882B0(list->unk00, list->unk04 * 4);
        D_8009A2CC = 0;
        D_800AFA60.index = (D_800AFA60.index + 1) % 3;
        D_800AFE88 = D_800AFE88 + 1;
        func_80008530();
    }
}
