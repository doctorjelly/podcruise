/* Independently written from specs/functions/leaf_state.md. */

#include "podcruise/leaf_state.h"

extern u8 D_8009B874[];

void func_80011778(u8 first, u8 second, u8 third, u8 fourth) {
    D_8009B874[0] = first;
    D_8009B874[1] = second;
    D_8009B874[2] = third;
    D_8009B874[3] = fourth;
}
