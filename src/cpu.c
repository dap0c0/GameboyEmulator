#include <stdlib.h>
#include "cpu.h"

// NOTE: it may be necesarry to align the boundaries
// of the alpha registers to allow for 16-bit addressing.
typedef struct CPU {
    uint8_t A, F;       // Accumulator & flags
    uint8_t B, C;       // General purpose registers
    uint8_t D, E;       //
    uint8_t H, L;       //
    uint16_t SP;        // Stack pointer
    uint16_t PC;        // Program counter/Pointer
} cpu;

cpu *init_cpu(void) {
    return (cpu *)calloc(1, sizeof(cpu));
}

void destroy_cpu(cpu *c) {
    free(c);
}
