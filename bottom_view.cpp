#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
        if(!root) return ans;
        queue<pair<BinaryTreeNode<int> *, int>> q;
        map<int, int> mpp;
        q.push({root,0});
        while(!q.empty()){
            BinaryTreeNode<int> *temp = q.front().first;
            int line = q.front().second;
            q.pop();
            if(mpp.find(line) == mpp.end()) mpp[line] = temp->data;
            else mpp[line] = temp->data;
            if(temp ->left) q.push({temp->left, line-1});
            if(temp ->right) q.push({temp->right, line+1});
        } 
        for(auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;
    // Write your code here.
    
}
