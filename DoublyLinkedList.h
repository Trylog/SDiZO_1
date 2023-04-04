//
// Created by micha on 27.03.2023.
//

#ifndef SDIZO_1_DOUBLYLINKEDLIST_H
#define SDIZO_1_DOUBLYLINKEDLIST_H

#include <string>

namespace std {

    class DoublyLinkedList {
    private:
        class Node{
        public:
            Node(int data){
                this->data=data;
                this->prev=NULL;
                this->next=NULL;
            }
            int data;
            struct Node* next;
            struct Node* prev;
        };
        Node* headP;
        Node* tailP;
    public:
        DoublyLinkedList(int element);
        void buildFromFile(string filePath);
        void remove(int index);
        void add(int index, int element);
        bool find(int element);
        void creatRandom(int size);
        void display();
    };

} // std

#endif //SDIZO_1_DOUBLYLINKEDLIST_H
