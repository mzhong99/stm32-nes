#ifndef __ROM_DECODER_H__
#define __ROM_DECODER_H__

#include <stdint.h>
#include "romfile.h"
#include "permalloc.h"

#define ROMDEC_ERR_BASE         (0x1000)
#define ROMDEC_ERR_BADMAGIC     (ROMDEC_ERR_BASE + 0x1)

struct romheader_flag6 {
    uint8_t mirroring: 1;
    uint8_t persistent_prg_rom: 1;
    uint8_t trainer: 1;
    uint8_t four_screen_vram: 1;
    uint8_t mapper_low: 4;
};

struct romheader_flag7 {
    uint8_t vs_unisystem: 1;
    uint8_t playchoice_10: 1;
    uint8_t nes2: 2;
    uint8_t mapper_high : 4;
};

struct romheader {
    uint8_t magic[4];
    uint8_t prg_rom_nseg;
    uint8_t chr_rom_nseg;
    struct romheader_flag6 flag6;
    struct romheader_flag7 flag7;
    uint8_t unused_nyi[8];
};
typedef struct _RomHeader RomHeader;

int romheader_init(struct romheader *header, struct romfile *rom);

struct romdecoder {
    struct romheader header;
    void *trainer;
    void *prg_rom;
    void *chr_rom;
};



#endif
