#include <iostream>
#include <conio.h>
#include "Array.h"
#include "DoublyLinkedList.h"
#include "RedBlackTree.h"
#include "BinaryHeap.h"
#include <chrono>

using namespace std;

void menu();

int main() {
    //menu();
    /*Array jeden;
    //jeden.creatRandom(0);
    jeden.display();
    /*try {
        jeden.add(5,12);
    } catch (int e) {
        cout<<e;
    }

    jeden.remove(7);
    jeden.display();
    if (jeden.find(12))cout<<"jest"<<endl;*/
    /*
    DoublyLinkedList lista;
    lista.add(0, 1);
    lista.add(1, 2);
    lista.add(2, 3);
    lista.add(3, 4);
    lista.remove(2);
    lista.display();
    cout<<endl<<lista.find(3)<<endl;*//*
    RedBlackTree tree(2);
    tree.add(3);
    tree.add(2);
    tree.add(0);
    tree.add(4);
    tree.add(-5);
    /*tree.add(1);
    tree.add(5);
    tree.add(4);
    tree.add(6);*//*
    tree.display();
    tree.remove(-5);
    tree.creatRandom(100);
    tree.display();*//*
    RedBlackTree tree(0);
    tree.creatRandom(100);
    tree.display();*/
    /*
    auto a=RedBlackTree::buildFromFile("bst2.txt");
    a.display();
    a.remove(15);
    a.display();*/
    menu();
    /*BinaryHeap a;
    a.add(0);
    a.add(1);
    a.add(2);
    a.remove(1);
    a.display();*/
    /*DoublyLinkedList a;
    a.buildFromFile("tab1.txt");
    a.display();
    a.remove(2);
    a.display();*/
    //menu();

    //RedBlackTree a;
    //a.buildFromFile("bst2.txt");
    //auto t1 = std::chrono::high_resolution_clock::now();
    /*for (int i = 0; i <400000 ; ++i) {
        a.add(i);
    }*/
    //auto t2 = std::chrono::high_resolution_clock::now();
    //a.remove(15);
   // a.remove(0);
    //a.buildFromFile("bst2.txt");

    //a.display();

    //auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    //a.display();
    //cout<<time_span.count();

    //DoublyLinkedList a;
    //a.add(1,12);
    //a.display();
    //a.remove(0);
    //a.display();

    //BinaryHeap a;
    /*a.add(10);
    a.display();
    a.remove(0);
    a.add(15);
    a.add(232);
    a.display();
    a.buildFromFile("heap2.txt");
    a.display();
    a.remove(8);
    a.display();
    a.remove(5);
    a.display();
    a.remove(6);
    a.remove(4);
    a.display();
    a.remove(4);
    a.display();
    a.remove(3);
    a.display();
    a.remove(3);
    a.display();
    a.remove(4);
    a.display();
    a.remove(2);
    a.display();
    a.remove(0);
    a.display();
*/

    system("pause");
    return 0;
}

