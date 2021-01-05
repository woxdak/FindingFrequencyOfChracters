//  BinaryTree.hpp
//  Created by Warren T on 11/8/20.
//  Copyright © 2020 Warren T. All rights reserved.
//  Description : Specification file for the BinaryTree class,
//  the non-inline functions will be defined in the implementation
//  file, "BinaryTree.cpp"


#ifndef BINARYTREE_HPP_
#define BINARYTREE_HPP_


#include <stdio.h>
#include <iostream>
using namespace std;

class BinaryTree
{
private:
     struct TreeNode
     {
         string value;
         int count;
         TreeNode *left;
         TreeNode *right;
     };

    TreeNode *root;

    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(string, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

public:
    BinaryTree() { root = nullptr;}
    ~BinaryTree() {destroySubTree(root);}

    void insertNode(string);
    bool searchNode(string);
    void incrementNode(string);
    void remove(string);

    void displayInOrder() const
        { displayInOrder(root); }
    void displayPreOrder() const
        { displayPreOrder(root); }
    void displayPostOrder() const
        { displayPostOrder(root); }
};


#endif
