#include "romfile.h"
#include <stdio.h>

struct romfile {
    FILE *file;
    size_t size;
    off_t offset;
};

struct romfile *romfile_permalloc() {
    return permalloc(sizeof(struct romfile));
}

int romfile_init(struct romfile *rom, const void *args) {
    const char *path = args;
    rom->file = fopen(path, "r");
    if (rom->file == NULL) {
        return ROMFILE_ERR_BADFILE;
    }

    fseek(rom->file, 0, SEEK_END);
    rom->size = ftell(rom->file);
    fseek(rom->file, 0, SEEK_SET);

    rom->offset = ftell(rom->file);
    return 0;
}

int romfile_fetch_raw(struct romfile *rom, void *dest, off_t offset, size_t length) {
    if (offset + length >= rom->size) {
        return ROMFILE_ERR_OUTOFBOUNDS;
    }

    if (fseek(rom->file, offset, SEEK_SET) != 0) {
        return ROMFILE_ERR_BADADDR;
    }

    rom->offset = ftell(rom->file);
    if (fread(dest, length, 1, rom->file) != length) {
        return ROMFILE_ERR_READCONTENTS;
    }

    return 0;
}

int romfile_cleanup(struct romfile *rom) {
    return fclose(rom->file);
}
