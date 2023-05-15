//
// Created by micha on 11.04.2023.
//

#include <iostream>
#include <fstream>
#include <random>
#include "BinaryHeap.h"

namespace std {
    BinaryHeap::BinaryHeap() {
        if(!(heap = (int*)malloc(sizeof(int)*100000)))throw -2; //trying to allocate array
        size=0;
    }
    inline void BinaryHeap::swap(int* a, int* b)
    {
        int temp = *b;
        *b = *a;
        *a = temp;
    }
    void BinaryHeap::heapify(int i) {
        int largest;
        //int top = heap[i];
        while(true){
            auto left = i*2+1;
            auto right = i*2+2;
            if(left < size && heap[left] > heap[i]){
                largest = left;
            }else largest = i;
            if(right < size && heap[right] > heap[largest]) largest = right;
            if(largest != i){swap(&heap[i], &heap[largest]);
            } else break;
            i = largest;
            /*
            if(right<size && heap[right]>heap[left]){
                largest=right;
            } else largest=left;
            if(top>=heap[largest])break;
            heap[i]=heap[largest];
            i=largest;*/
        }
        //heap[i]=top;
    }
    void BinaryHeap::add(int element) {
        heap[size]=element;
        for(int i = size; heap[(i-1)/2]<heap[i]&&i!=0;i=(i-1)/2) {
            swap(&heap[i], &heap[(i-1)/2]);
        }
        size++;
    }

    void BinaryHeap::remove(int index) {
        if(index<size&&index>=0){
            swap(&heap[index], &heap[size-1]);
            size--;
            for (int i = size / 2 - 1; i >= 0; i--)heapify(i);
        } else {cout<<"### WRONG INDEX ###"<<endl; return;}


    }
    void BinaryHeap::displayH(int node, string printed, bool lR) { //lR - left(1) or right(0);
        if(node<size){
            cout<<printed;
            if(lR){
                cout<<"R--- ";
                printed+="   ";
            } else{
                cout<<"L--- ";
                printed+="|  ";
            }
            cout<<heap[node]<<endl;
            displayH(node*2+1, printed, false);
            displayH(node*2+2, printed, true);
        }
    }

    void BinaryHeap::display() {

        for(auto i = 0; i < size; ++i)cout<<heap[i]<<" "; //displaying array form
        cout<<endl<<endl;
        displayH(0, "", true);

    }

    bool BinaryHeap::find(int element) {
        for(auto i = 0; i < size; ++i)if(heap[i]==element)return true;
        return false;
    }

    void BinaryHeap::buildFromFile(string filePath) {
        fstream input;
        input.open(filePath, ios::in);
        if(input.good()) {
            int tempSize=0;
            input >> tempSize;
            if (tempSize) {
                int tempIn;
                for (auto i = 0; i < tempSize; ++i) {
                    if (!input.eof()) {
                        input >> tempIn;
                        add(tempIn);
                    } else throw -3; //wrong file length
                }
            }
        }
    }

    void BinaryHeap::creatRandom(int sizeI) {
        std::uniform_int_distribution<int> distribution(0,0xffffffff);
        std::random_device rd;
        for (auto i = 0; i < sizeI; ++i) add(distribution(rd)); //filling list with random numbers in full int range
        for(int i = sizeI/2-1;i>=0;--i)heapify(i);
    }
} // std