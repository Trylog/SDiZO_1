//
// Created by micha on 03.04.2023.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
#include "Array.h"

namespace std {
    Array::Array() {
        pointer = (int*) malloc(sizeof(int));
        pointer[0]=NULL;
        size = 0;
    }

    void Array::add(int index, int element) {
        if(index<0||index>=size+1)cout<<endl<<"### WRONG INDEX ###"<<endl; //wrong index
        int* tempPointer=NULL;
        tempPointer = (int*)malloc(sizeof(int) * (size + 2));
        if (tempPointer){
            for(auto i = 0; i<index;++i) tempPointer[i] = pointer[i];
            tempPointer[index] = element;
            for(auto i = index; i<size;++i) tempPointer[i+1] = pointer[i];
            tempPointer[size + 1] = NULL;
            free(pointer);
            pointer=tempPointer;
            size++;
        }else throw -2; //failed to reallocate array
    }

    void Array::remove(int index) {
        if(size>0 && index>=0 && index<=size){
            for(auto i = index; i<size;++i) pointer[i] = pointer[i+1];
            pointer = (int*) realloc(pointer, sizeof(int) * size);
            size--;
        } else cout<<endl<<"### WRONG INDEX ###"<<endl; //wrong index
    }

    void Array::display() {
        cout<< "Array: \n";
        for (auto i = 0; i<size; ++i) {
            cout<<pointer[i]<<" ";
        }
        cout<<endl;
    }

    void Array::buildFromFile(string filePath) {
        fstream input;
        input.open(filePath, ios::in);
        if(input.good()){
            input>>size;
            if(size){
                free(pointer);
                if(!(pointer = (int*)malloc(sizeof(int)*size+1))) throw -2; //failed to allocate memory
                for (auto i = 0; i < size; ++i){
                    if(!input.eof()){
                        int temp=0;
                        input>>temp;
                        //TODO check if temp is max 32-bit number
                        pointer[i]=temp;
                    }else throw -3; //wrong file length
                }
                pointer[size]=NULL;
            }
        }
    }

    bool Array::find(int element) {
        for (auto i = 0; i<size; ++i) {
            if(pointer[i]==element)return true;
        }
        return false;
    }

    void Array::creatRandom(int size) {
        if(size>0){
            free(pointer);
            if(!(pointer = (int*)malloc(sizeof(int)*size+1)))throw -2; // failed to allocate memory
            //std::default_random_engine generator;
            std::random_device rd;
            std::uniform_int_distribution<int> distribution(0,0xffffffff);
            //auto rando = bind(distribution, generator );
            for (auto i = 0; i < size; ++i) pointer[i]=distribution(rd); //filling array with random numbers in full int range
            pointer[size]=NULL;
        }else cout<<"Za maly rozmiar tablicy"<<endl;

    }

} // std