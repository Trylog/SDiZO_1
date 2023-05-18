#include <iostream>
#include <conio.h>
#include "Array.h"
#include "DoublyLinkedList.h"
#include "RedBlackTree.h"
#include "BinaryHeap.h"
#include <chrono>
#include <random>

using namespace std;

void menu();

void testRBT(int number) {
    RedBlackTree a;
    cout<<number<<": "<<endl;
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 0xffffffff);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t4 = std::chrono::high_resolution_clock::now();
    auto t3 = std::chrono::high_resolution_clock::now();

    srand(0);
    double k = 0.0, m = 0.0, n = 0.0;
    for (int j = 0; j < 100; ++j) {
        int l[number];
        for (int i = 0; i < number; ++i) {
            l[i] = distribution(rd);
        }
        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.add(l[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.find(rand() % number);
        }
        t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.remove(a.root->data);
        }
        t4 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        auto time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
        auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
        k += time_span.count();
        n += time_span1.count();
        m += time_span2.count();
    }
    cout << k << endl << m << endl << n << endl << endl;
}

void testDLL(int number) {
    DoublyLinkedList a;
    cout<<number<<": "<<endl;
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 0xffffffff);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t4 = std::chrono::high_resolution_clock::now();
    auto t3 = std::chrono::high_resolution_clock::now();

    srand(0);
    double k = 0.0, m = 0.0, n = 0.0;
    for (int j = 0; j < 20; ++j) {
        int l[number];
        for (int i = 0; i < number; ++i) {
            l[i] = distribution(rd);
        }
        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.add(0, l[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.find(rand() % number);
        }
        t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.remove(l[i]);
        }
        t4 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        auto time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
        auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
        k += time_span.count();
        n += time_span1.count();
        m += time_span2.count();
    }
    cout << k << endl << m << endl << n << endl << endl;
    k = 0.0; m = 0.0; n = 0.0;
    DoublyLinkedList b;
    for (int j = 0; j < 20; ++j) {
        int l[number];
        for (int i = 0; i < number; ++i) {
            l[i] = distribution(rd);
        }
        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            b.add(i, l[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            b.find(rand() % number);
        }
        t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            b.remove(b.headP->data);
        }
        t4 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        auto time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
        auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
        k += time_span.count();
        n += time_span1.count();
        m += time_span2.count();
    }
    cout << k << endl << m << endl << n << endl << endl;
    k = 0.0; m = 0.0; n = 0.0;
    DoublyLinkedList c;
    for (int j = 0; j < 20; ++j) {
        int l[number];
        for (int i = 0; i < number; ++i) {
            l[i] = distribution(rd);
        }
        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            c.add(i>0 ? rand()%i : 0, l[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            c.find(rand() % number);
        }
        t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            c.remove(l[i]);
        }
        t4 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        auto time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
        auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
        k += time_span.count();
        n += time_span1.count();
        m += time_span2.count();
    }
    cout << k << endl << m << endl << n << endl << endl;
    k = 0.0; m = 0.0; n = 0.0;
}

void testA(int number) {
    Array a;
    cout<<number<<": "<<endl;
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 0xffffffff);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t4 = std::chrono::high_resolution_clock::now();
    auto t3 = std::chrono::high_resolution_clock::now();

    srand(0);
    double k = 0.0, m = 0.0, n = 0.0;
    for (int j = 0; j < 20; ++j) {
        int l[number];
        for (int i = 0; i < number; ++i) {
            l[i] = distribution(rd);
        }
        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.add(0, l[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.find(rand() % number);
        }
        t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.remove(0);
        }
        t4 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        auto time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
        auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
        k += time_span.count();
        n += time_span1.count();
        m += time_span2.count();
    }
    cout << k << endl << m << endl << n << endl << endl;
    k = 0.0; m = 0.0; n = 0.0;
    Array b;
    for (int j = 0; j < 20; ++j) {
        int l[number];
        for (int i = 0; i < number; ++i) {
            l[i] = distribution(rd);
        }
        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            b.add(i, l[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            b.find(rand() % number);
        }
        t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            b.remove(number-i-1);
        }
        t4 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        auto time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
        auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
        k += time_span.count();
        n += time_span1.count();
        m += time_span2.count();
    }
    cout << k << endl << m << endl << n << endl << endl;
    k = 0.0; m = 0.0; n = 0.0;
    Array c;
    for (int j = 0; j < 20; ++j) {
        int l[number];
        for (int i = 0; i < number; ++i) {
            l[i] = distribution(rd);
        }
        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            c.add(i>0 ? rand()%i : 0, l[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            c.find(i>0 ? rand()%i : 0);
        }
        t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            c.remove(number-i-1);
        }
        t4 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        auto time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
        auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
        k += time_span.count();
        n += time_span1.count();
        m += time_span2.count();
    }
    cout << k << endl << m << endl << n << endl << endl;
    k = 0.0; m = 0.0; n = 0.0;
}

void testBH(int number) {
    BinaryHeap a;
    cout<<number<<": "<<endl;
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(0, 0xffffffff);
    auto t1 = std::chrono::high_resolution_clock::now();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto t4 = std::chrono::high_resolution_clock::now();
    auto t3 = std::chrono::high_resolution_clock::now();

    srand(0);
    double k = 0.0, m = 0.0, n = 0.0;
    for (int j = 0; j < 100; ++j) {
        int l[number];
        for (int i = 0; i < number; ++i) {
            l[i] = distribution(rd);
        }
        t1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.add(l[i]);
        }
        t2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.find(rand() % number);
        }
        t3 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < number; ++i) {
            a.remove(0);
        }
        t4 = std::chrono::high_resolution_clock::now();
        auto time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
        auto time_span1 = std::chrono::duration_cast<std::chrono::duration<double>>(t3 - t2);
        auto time_span2 = std::chrono::duration_cast<std::chrono::duration<double>>(t4 - t3);
        k += time_span.count();
        n += time_span1.count();
        m += time_span2.count();
    }
    cout << k << endl << m << endl << n << endl << endl;
}

int main() {

    //cout<<"### RBT ###"<<endl;
    /*testRBT(5000);
    testRBT(8000);
    testRBT(10000);
    testRBT(16000);
    testRBT(20000);
    testRBT(40000);
    testRBT(60000);
    testRBT(100000);*/
    cout<<endl<<"### DLL ###"<<endl<<endl;
    testDLL(5000);
    testDLL(8000);
    testDLL(10000);
    testDLL(16000);
    testDLL(20000);
    testDLL(40000);
    testDLL(60000);
    testDLL(100000);/*
    cout<<endl<<"### Array ###"<<endl<<endl;
    testA(5000);
    testA(8000);
    testA(10000);
    testA(16000);
    testA(20000);
    testA(40000);
    testA(60000);
    testA(100000);*//*
    cout<<endl<<"### BinaryHeap ###"<<endl<<endl;
    testBH(5000);
    testBH(8000);
    testBH(10000);
    testBH(16000);
    testBH(20000);
    testBH(40000);
    testBH(60000);
    testBH(100000);*/
    /*auto test = new Array();
    test->buildFromFile("tab1.txt");
    test->display();
    test->remove(2);
    test->remove(3);
    test->remove(0);
    test->remove(0);
    test->remove(0);
    test->display();
    test->add(0,2);
    test->add(1,6);
    test->add(2,8);
    test->add(1,4);
    test->display();
    test->add(0,0);
    test->display();*/



    menu();
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
