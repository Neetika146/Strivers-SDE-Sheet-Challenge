#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int levelorder(TreeNode<int> *root){
    if(!root) return 0;
    int ans = 0;
    queue <TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        ans = max(ans, n);
        while(n--){
            TreeNode<int> * temp = q.front();
            q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}

int getMaxWidth(TreeNode<int> *root)
{
    return levelorder(root);   
    // Write your code here.
}