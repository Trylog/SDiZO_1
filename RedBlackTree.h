//
// Created by micha on 16.04.2023.
//

#ifndef SDIZO_1_REDBLACKTREE_H
#define SDIZO_1_REDBLACKTREE_H

#include <string>

namespace std {

    class RedBlackTree {
    private:
        struct node{
            public:
                bool color;
                int data;
                node* left;
                node* right;
                node* parent;
        };
        node* pNil, nil{};

        void rotateLeft(node* element);
        void rotateRight(node* element);
        void addFixup(node* element);
        void transplant(node* old, node* newer);
        void removeFixup(node* element);
        node* treeMinimum(node* x);
        node* findP(int element);
        void displayH(node* node, string printed, bool lR);
    public:
        node* root;
        RedBlackTree();
        void buildFromFile(string filePath);
        void remove(int data);
        void add(int data);
        bool find(int element);
        void creatRandom(int size);
        void display();
    };

} // std

#endif //SDIZO_1_REDBLACKTREE_H
