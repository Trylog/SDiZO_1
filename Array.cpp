//
// Created by micha on 03.04.2023.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <random>
#include <functional>
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
        tempPointer = (int*)malloc(sizeof(int) * (arrayLen + 2));
        if (tempPointer){
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
        if(size>0){
            free(pointer);
            if(!(pointer = (int*)malloc(sizeof(int)*size+1)))throw -2; // failed to allocate memory
            std::default_random_engine generator;
            std::uniform_int_distribution<int> distribution(0,0xffffffff);
            auto rando = bind(distribution, generator );
            for (auto i = 0; i < size; ++i) pointer[i]=rando(); //filling array with random numbers in full int range
            pointer[size]=NULL;
        }else cout<<"Za maly rozmiar tablicy"<<endl;

    }

} // std