//
// Created by micha on 11.04.2023.
//

#ifndef SDIZO_1_BINARYHEAP_H
#define SDIZO_1_BINARYHEAP_H

#include <string>

namespace std {

    class BinaryHeap {

    private:

        int* heap;
        int size;

        static inline void swap(int* a,int* b);
        void heapify(int i);
        void displayH(int node, string printed, bool rL);

    public:
        BinaryHeap();
        void buildFromFile(string filePath);
        void remove(int index);
        void add(int element);
        bool find(int element);
        void creatRandom(int sizeI);
        void display();
    };


} // std

#endif //SDIZO_1_BINARYHEAP_H
