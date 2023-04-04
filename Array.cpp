//
// Created by micha on 03.04.2023.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "Array.h"

namespace std {
    Array::Array() {
        pointer = (int*) malloc(sizeof(int));
        pointer[0]=NULL;
    }

    void Array::add(int index, int element) {
        auto arrayLen=0;
        for(;pointer[arrayLen] != NULL; ++arrayLen);
        if(index<0||index>=arrayLen+1)throw -1; //wrong index
        int* tempPointer=NULL;
        if (tempPointer = (int*)malloc(sizeof(int) * (arrayLen + 2))){
            for(auto i = 0; i<index;++i) tempPointer[i] = pointer[i];
            tempPointer[index] = element;
            for(auto i = index; i<=arrayLen;++i) tempPointer[i+1] = pointer[i];
            free(pointer);
            pointer=tempPointer;
        }else throw -2; //failed to reallocate array
    }

    void Array::remove(int index) {
        auto arrayLen=0;
        for(;pointer[arrayLen] != NULL; ++arrayLen);
        if(arrayLen>0 && index>=0 && index<=arrayLen){
            for(auto i = index; i<arrayLen;++i) pointer[i] = pointer[i+1];
            pointer = (int*) realloc(pointer, sizeof(int) * arrayLen);
        } else throw -1; //wrong index
    }

    void Array::display() {
        cout<< "Array: \n";
        for (auto i = 0; pointer[i]!=NULL; ++i) {
            cout<<pointer[i]<<" ";
        }
        cout<<endl;
    }

    void Array::buildFromFile(string filePath) {
        fstream input;
        input.open(filePath, ios::in);
        if(input.good()){
            int arrayLen = 0;
            input>>arrayLen;
            if(arrayLen){
                free(pointer);
                if(!(pointer = (int*)malloc(sizeof(int)*arrayLen))) throw -2; //failed to allocate memory
                for (auto i = 0; i < arrayLen; ++i){
                    if(!input.eof()){
                        int temp=0;
                        input>>temp;
                        //TODO check if temp is max 32-bit number
                        pointer[i]=temp;
                    }else throw -3; //wrong file length
                }
            }
        }
    }

    bool Array::find(int element) {
        for (auto i = 0; pointer[i]!=NULL; ++i) {
            if(pointer[i]==element)return true;
        }
        return false;
    }

    void Array::creatRandom(int size) {
        free(pointer);
        if(!(pointer = (int*)malloc(sizeof(int)*size)))throw -2; // failed to allocate memory
        srand(time(NULL)); //initializing random seed using current system time
        for (auto i = 0; i < size; ++i) pointer[i]=rand()%0xffffffff; //filling array with random numbers in full 32-bit range
    }

} // std