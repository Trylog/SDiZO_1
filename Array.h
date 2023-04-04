//
// Created by micha on 03.04.2023.
//

#ifndef SDIZO_1_ARRAY_H
#define SDIZO_1_ARRAY_H

#include <string>

namespace std {

    class Array {
    private:
        int* pointer;
    public:
        Array();
        void buildFromFile(string filePath);
        void remove(int index);
        void add(int index, int element);
        bool find(int element);
        void creatRandom(int size);
        void display();

    };

} // std

#endif //SDIZO_1_ARRAY_H
