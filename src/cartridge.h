#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef struct CARTRIDGE cartridge;

cartridge *init_cartridge(const char *rom_file);
void destroy_cartridge(cartridge *cart);
