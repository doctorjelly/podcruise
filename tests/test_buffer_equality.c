#define _DEFAULT_SOURCE
#include <assert.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>

#include "podcruise/types.h"

extern s32 func_80096AD0(const u8 *, const u8 *, s32);

int main(void) {
    long page = sysconf(_SC_PAGESIZE);
    u8 *memory;
    u8 right[68];
    int count, offset, different;

    assert(page > 64);
    memory = mmap(0, (size_t)page * 2, PROT_READ | PROT_WRITE,
                  MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    assert(memory != MAP_FAILED);
    assert(mprotect(memory + page, (size_t)page, PROT_NONE) == 0);
    assert(func_80096AD0(memory + page, memory + page, 0) == 0);
    assert(func_80096AD0(memory + page, memory + page, -1) == 0);
    /* The final byte is immediately before an inaccessible page. Exercise
     * byte tails, aligned words, and every relative pointer alignment. */
    for (count = 1; count <= 64; count++) {
        u8 *left = memory + page - count;
        memset(left, 0x5A, (size_t)count);
        for (offset = 0; offset < 4; offset++) {
            memset(right, 0x5A, sizeof(right));
            assert(func_80096AD0(left, right + offset, count) == 0);
            for (different = 0; different < count; different++) {
                right[offset + different] ^= 1;
                assert(func_80096AD0(left, right + offset, count) == 1);
                right[offset + different] ^= 1;
            }
        }
    }
    assert(munmap(memory, (size_t)page * 2) == 0);
    return 0;
}
