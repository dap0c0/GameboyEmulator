#pragma once
#include <stdint.h>

#define WORD_LENGTH                 8
#define ADDRESS_SPACE               16

#define ROM_BANK_00_OFF             0x0000
#define ROM_BANK_01_NN_OFF          0x4000
#define VRAM_OFF                    0x8000
#define EXTERNAL_RAM_OFF            0xA000
#define WRAM_BANK_0_OFF             0xC000
#define WRAM_BANK_1_N_OFF           0xD000
#define ECHO_RAM_OFF                0xE000
#define OAM_OFF                     0xFE00
#define NOT_USABLE_OFF              0xFEA0
#define IO_REGISTERS_OFF            0xFF00
#define HRAM_OFF                    0xFF80
#define INT_ENABLE_REGISTER_OFF     0xFFFF

uint8_t *init_memory(void);
void destroy_memory(uint8_t *memory);