inline void displayMainMenu(int currentState){
    system("cls");
    switch (currentState) {
        case 0:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"#1. Array #\n"
                <<"2. Doubly Linked List \n"
                <<"3. Binary Heap \n"
                <<"4. Red-Black Tree \n";
            break;
        case 1:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"1. Array \n"
                <<"#2. Doubly Linked List #\n"
                <<"3. Binary Heap \n"
                <<"4. Red-Black Tree \n";
            break;
        case 2:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"1. Array \n"
                <<"2. Doubly Linked List \n"
                <<"#3. Binary Heap #\n"
                <<"4. Red-Black Tree \n";
            break;
        case 3:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"1. Array \n"
                <<"2. Doubly Linked List \n"
                <<"3. Binary Heap \n"
                <<"#4. Red-Black Tree #\n";
            break;
    }
}
inline void displaySubmenu(int currentState) {
    system("cls");
    switch (currentState) {
        case 0:
            cout<<"Select an Operation on Structure: \n"
                <<"#1. Build from File #\n"
                <<"2. Delete \n"
                <<"3. Add \n"
                <<"4. Find \n"
                <<"5. Create Random \n"
                <<"6. Display \n";
            break;
        case 1:
            cout<<"Select an Operation on Structure: \n"
                <<"1. Build from File \n"
                <<"#2. Delete #\n"
                <<"3. Add \n"
                <<"4. Find \n"
                <<"5. Create Random \n"
                <<"6. Display \n";
            break;
        case 2:
            cout<<"Select an Operation on Structure: \n"
                <<"1. Build from File \n"
                <<"2. Delete \n"
                <<"#3. Add #\n"
                <<"4. Find \n"
                <<"5. Create Random \n"
                <<"6. Display \n";
            break;
        case 3:
            cout<<"Select an Operation on Structure: \n"
                <<"1. Build from File \n"
                <<"2. Delete \n"
                <<"3. Add \n"
                <<"#4. Find #\n"
                <<"5. Create Random \n"
                <<"6. Display \n";
            break;
        case 4:
            cout<<"Select an Operation on Structure: \n"
                <<"1. Build from File \n"
                <<"2. Delete \n"
                <<"3. Add \n"
                <<"4. Find \n"
                <<"#5. Create Random #\n"
                <<"6. Display \n";
            break;
        case 5:
            cout<<"Select an Operation on Structure: \n"
                <<"1. Build from File \n"
                <<"2. Delete \n"
                <<"3. Add \n"
                <<"4. Find \n"
                <<"5. Create Random \n"
                <<"#6. Display #\n";
            break;
    }
}


#define ARROW_UP 72
#define ARROW_DOWN 80
#define ENTER 13

