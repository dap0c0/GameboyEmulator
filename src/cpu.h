#pragma once
#include <stdint.h>

#define FLAGS_BIT_OFF_Z 7           // Zero flag
#define FLAGS_BIT_OFF_N 6           // Subtraction flag (BCD)
#define FLAGS_BIT_OFF_H 5           // Half Carry flag (BCD)
#define FLAGS_BIT_OFF_C 4           // Carry flag

typedef struct CPU cpu;

cpu *init_cpu(void);
void destroy_cpu(cpu *c);
