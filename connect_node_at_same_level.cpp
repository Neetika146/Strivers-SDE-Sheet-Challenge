#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    if (!root) return;
        queue<BinaryTreeNode< int >*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            BinaryTreeNode< int > *prev = q.front();
            // q.pop();
            while(sz--){
                BinaryTreeNode< int >* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                prev->next = curr;
                prev = curr;
            }
            prev->next = NULL;
        }
    // Write your code here.
}