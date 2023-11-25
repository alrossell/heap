#include "./heap.h"
#include <cstdint>
#include <iostream>

uintptr_t heap[HEAP_SIZE] = { 0 };

Chunk_List allocatedChunks = { 0 };

Chunk_List freeChunks = {
    .size = 1,
    .chunks = {
        [0] = {
            .size = sizeof(heap),
            .start = heap,
        }
    },
};

uintptr_t* allocChunk(size_t size) {
    for(int i = 0; i < freeChunks.size; i++) {
        if(freeChunks[i].size >= size) {
            uintptr_t* start = freeChunks[i].start;

            if(freeChunks[i].size == size) {
                deleteChunk(freeChunks, i);
            } else {
                freeChunks[i].size -= size;
                freeChunks[i].start -= (uintptr_t) size;
            }

            insertChunk(allocatedChunks, start, size);
            return start;
        }    
    } 

    // combineChunks(allocatedChunks);
    
    return NULL;
}

void combindChunks(Chunk_List &list, uintptr_t *start, size_t size) {

    for(int i = 0; i < (list.size-1); i++) {

    }
}

void freeChunk(uintptr_t *ptr) {
    for(int i = 0; i < allocatedChunks.size; i++) {
        if(ptr == allocatedChunks[i].start) {
            insertChunk(freeChunks, allocatedChunks[i].start, allocatedChunks[i].size);
            deleteChunk(allocatedChunks, i);
            return;
        }
    }
}

void insertChunk(Chunk_List &list, uintptr_t *start, size_t size) {
    
    list[list.size] = Chunk {
        .size = size,
        .start = start,
    };

    list.size++;
}

void deleteChunk(Chunk_List &list, size_t index) {
    list[index] = list[list.size-1];
    list.size--;
}

void printHeap() {
    std::cout << "----- Free Stack Start -----\n"  << std::endl;
    
    for(int i = 0; i < freeChunks.size; i++) {
        std::cout << "Chunk size: " << freeChunks[i].size << std::endl;
        std::cout << "Chunk start: " << freeChunks[i].start << std::endl;
    }
    
    std::cout << "\n----- Free Stack End -----" << std::endl;
    
    std::cout << "----- Allocated Stack Start -----\n" << std::endl;

    for(int i = 0; i < allocatedChunks.size; i++) {
        std::cout << "Chunk size: " << allocatedChunks[i].size << std::endl;
        std::cout << "Chunk start: " << allocatedChunks[i].start << std::endl;
    }

    std::cout << "\n----- Allocated Stack End -----" << std::endl;
}
