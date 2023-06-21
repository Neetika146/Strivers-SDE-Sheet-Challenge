#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree BinaryTreeNode<int> structure

    template <typename T>

    class BinaryTreeBinaryTreeNode<int>
    {
    public :
        T data;
        BinaryTreeBinaryTreeNode<int><T> *left;
        BinaryTreeBinaryTreeNode<int><T> *right;

        BinaryTreeBinaryTreeNode<int>(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeBinaryTreeNode<int>() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
    void predecessor(BinaryTreeNode<int>* root, int &pre, int key){
        while(root != NULL){
            if(root->data < key){
                pre = root->data;
                root= root->right;
            }
            else{
                root = root->left;
            }
        }
    }
    void successor(BinaryTreeNode<int>* root, int &suc, int key){
        while(root != NULL){
            if(root->data > key){
                suc = root->data;
                root= root->left;
            }
            else{
                root = root->right;
            }
        }
    }
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre = -1, suc  = -1;
    BinaryTreeNode<int> *temp = root;
    predecessor(temp, pre, key);
    successor(root, suc, key);
    return {pre, suc};
    // Write your code here.
}