void menu(){

    int currentState0=0;
    int input=0;
    displayMainMenu(currentState0);
    while (true){
        input=_getch();
        if(input==224) {
            input = _getch();
            if (input == ARROW_UP) {
                //arrow "up"
                if (currentState0 > 0)currentState0--;
                displayMainMenu(currentState0);
            } else if (input == ARROW_DOWN) {
                //arrow "down"
                if (currentState0 < 3)currentState0++;
                displayMainMenu(currentState0);
            }
        }else if(input==ENTER){
            //when "enter" pressed
            Array a;
            DoublyLinkedList b;
            BinaryHeap c;
            RedBlackTree d;
            int currentState1=0;
            displaySubmenu(currentState1);
            while(true){
                input =0;
                input=_getch();
                if(input==224) {
                    input = _getch();
                    if (input == ARROW_UP) {
                        //arrow "up"
                        if (currentState1 > 0)currentState1--;
                        displaySubmenu(currentState1);
                    } else if (input == ARROW_DOWN) {
                        //arrow "down"
                        if (currentState1 < 5)currentState1++;
                        displaySubmenu(currentState1);
                    }
                }else if (input==ENTER){
                    if(currentState0==0){//array
                        string temp;
                        int temp1, temp2;
                        switch (currentState1) {
                            case 0://form file
                                cout<<"Name the file:"<<endl;
                                temp="";
                                cin>>temp;
                                cout<<endl;
                                a.buildFromFile(temp);
                                a.display();
                                break;
                            case 1://delete
                                cout<<"Index:"<<endl;
                                temp1=0;
                                cin>>temp1;
                                a.remove(temp1);
                                a.display();
                                break;
                            case 2://add
                                temp1=0;
                                temp2=0;
                                cout<<"Value:"<<endl;
                                cin>>temp1;
                                cout<<endl<<"index"<<endl;
                                cin>>temp2;
                                a.add(temp2, temp1);
                                a.display();
                                break;
                            case 3://find
                                cout<<"Value"<<endl;
                                temp1=0;
                                cin>>temp1;
                                if(a.find(temp1)){
                                    cout<<endl<<"exists"<<endl;
                                } else cout<<endl<<"does not exists"<<endl;
                                break;
                            case 4://random
                                cout<<"Size of array"<<endl;
                                temp1=0;
                                cin>>temp1;
                                a.creatRandom(temp1);
                                a.display();
                                break;
                            case 5: //display
                                a.display();
                                break;
                        }
                    } else if(currentState0==1){//DoublyLinkedList
                        string temp;
                        int temp1, temp2;
                        switch (currentState1) {
                            case 0://form file
                                cout<<"Name the file:"<<endl;
                                temp="";
                                cin>>temp;
                                cout<<endl;
                                b.buildFromFile(temp);
                                b.display();
                                break;
                            case 1://delete
                                cout<<"Value:"<<endl;
                                temp1=0;
                                cin>>temp1;
                                b.remove(temp1);
                                b.display();
                                break;
                            case 2://add
                                temp1=0;
                                temp2=0;
                                cout<<"Value:"<<endl;
                                cin>>temp1;
                                cout<<endl<<"index"<<endl;
                                cin>>temp2;
                                b.add(temp2, temp1);
                                b.display();
                                break;
                            case 3://find
                                cout<<"Value"<<endl;
                                temp1=0;
                                cin>>temp1;
                                if(b.find(temp1)){
                                    cout<<endl<<"exists"<<endl;
                                } else cout<<endl<<"does not exists"<<endl;
                                break;
                            case 4://random
                                cout<<"Size of List"<<endl;
                                temp1=0;
                                cin>>temp1;
                                b.creatRandom(temp1);
                                b.display();
                                break;
                            case 5: //display
                                b.display();
                                break;
                        }
                    } else if(currentState0==2){
                        string temp;
                        int temp1, temp2;
                        switch (currentState1) {
                            case 0://form file
                                cout<<"Name the file:"<<endl;
                                temp="";
                                cin>>temp;
                                cout<<endl;
                                c.buildFromFile(temp);
                                c.display();
                                break;
                            case 1://delete
                                cout<<"Index:"<<endl;
                                temp1=0;
                                cin>>temp1;
                                c.remove(temp1);
                                c.display();
                                break;
                            case 2://add
                                temp1=0;
                                cout<<"Value:"<<endl;
                                cin>>temp1;
                                c.add(temp1);
                                c.display();
                                break;
                            case 3://find
                                cout<<"Value"<<endl;
                                temp1=0;
                                cin>>temp1;
                                if(c.find(temp1)){
                                    cout<<endl<<"exists"<<endl;
                                } else cout<<endl<<"does not exists"<<endl;
                                break;
                            case 4://random
                                cout<<"Size of array"<<endl;
                                temp1=0;
                                cin>>temp1;
                                c.creatRandom(temp1);
                                c.display();
                                break;
                            case 5: //display
                                c.display();
                                break;
                        }
                    } else if(currentState0==3){//RED_BLACK_TREE
                        string temp;
                        int temp1, temp2;
                        switch (currentState1) {
                            case 0://form file
                                cout<<"Name the file:"<<endl;
                                temp="";
                                cin>>temp;
                                cout<<endl;
                                d.buildFromFile(temp);
                                d.display();
                                break;
                            case 1://delete
                                cout<<"Index:"<<endl;
                                temp1=0;
                                cin>>temp1;
                                d.remove(temp1);
                                d.display();
                                break;
                            case 2://add
                                temp1=0;
                                temp2=0;
                                cout<<"Value:"<<endl;
                                cin>>temp1;
                                d.add(temp1);
                                d.display();
                                break;
                            case 3://find
                                cout<<"Value"<<endl;
                                temp1=0;
                                cin>>temp1;
                                if(d.find(temp1)){
                                    cout<<endl<<"exists"<<endl;
                                } else cout<<endl<<"does not exists"<<endl;
                                break;
                            case 4://random
                                cout<<"Size of the tree"<<endl;
                                temp1=0;
                                cin>>temp1;
                                d.creatRandom(temp1);
                                d.display();
                                break;
                            case 5: //display
                                d.display();
                                break;
                        }
                    }

                }
            }
        }
    }
}
