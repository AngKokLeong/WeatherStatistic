//
// Created by Ang Kok Leong on 17/7/22.
//

#ifndef WEATHERSTATISTIC_BST_H
#define WEATHERSTATISTIC_BST_H

/*
 * BST.h
 *
 *  Created on: 23 Mar 2019
 *      Author: angkokleong
 */

#include <iostream>
#include <string>

using namespace std;

template <class T>

struct nodeType
{
    T info;
    nodeType<T>* lLink;
    nodeType<T>* rLink;
};


template <class T>
class BST
{
private:
    void inorder(nodeType<T>* p, void (*visit) (T &item)) const;
    void preorder(nodeType<T>* p, void (*visit) (T &item)) const;
    void postorder(nodeType<T>* p, void (*visit) (T &item)) const;

    nodeType<T>* root;

public:
    BST();
    ~BST();

    void insert(T i);
    bool search(const T searchItem) const;
    bool isEmpty();
    void inorderTraversal(void (*visit) (T &item)) const;
    void preorderTraversal(void (*visit) (T &item)) const;
    void postorderTraversal(void (*visit) (T &item)) const;

    void destroy(nodeType<T>* &p);
};

template <class T>
BST<T>::BST()
{
    root = NULL;
}

template <class T>
BST<T>::~BST()
{
    destroy(root);
}

template <class T>
bool BST<T>::search(const T searchItem) const
{
    nodeType<T> *current;
    bool found = false;

    if(root == NULL)
        cout << "Cannot search an empty tree." << endl;
    else{
        current = root;
        while(current != NULL && !found){
            if(searchItem == current->info)
                found = true;
            else if(searchItem < current->info)
                current = current->lLink;
            else
                current = current->rLink;
        }
    }
    return found;
}

template <class T>
void BST<T>::destroy(nodeType<T>* &p)
{
    if(p != NULL)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = NULL;
    }
}

template <class T>
void BST<T>::insert(T i)
{
    nodeType<T>* newNode = new nodeType<T>;
    nodeType<T>* trailCurrent = NULL;
    nodeType<T>* current;

    newNode->info = i;
    newNode->lLink = NULL;
    newNode->rLink = NULL;

    if(isEmpty() == true){
        root = newNode;
    }else{
        current = root;

        //find the node's trailCurrent. Find where there is appropriate space
        while(current != NULL){
            trailCurrent = current;

            if(i == current->info)
            {
                cout << i << "Item already inserted! No duplicates allowed" << endl;
                return;
            }
            else if(i > current->info)
            {
                current = current->rLink;
            }
            else if (i < current->info){
                current = current->lLink;
            }
        }


        if(i > trailCurrent->info)
        {
            trailCurrent->rLink = newNode;
            //cout << newNode->info << " Inserted!" << endl;
        }else if(i < trailCurrent->info){
            trailCurrent->lLink = newNode;
            //cout << newNode->info << " Inserted!" << endl;
        }
    }
}

template <class T>
bool BST<T>::isEmpty()
{
    return (root == NULL);
}

template <class T>
void BST<T>::inorderTraversal(void (*visit) (T &item)) const
{
    inorder(root, *visit);
}

template <class T>
void BST<T>::inorder(nodeType<T>* p, void (*visit) (T &item)) const
{
    if(p != NULL){
        inorder(p->lLink, *visit);
        //cout << p->info << " ";
        (*visit)(p->info);
        inorder(p->rLink, *visit);
    }
}

template <class T>
void BST<T>::preorderTraversal(void (*visit) (T &item)) const
{
    preorder(root, *visit);
}

template <class T>
void BST<T>::preorder(nodeType<T>* p, void (*visit) (T &item)) const
{
    if(p!= NULL)
    {
        //cout << p->info << " ";
        (*visit)(p->info);
        preorder(p->lLink, *visit);
        preorder(p->rLink, *visit);
    }
}

template <class T>
void BST<T>::postorderTraversal(void (*visit) (T &item)) const
{
    postorder(root, *visit);
}

template <class T>
void BST<T>::postorder(nodeType<T>* p, void (*visit) (T &item)) const
{
    if(p!= NULL)
    {
        postorder(p->lLink, *visit);
        postorder(p->rLink, *visit);
        //cout << p->info << " ";
        (*visit) (p->info);
    }
}

#endif //WEATHERSTATISTIC_BST_H
