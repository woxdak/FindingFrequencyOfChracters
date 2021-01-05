//
//  BinaryTree.cpp
//  Project5_2250
//  Implementation file for the BinaryTreeclass

#include <iostream>
using namespace std;
#include "BinaryTree.hpp"

void BinaryTree::insertNode(string letter)
{

    if (searchNode(letter)) incrementNode(letter);
    else{
        TreeNode *newNode = nullptr;
        newNode = new TreeNode;
        newNode -> value = letter;
        newNode -> count = 1;
        newNode -> left = newNode-> right = nullptr;
        insert(root, newNode);
    }
}

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if (nodePtr == nullptr)
        nodePtr = newNode;
    else if (newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode);
    else
        insert(nodePtr->right, newNode);
}

void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
    if (nodePtr)
    {
        if (nodePtr->left)
            destroySubTree(nodePtr->left);
        if (nodePtr->right)
            destroySubTree(nodePtr->right);
        delete nodePtr;
    }
}

void BinaryTree::incrementNode(string letter)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == letter) {
            nodePtr->count = nodePtr->count +1; return;
        }
        else if (letter < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
}

bool BinaryTree::searchNode(string letter)
{
    TreeNode *nodePtr = root;

    while (nodePtr)
    {
        if (nodePtr->value == letter) {
            return true;
        }
        else if (letter < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    return false;
}

void BinaryTree::remove(string letter)
{
    deleteNode(letter, root);
}



void BinaryTree::deleteNode(string letter, TreeNode *&nodePtr)
{
    if(letter < nodePtr->value)
        deleteNode(letter, nodePtr->left);
    else if (letter > nodePtr->value)
        deleteNode(letter, nodePtr->right);
    else makeDeletion(nodePtr);
}


void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr = nullptr;

    if (nodePtr == nullptr)
        cout << "Cannot delete empty node.\n";
    else if (nodePtr->right == nullptr)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    }
    else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    } else {
        tempNodePtr = nodePtr->right;
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

void BinaryTree::displayInOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << ": " << nodePtr->count<< endl;
        displayInOrder(nodePtr->right);
    }
}

void BinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        cout << nodePtr->value << ": " << nodePtr->count<< endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void BinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << ": " << nodePtr->count<< endl;
    }
}
