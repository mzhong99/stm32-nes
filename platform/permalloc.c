#include "permalloc.h"

void *permalloc(size_t size) {
    static uint8_t _buffer[PERMALLOC_SIZE];
    static uint8_t *_top = _buffer;

    if (size == PERMALLOC_RESET) {
        _top = _buffer;
        return NULL;
    }

    if (_top + size >= _buffer + PERMALLOC_SIZE) {
        return NULL;
    }

    void *payload = _top;
    _top += size;
    return payload;
}
