//
// Created by micha on 27.03.2023.
//

#ifndef SDIZO_1_DOUBLYLINKEDLIST_H
#define SDIZO_1_DOUBLYLINKEDLIST_H

#include <string>

namespace std {

    class DoublyLinkedList {
    private:
        struct node{
        public:
            int data;
            struct node* next;
            struct node* prev;
        };
    public:
        struct node* headP;
        struct node* tailP;
        DoublyLinkedList();
        void buildFromFile(string filePath);
        void remove(int element);
        void add(int index, int element);
        bool find(int element);
        void creatRandom(int size);
        void display();
    };

} // std

#endif //SDIZO_1_DOUBLYLINKEDLIST_H
