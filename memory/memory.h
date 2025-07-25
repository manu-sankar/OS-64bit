#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>

void* allocate(size_t size);
void deallocate(void* ptr);
void init_memory();

#endif // MEMORY_H
