//
// Created by micha on 11.04.2023.
//

#include <iostream>
#include <fstream>
#include <random>
#include <functional>
#include "BinaryHeap.h"

namespace std {
    BinaryHeap::BinaryHeap() {
        if(!(heap = (int*)malloc(sizeof(int)*1000)))throw -2; //trying to allocate array
    }
    inline void BinaryHeap::swap(int* a, int* b)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }
    void BinaryHeap::heapify(int i) {
        int largest;
        int top = heap[i];
        while(i<size/2){
            auto left = i*2+1;
            auto right = i*2+2;
            if(right<size && heap[right]>heap[left]){
                largest=right;
            } else largest=left;
            if(top>=heap[largest])break;
            heap[i]=heap[largest];
            i=largest;
        }
        heap[i]=top;
    }
    void BinaryHeap::add(int element) {
        heap[size]=element;
        for(int i = size; heap[((i+1)/2)-1]>heap[i]&&i!=0;i=((i+1)/2)-1) swap(&heap[i],&heap[((i+1)/2)-1]);
        size++;
    }

    void BinaryHeap::remove(int index) {
        swap(&heap[index], &heap[size-1]);
        heapify(index);
        size--;
    }

    void BinaryHeap::display() {

        for(auto i = 0; i < size; ++i)cout<<heap[i]<<" "; //displaying array form
    }

    bool BinaryHeap::find(int element) {
        for(auto i = 0; i < size; ++i)if(heap[i]==element)return true;
        return false;
    }

    void BinaryHeap::buildFromFile(string filePath) {
        fstream input;
        input.open(filePath, ios::in);
        if(input.good()) {
            input >> size;
            if (size) {
                int tempIn;
                for (auto i = 0; i < size; ++i) {
                    if (!input.eof()) {
                        input >> heap[i];
                    } else throw -3; //wrong file length
                }
            }
        }
        heapify(0);
    }

    void BinaryHeap::creatRandom(int size) {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0,0xffffffff);
        auto rando = bind(distribution, generator );
        for (auto i = 0; i < size; ++i) heap[i] = rando(); //filling list with random numbers in full int range
        for(int i = size/2-1;i>=0;--i)heapify(i);
    }
} // std