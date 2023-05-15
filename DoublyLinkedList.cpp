//
// Created by micha on 27.03.2023.
//

#include <iostream>
#include <fstream>
#include <random>
#include "DoublyLinkedList.h"

namespace std {
    DoublyLinkedList::DoublyLinkedList() {
        tailP=NULL;
        headP=NULL;

    }

    void DoublyLinkedList::add(int index, int element) {
        if(index==0) {
            if(tailP==NULL) {   //no elements yet
                headP = static_cast<node *>(malloc(sizeof(struct node)));
                headP->data = element;
                headP->next= nullptr;
                headP->prev= nullptr;
                tailP = headP;
            } else{
                node* temp = static_cast<node *>(malloc(sizeof(struct node)));
                temp->data=element;
                tailP->prev=temp;
                temp->next=tailP;
                temp->prev= nullptr;
                tailP=temp;
            }
        } else{
            node* tempP=tailP;
            //if(tempP== nullptr){cout<<"### LIST IS EMPTY - INDEX OUT OF BOUNDS ###"<<endl;return;}
            for(auto i = 1; i<=index;++i){
                if(tempP->next==NULL){
                    if(i==index) {//the last element
                        node* temp = static_cast<node *>(malloc(sizeof(struct node)));
                        temp->data=element;
                        headP->next = temp;
                        temp->prev = headP;
                        temp->next= nullptr;
                        headP = temp;
                    } else cout<<endl<<"### INDEX OUT OF BOUNDS ###"<<endl;
                    return;
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

    void DoublyLinkedList::remove(int element) {
        if(tailP!= nullptr) {
            node *tempP = tailP;
            /*for (auto i = 0; i < index; ++i) {
                if(tempP->next==NULL)throw -1;
                tempP=tempP->next;
            }*/
            int a = 0;
            while (tempP->data != element) {
                a++;
                if (tempP->next == nullptr){cout<<endl<<"### THIS ELEMENT DOES NOT EXIST ###"<<endl;return;};
                tempP = tempP->next;
            }

            if (tempP->next != nullptr) {
                tempP->next->prev = tempP->prev;
            }else headP = tempP->prev;
            if (tempP->prev != nullptr){
                tempP->prev->next = tempP->next;
            }else tailP = tempP->next;

            free(tempP);
        }else cout<<endl<<"### LIST EMPTY ###"<<endl;
    }

    void DoublyLinkedList::display() {
        node* tempP=tailP;
        cout<<"From tail to head:"<<endl;
        while(tempP!=NULL){
            cout<<tempP->data<<" ";
            tempP=tempP->next;
        }
        cout<<endl<<endl<<"From head to tail:"<<endl;
        tempP=headP;
        while(tempP!=NULL){
            cout<<tempP->data<<" ";
            tempP=tempP->prev;
        }
        cout<<endl;
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
                        add(i, tempIn);
                    } else throw -3; //wrong file length
                }
            }
        }
    }

    void DoublyLinkedList::creatRandom(int size) {
        std::uniform_int_distribution<int> distribution(0,0xffffffff);
        std::random_device rd;
        for (auto i = 0; i < size; ++i) add(i, distribution(rd)); //filling list with random numbers in full int range
    }

    bool DoublyLinkedList::find(int element) {
        node* tempP=tailP;
        while(tempP!=NULL){
            if(tempP->data==element) return true;
            tempP=tempP->next;
        }
        return false;
    }
} // std