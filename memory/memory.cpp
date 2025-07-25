#include "memory.h"

struct MemoryBlock {
    size_t size;
    bool free;
    MemoryBlock* next;
};

MemoryBlock* memoryList = nullptr; // Head of the memory list

void init_memory() {
    memoryList = (MemoryBlock*)0x100000; // Start of the memory
    memoryList->size = 0x1000000; // 16 MB
    memoryList->free = true;
    memoryList->next = nullptr;
}

void* allocate(size_t size) {
    MemoryBlock* current = memoryList;
    while (current) {
        if (current->free && current->size >= size) {
            current->free = false; // Mark as allocated
            return (void*)(current + 1); // Return pointer to memory after the block
        }
        current = current->next;
    }
    return nullptr; // No suitable block found
}

void deallocate(void* ptr) {
    MemoryBlock* block = (MemoryBlock*)ptr - 1; // Get the block
    block->free = true; // Mark as free
}
