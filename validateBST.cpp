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
    bool isValidBST(BinaryTreeNode<int>* root, long long minval, long long maxval) {
        if(!root) return true;
        if((root->data >= maxval) || (minval >= root->data)) return false;
        return isValidBST(root->left, minval, root->data) && isValidBST(root->right, root->data, maxval);
    }
bool validateBST(BinaryTreeNode<int> *root) {
    return isValidBST(root, (long long)INT_MIN*2, (long long)INT_MAX*2);
    // Write your code here
}