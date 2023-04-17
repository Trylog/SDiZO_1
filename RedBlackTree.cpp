//
// Created by micha on 16.04.2023.
//

#include "RedBlackTree.h"
#define RED 1
#define BLACK 0

namespace std {
    RedBlackTree::RedBlackTree(int element) {
        nil.color=BLACK;
        pNil=&nil;
        root=static_cast<node *>(malloc(sizeof(struct node)));
        root->parent=pNil;
        root->data=element;
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
                    rotateRight(element->parent->parent);
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
                        rotateLeft(element);
                    }
                    element->parent->color=BLACK;
                    element->parent->parent->color=RED;
                    rotateRight(element->parent->parent);
                }
            }
        }
        root->color=BLACK;
    }

    void RedBlackTree::add(int data) {
        auto element=static_cast<node *>(malloc(sizeof(struct node)));
        auto x=root;
        auto y=pNil;
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
        element->data=data;
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
        
    }

    RedBlackTree::node *RedBlackTree::find(int element) {
        auto x = root;
        while (x!=pNil && x->data!=element){
            if (element < x->data){
                x=x->left;
            } else x=x->right;
        }
        return x;
    }

    RedBlackTree::node *RedBlackTree::treeMinimum(node* x) {
        auto a=x;
        while (a->left!=pNil){
            a=a->left;
        }
        return a;
    }

    void RedBlackTree::remove(int data) {
        auto element=find(data);
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
    }

} // std