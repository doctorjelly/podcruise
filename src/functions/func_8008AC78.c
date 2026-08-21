/* Independently written from specs/functions/recovered/boundary_state_tranche.md. */
#include "podcruise/types.h"

void func_8008AC78(quotient, remainder, value, divisor)
u64 *quotient;
u64 *remainder;
u64 value;
s16 divisor;
{
    *quotient = value / divisor;
    *remainder = value % divisor;
}
