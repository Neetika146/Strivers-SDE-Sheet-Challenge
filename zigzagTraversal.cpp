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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
        vector<int>ans;
        if(!root) return ans;
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        bool flag = false;
        while(!q.empty()){
            int sz = q.size();
            vector<int> temp;
            for(int i = 0; i < sz; i++){
                BinaryTreeNode<int>* node = q.front();
                q.pop();
                temp.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag){
                reverse(temp.begin(), temp.end());
            }
            for (int i = 0; i < sz; i++) {
              ans.push_back(temp[i]);
            }
            flag = !flag;
        }

        return ans;
    // Write your code here!
}
