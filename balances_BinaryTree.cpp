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
int solve(BinaryTreeNode<int>* root){
        if(!root) return 0;
        int lh = solve(root->left);
        int rh = solve(root->right);
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1 + max(lh, rh);
    }
    bool isBalancedBT(BinaryTreeNode<int>* root) {
        int height = solve(root);
        if(height == -1) return false;
        return true;
    }