#include <string.h>
#include "rom_decoder.h"

int romdec_parse_header(RomHeader *rom_header, const void *buffer_vp) {
    const uint8_t *buffer = buffer_vp;

    memcpy(rom_header, buffer, sizeof(*rom_header));

    if (memcmp(rom_header->magic, "NES\x1A", 4) != 0) {
        return ROMDEC_ERR_BADMAGIC;
    }

    return 0;
}
