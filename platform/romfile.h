#ifndef __ROMFILE_H__
#define __ROMFILE_H__

#include <stddef.h>
#include "permalloc.h"

#define ROMFILE_ERR_BASE            (0x2000)
#define ROMFILE_ERR_BADFILE         (ROMFILE_ERR_BASE + 0x1)
#define ROMFILE_ERR_BADADDR         (ROMFILE_ERR_BASE + 0x2)
#define ROMFILE_ERR_OUTOFBOUNDS     (ROMFILE_ERR_BASE + 0x2)
#define ROMFILE_ERR_READCONTENTS    (ROMFILE_ERR_BASE + 0x3)

// Eventually, consider implementing some form of memory management caching
struct romfile *romfile_permalloc();
int romfile_init(struct romfile *rom, const void *args);
int romfile_fetch_raw(struct romfile *rom, void *dest, off_t offset, size_t length);
int romfile_cleanup(struct romfile *rom);

#endif
