#include <cstdint>

#include <iostream>
#include <list>

#include "./heap.h"

int main() {
    std::cout << "hello world \n";
    uintptr_t* ptr1 = allocChunk(64);
    uintptr_t* ptr2 = allocChunk(64);
    uintptr_t* ptr3 = allocChunk(128);
    uintptr_t* ptr4 = allocChunk(1024);
    uintptr_t* ptr5 = allocChunk(1024);
    
    freeChunk(ptr2);
    freeChunk(ptr4);

    printHeap();
}
