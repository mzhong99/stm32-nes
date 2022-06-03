#ifndef __PERMALLOC_H__
#define __PERMALLOC_H__

#include <stddef.h>
#include <stdint.h>

#define PERMALLOC_SIZE  (2048)
#define PERMALLOC_RESET (0)
void *permalloc(size_t size);

#endif
