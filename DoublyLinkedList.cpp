//
// Created by micha on 27.03.2023.
//

#include <iostream>
#include <fstream>
#include "DoublyLinkedList.h"

namespace std {
    DoublyLinkedList::DoublyLinkedList(int element) {


    }

    void DoublyLinkedList::add(int index, int element) {
        if(element==0) {
            if(tailP==NULL) {   //no elements yet
                headP = new Node(element);
                tailP = headP;
            } else{
                Node* temp = new Node(element);
                tailP->prev=temp;
                temp->next=tailP;
                tailP=temp;
            }
        } else{
            Node* tempP=tailP;
            for(auto i = 1; i<=index;++i){
                if(tempP->next==NULL){
                    if(i+1==index) {//the last element
                        Node *temp = new Node(element);
                        headP->next = temp;
                        temp->prev = headP;
                        headP = temp;
                    } else throw -1;
                    break;
                }
                tempP=tempP->next;
            }
            Node* temp = new Node(element);
            temp->next=tempP;
            temp->prev=tempP->prev;
            tempP->prev->next=temp;
            tempP->prev=temp;
        }
    }

    void DoublyLinkedList::remove(int index) {

        Node* tempP=tailP;
        for (auto i = 1; i <= index; ++i) {
            if(tempP->next==NULL)throw -1;
            tempP=tempP->next;
        }
        if(tempP->next!=NULL)tempP->next->prev=tempP->prev;
        if(tempP->prev!=NULL)tempP->prev->next=tempP->next;
    }

    void DoublyLinkedList::display() {
        Node* tempP=tailP;
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
                        //TODO check if temp is max 32-bit number
                        if (tailP == NULL) {   //no elements yet
                            headP = new Node(tempIn);
                            tailP = headP;
                        } else {
                            Node *temp = new Node(tempIn);
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
    }

    bool DoublyLinkedList::find(int element) {
        Node* tempP=tailP;
        while(tempP->next!=NULL){
            if(tempP->data==element) return true;
            tempP=tempP->next;
        }
        return false;
    }
} // std