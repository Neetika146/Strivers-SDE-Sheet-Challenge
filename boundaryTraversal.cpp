#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>* root){
    if(root->left == NULL && root->right == NULL) return true;
    return false;
}

void leftBoundary(TreeNode<int>* root, vector<int> &ans){
    TreeNode<int>* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else curr=curr->right;
    }
}

void rightBoundary(TreeNode<int>* root, vector<int> &ans){
    TreeNode<int>* curr = root->right;
    int i = 0;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data); i++;
        if(curr->right) curr=curr->right;
        else curr=curr->left;
    }
    reverse(ans.end()-i+1, ans.end());
}

void leaves(TreeNode<int>* root, vector<int> &ans){
  if (isLeaf(root)) {
    ans.push_back(root->data);
    return;
  }
    if(root->left) leaves(root->left, ans);
    if(root->right) leaves(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    leftBoundary(root, ans);
    leaves(root, ans);
    rightBoundary(root, ans);
    return ans;
}