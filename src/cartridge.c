#include "cartridge.h"
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define ROM_BANK_SIZE             1 << 15
#define ROM_BANKS_OFF             0x148
#define ROM_BANKS_MIN_SHIFT       0x00
#define ROM_BANKS_MAX_SHIFT       0x08
#define BUFFER_SIZE               1 << 9

// NOTE: If it's realized that the cartridge struct
// doesn't hold any other info beyond the buffer,
// then the cartridge will simply be the buffer
// and not a wrapper class.
typedef struct CARTRIDGE {
    uint8_t *buffer;
} cartridge;

cartridge *init_cartridge(const char *rom_file) {
    cartridge *cart;
    int fd;

    if ((cart = malloc(sizeof(cartridge))) != NULL) {
        if ((fd = open(rom_file, O_RDONLY)) != -1) {
            char buffer[BUFFER_SIZE] = {0};
            uint8_t cart_size_shift;
            uint8_t cart_size;

            // Allocate enough size for the cartridge
            // and copy all filedata into its buffer
            if (read(fd, &buffer, BUFFER_SIZE) > ROM_BANKS_OFF) {
                cart_size_shift = buffer[ROM_BANKS_OFF];
                cart_size = ROM_BANK_SIZE * (1 << cart_size_shift);
                if (ROM_BANKS_MIN_SHIFT <= cart_size_shift && cart_size_shift <= ROM_BANKS_MAX_SHIFT &&
                    (cart->buffer = calloc(cart_size, sizeof(uint8_t))) != NULL) {
                    lseek(fd, 0, SEEK_SET);
                    assert(read(fd, cart->buffer, cart_size) == cart_size); // TODO: remove assertion
                } else {
                    destroy_cartridge(cart);
                }
            }
        }
        close(fd);
    }
    return cart;
}
void destroy_cartridge(cartridge *cart) {
    if (cart != NULL) {
        free(cart->buffer);
        free(cart);
    }
}
