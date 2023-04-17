//
// Created by micha on 27.03.2023.
//

#include <iostream>
#include <fstream>
#include <random>
#include <functional>
#include "DoublyLinkedList.h"

namespace std {
    DoublyLinkedList::DoublyLinkedList(int element) {


    }

    void DoublyLinkedList::add(int index, int element) {
        if(element==0) {
            if(tailP==NULL) {   //no elements yet
                headP = static_cast<node *>(malloc(sizeof(struct node)));
                headP->data = element;
                tailP = headP;
            } else{
                node* temp = static_cast<node *>(malloc(sizeof(struct node)));
                temp->data=element;
                tailP->prev=temp;
                temp->next=tailP;
                tailP=temp;
            }
        } else{
            node* tempP=tailP;
            for(auto i = 1; i<=index;++i){
                if(tempP->next==NULL){
                    if(i+1==index) {//the last element
                        node* temp = static_cast<node *>(malloc(sizeof(struct node)));
                        temp->data=element;
                        headP->next = temp;
                        temp->prev = headP;
                        headP = temp;
                    } else throw -1;
                    break;
                }
                tempP=tempP->next;
            }
            node* temp = static_cast<node *>(malloc(sizeof(struct node)));
            temp->data=element;
            temp->next=tempP;
            temp->prev=tempP->prev;
            tempP->prev->next=temp;
            tempP->prev=temp;
        }
    }

    void DoublyLinkedList::remove(int index) {

        node* tempP=tailP;
        for (auto i = 1; i <= index; ++i) {
            if(tempP->next==NULL)throw -1;
            tempP=tempP->next;
        }
        if(tempP->next!=NULL)tempP->next->prev=tempP->prev;
        if(tempP->prev!=NULL)tempP->prev->next=tempP->next;
    }

    void DoublyLinkedList::display() {
        node* tempP=tailP;
        while(tempP->next!=NULL){
            cout<<tempP->data<<" ";
            tempP=tempP->next;
        }
    }

    void DoublyLinkedList::buildFromFile(string filePath) {
        fstream input;
        input.open(filePath, ios::in);
        if(input.good()) {
            int arrayLen = 0;
            input >> arrayLen;
            if (arrayLen) {
                tailP=NULL;
                headP=NULL;
                int tempIn;
                for (auto i = 0; i < arrayLen; ++i) {
                    if(!input.eof()) {
                        input >> tempIn;
                        if (tailP == NULL) {   //no elements yet
                            headP = static_cast<node *>(malloc(sizeof(struct node)));
                            headP->data=tempIn;
                            tailP = headP;
                        } else {
                            node *temp = static_cast<node *>(malloc(sizeof(struct node)));
                            temp->data=tempIn;
                            headP->next = temp;
                            temp->prev = headP;
                            headP = temp;
                        }
                    } else throw -3; //wrong file length
                }
            }
        }
    }

    void DoublyLinkedList::creatRandom(int size) {
        //TODO createRandom - List, change function name
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0,0xffffffff);
        auto rando = bind(distribution, generator );
        for (auto i = 0; i < size; ++i) add(i, rando()); //filling list with random numbers in full int range
    }

    bool DoublyLinkedList::find(int element) {
        node* tempP=tailP;
        while(tempP->next!=NULL){
            if(tempP->data==element) return true;
            tempP=tempP->next;
        }
        return false;
    }
} // std