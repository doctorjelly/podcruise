#ifndef PODCRUISE_TEXT_METRICS_H
#define PODCRUISE_TEXT_METRICS_H

#include "podcruise/types.h"

struct PcFont;

extern struct PcFont *D_800D6940[];

s32 func_800129B8(u8 *text, s32 fontIndex);
s32 func_800129E4(u8 *text, struct PcFont *font);

#endif
