//
// Created by micha on 16.04.2023.
//

#include <random>
#include <fstream>
#include <iostream>
#include "RedBlackTree.h"
#define RED 1
#define BLACK 0

namespace std {
    RedBlackTree::RedBlackTree() {
        nil.color=BLACK;
        pNil=&nil;
        root= nullptr;/*
        root=static_cast<node *>(malloc(sizeof(struct node)));
        root->parent=pNil;
        root->data=NULL;
        root->color=BLACK;
        root->right=pNil;
        root->left=pNil;*/
    }

    void RedBlackTree::rotateLeft(RedBlackTree::node *element) {
        auto rSon = element->right;
        element->right=rSon->left;
        if (rSon->left!=pNil)rSon->left->parent=element;
        rSon->parent=element->parent;
        if (element->parent==pNil) {
            root = rSon;
        } else if (element==element->parent->left){
            element->parent->left=rSon;
        } else element->parent->right=rSon;
        rSon->left=element;
        element->parent=rSon;
    }

    void RedBlackTree::rotateRight(RedBlackTree::node *element) {
        auto prt = element->parent;
        prt->left=element->right;
        if (element->right!=pNil)element->right->parent=prt;
        element->parent=prt->parent;
        if (prt->parent==pNil){
            root=element;
        } else if(prt==prt->parent->left){
            prt->parent->left=element;
        } else prt->parent->right=element;
        element->right=prt;
        prt->parent=element;
    }

    void RedBlackTree::addFixup(RedBlackTree::node *element) {
        while (element->parent->color==RED){
            if (element->parent==element->parent->parent->left){
                auto uncle=element->parent->parent->right;
                if (uncle->color==RED){
                    element->parent->color=BLACK;
                    uncle->color=BLACK;
                    element->parent->parent->color=RED;
                    element=element->parent->parent;
                }else {
                    if (element == element->parent->right) {
                        element = element->parent;
                        rotateLeft(element);
                    }
                    element->parent->color=BLACK;
                    element->parent->parent->color=RED;
                    rotateRight(element->parent->parent->left);
                }
            }else{
                auto uncle=element->parent->parent->left;
                if (uncle->color==RED){
                    element->parent->color=BLACK;
                    uncle->color=BLACK;
                    element->parent->parent->color=RED;
                    element=element->parent->parent;
                }else {
                    if (element == element->parent->left) {
                        element = element->parent;
                        rotateRight(element->left);
                    }
                    element->parent->color=BLACK;
                    element->parent->parent->color=RED;
                    rotateLeft(element->parent->parent);
                }
            }
        }
        root->color=BLACK;
    }

    void RedBlackTree::add(int data) {
        if(root==NULL){
            root=static_cast<node *>(malloc(sizeof(struct node)));
            root->data=data;
            root->parent=pNil;
            root->color=BLACK;
            root->left=pNil;
            root->right=pNil;
            return;
        }
        auto element=static_cast<node *>(malloc(sizeof(struct node)));
        auto x=root;
        auto y=pNil;
        element->data=data;
        while (x!=pNil){
            y=x;
            if (element->data < x->data){
                x=x->left;
            } else x=x->right;
        }
        element->parent=y;
        if (y==pNil){
            root=element;
        } else if (element->data < y->data){
            y->left=element;
        } else y->right=element;
        element->left=pNil;
        element->right=pNil;
        element->color=RED;
        //if(data==6)rotateLeft(root);
        //if(data==6)rotateRight(root->left);
        //display();
        addFixup(element);
    }

    void RedBlackTree::transplant(RedBlackTree::node *old, RedBlackTree::node *newer) {
        if (old->parent==pNil){
            root=newer;
        } else if (old==old->parent->left){
            old ->parent->left=newer;
        }else old->parent->right=newer;
        newer->parent=old->parent;
    }

