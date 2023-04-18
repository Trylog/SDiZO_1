#include <iostream>
#include <conio.h>
#include "Array.h"
#include "DoublyLinkedList.h"
#include "RedBlackTree.h"


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
    cout<<endl<<lista.find(3)<<endl;*/
    RedBlackTree tree(0);
    tree.add(1);
    tree.display();

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
                <<"4. Binary Search Tree \n"
                <<"5. Red-Black Tree \n"
                <<"6. AVL Tree \n";
            break;
        case 1:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"1. Array \n"
                <<"#2. Doubly Linked List #\n"
                <<"3. Binary Heap \n"
                <<"4. Binary Search Tree \n"
                <<"5. Red-Black Tree \n"
                <<"6. AVL Tree \n";
            break;
        case 2:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"1. Array \n"
                <<"2. Doubly Linked List \n"
                <<"#3. Binary Heap #\n"
                <<"4. Binary Search Tree \n"
                <<"5. Red-Black Tree \n"
                <<"6. AVL Tree \n";
            break;
        case 3:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"1. Array \n"
                <<"2. Doubly Linked List \n"
                <<"3. Binary Heap \n"
                <<"#4. Binary Search Tree #\n"
                <<"5. Red-Black Tree \n"
                <<"6. AVL Tree \n";
            break;
        case 4:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"1. Array \n"
                <<"2. Doubly Linked List \n"
                <<"3. Binary Heap \n"
                <<"4. Binary Search Tree \n"
                <<"#5. Red-Black Tree #\n"
                <<"6. AVL Tree \n";
            break;
        case 5:
            cout<<"######### MENU #########\n"
                <<"Select structure: \n"
                <<"1. Array \n"
                <<"2. Doubly Linked List \n"
                <<"3. Binary Heap \n"
                <<"4. Binary Search Tree \n"
                <<"5. Red-Black Tree \n"
                <<"#6. AVL Tree #\n";
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
inline void displaySubmenuBST(int currentState) {

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
                if (currentState0 < 5)currentState0++;
                displayMainMenu(currentState0);
            }
        }else if(input==ENTER){
            //when "enter" pressed
            while(true){
                int currentState1=0;
                input=_getch();
                if(input==224) {
                    input = _getch();
                    if (input == ARROW_UP) {
                        //arrow "up"
                        if (currentState1 > 0)currentState1--;
                        if(currentState0!=3){displaySubmenu(currentState1);}
                        else { displaySubmenuBST(currentState1);}
                    } else if (input == ARROW_DOWN) {
                        //arrow "down"
                        if (currentState1 < 5)currentState1++;
                        if(currentState0!=3){displaySubmenu(currentState1);}
                        else { displaySubmenuBST(currentState1);}
                    }
                }else if (input==ENTER){
                    switch (currentState0) {
                        case 0:
                            //array
                            switch (currentState1) {
                                case 0:
                                    break;
                            }
                            break;
                        case 1:
                            //doubly linked list

                            break;
                        case 2:
                            //binary heap

                            break;
                        case 3:
                            //binary search tree
                            break;
                        case 4:
                            //red-black tree
                            break;
                        case 5:
                            //AVL tree
                            break;
                    }
                }
            }
        }
    }
}
