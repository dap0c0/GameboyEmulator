#include <stdlib.h>
#include "memory.h"

uint8_t *init_memory(void) {
    return (uint8_t *)calloc(1 << 16, sizeof(uint8_t));
}

void destroy_memory(uint8_t *memory) {
    free(memory);
}
