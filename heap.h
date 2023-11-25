#ifndef HEAP_H_
#define HEAP_H_

#include <cstddef>
#include <cstdint>
#include <map>

#define HEAP_SIZE 640000
#define CHUNK_LIST_MAX 256

uintptr_t *allocChunk(size_t size);
void freeChunk(uintptr_t* ptr);
void condenseChunks();

struct Chunk {
    size_t size;
    uintptr_t* start;
};

struct Chunk_List {
    size_t size;
    Chunk chunks[CHUNK_LIST_MAX];

    Chunk& operator[](int i) {
        return this->chunks[i];
    };
};

void deleteChunk(Chunk_List& list, size_t index);
void insertChunk(Chunk_List& list, uintptr_t *start, size_t size);
void combindChunks(Chunk_List& list, uintptr_t *start, size_t size);

void printHeap();

#endif
