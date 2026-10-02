/* Specification: specs/functions/recovered/func_800129B8.md. */
#include "podcruise/text_metrics.h"

s32 func_800129B8(u8 *text, s32 fontIndex) {
    return func_800129E4(text, D_800D6940[fontIndex]);
}