    void RedBlackTree::removeFixup(RedBlackTree::node *element) {
        while (element!=root && element->color==BLACK){
            if(element==element->parent->left){
                auto brother = element->parent->right;
                if (brother->color==RED){
                    brother->color=BLACK;
                    element->parent->color=RED;
                    rotateLeft(element->parent);
                    brother=element->parent->right;
                }
                if (brother->left->color==BLACK && brother->right->color==BLACK){
                    brother->color=RED;
                    element=element->parent;
                }else {
                    if (brother->right->color == BLACK) {
                        brother->left->color = BLACK;
                        brother->color = RED;
                        rotateRight(brother->left);
                        brother = element->parent->right;
                    }
                    brother->color = element->parent->color;
                    element->parent->color = BLACK;
                    brother->right->color = BLACK;
                    rotateLeft(element->parent);
                    element = root;
                }
            }else{
                auto brother = element->parent->left;
                if (brother->color==RED){
                    brother->color=BLACK;
                    element->parent->color=RED;
                    rotateRight(element->parent->left);
                    brother=element->parent->left;
                }
                if (brother->right->color==BLACK && brother->left->color==BLACK){
                    brother->color=RED;
                    element=element->parent;
                }else {
                    if (brother->left->color == BLACK) {
                        brother->right->color = BLACK;
                        brother->color = RED;
                        rotateLeft(brother);
                        brother = element->parent->left;
                    }
                    brother->color = element->parent->color;
                    element->parent->color = BLACK;
                    brother->left->color = BLACK;
                    rotateRight(element->parent->left);
                    element = root;
                }
            }
        }
        element->color=BLACK;
    }

    RedBlackTree::node *RedBlackTree::findP(int element) {
        auto x = root;
        while (x!=pNil && x->data!=element){
            if (element < x->data){
                x=x->left;
            } else x=x->right;
        }
        return x;
    }

    bool RedBlackTree::find(int element) {
        if(findP(element)!=pNil)return true;
        return false;
    }

    RedBlackTree::node *RedBlackTree::treeMinimum(node* x) {
        auto a=x;
        while (a->left!=pNil){
            a=a->left;
        }
        return a;
    }

    void RedBlackTree::remove(int data) {
        auto element=findP(data);
        if (element==pNil)throw -1; //this element does not exist in this tree

        node* newer= nullptr;
        auto ogColor=element->color;
        if(element->left==pNil){
            newer = element->right;
            transplant(element, element->right);
        }else if (element->right==pNil){
            newer = element->left;
            transplant(element, element->left);
        }else{
            auto treeMin= treeMinimum(element->right);
            ogColor=treeMin->color;
            newer = treeMin->right;
            if(treeMin->parent==element){
                newer->parent=treeMin;
            }else {
                transplant(treeMin, treeMin->right);
                treeMin->right=element->right;
                treeMin->right->parent=treeMin;
            }
            transplant(element, treeMin);
            treeMin->left=element->left;
            treeMin->left->parent=treeMin;
            treeMin->color=element->color;
        }
        if(ogColor==BLACK) removeFixup(newer);
        free(element);
    }

    void RedBlackTree::creatRandom(int size) {
        std::uniform_int_distribution<int> distribution(0,0xffffffff);
        std::random_device rd;
        for (auto i = 0; i < size; ++i) add(distribution(rd));
    }

     void RedBlackTree::buildFromFile(string filePath) {
        fstream input;
        input.open(filePath, ios::in);
        if(input.good()) {
            int size=0;
            input >> size;
            if (size) {
                int tempIn;
                for (auto i = 0; i < size; ++i) {
                    if (!input.eof()) {
                        input >> tempIn;
                        add(tempIn);
                    } else throw -3; //wrong file length
                }
            }
        }
    }

    void RedBlackTree::displayH(node* node, string printed, bool lR) { //lR - left(1) or right(0);
        if(node!=pNil){
            cout<<printed;
            if(lR){
                cout<<"R--- ";
                printed+="   ";
            } else{
                cout<<"L--- ";
                printed+="|  ";
            }
            cout<<node->data<<"[" <<(node->color ? "RED" : "BLACK")<<"]"<<endl;
            displayH(node->left, printed, false);
            displayH(node->right, printed, true);
        }
    }

    void RedBlackTree::display() {
        if (root) displayH(root, "", true);
        cout<<endl;
    }

} // std