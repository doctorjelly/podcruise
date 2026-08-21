/* Implements specification specs/func_80064A48.md (recovered behavior). */
#include "podcruise/types.h"

extern void func_80017C18(void *arg0, void *arg1);
extern void func_80015288(void *arg0, void *arg1);

typedef struct {
    u8 unk00[0x30];
    void **unk30;
} Func80064A48Owner;

void func_80064A48(void *arg0, Func80064A48Owner *arg1, s32 arg2) {
    u8 bufferB[20];
    u8 bufferA[48];

    func_80017C18(arg1->unk30[arg2], bufferA);
    func_80015288(arg0, bufferB);
}
