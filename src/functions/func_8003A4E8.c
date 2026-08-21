/* Independently written from the specification for func_8003A4E8. */
#include "podcruise/types.h"

typedef struct {
    u8 pad[0x40];
    s16 value;
    u8 rest[0x12];
} Record8003A4E8;

typedef struct {
    u8 pad[0xC];
    Record8003A4E8 *records;
} Object8003A4E8;

s16 func_8003A4E8(Object8003A4E8 *object, s32 index) {
    return object->records[index].value;
}
