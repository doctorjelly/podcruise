/* Recovered from specification $S/specs/func_80090660.md */
#include "podcruise/types.h"

extern unsigned long long D_8014C510;
extern u32 D_8014C518;

extern s32 func_8008CA80(void);
extern u32 func_8008C550(void);
extern void func_8008CAA0(s32);

unsigned long long func_80090660(void) {
    u32 now;
    u32 elapsed;
    unsigned long long base;
    register s32 context;

    context = func_8008CA80();
    now = func_8008C550();
    elapsed = now - D_8014C518;
    base = D_8014C510;
    func_8008CAA0(context);
    return (unsigned long long)elapsed + base;
}
