#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
BinaryTreeNode<int> *BT(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&head, BinaryTreeNode<int> *&previ) {
    if(!root) return NULL;

    BT(root->left, head, previ);

    if(previ == NULL) head = root;
    else{
        root->left = previ;
        previ->right = root;
    }
    previ = root;

    BT(root->right, head, previ);

    return head;
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head = NULL;
    BinaryTreeNode<int>* previ = NULL;
    return BT(root, head, previ);
    // Write your code here
}