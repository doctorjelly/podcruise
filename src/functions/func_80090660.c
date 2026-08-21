/* Recovered from specification $S/specs/func_80090660.md */
#include "podcruise/types.h"

extern unsigned long long D_8014C510;
extern u32 D_8014C518;

extern void *func_8008CA80(void);
extern u32 func_8008C550(void);
extern void func_8008CAA0(void *);

unsigned long long func_80090660(void) {
    f64 pad;
    void *context;
    u32 now;
    unsigned long long elapsed;
    unsigned long long base;

    context = func_8008CA80();
    now = func_8008C550();
    elapsed = now - D_8014C518;
    base = D_8014C510;
    func_8008CAA0(context);
    (void)&pad;
    return elapsed + base;
}
