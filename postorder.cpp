#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> postorder;
        if (root == NULL) return postorder;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            if(curr->left != NULL) s1.push(curr->left);
            if(curr->right != NULL) s1.push(curr->right);
            s2.push(curr);
        }
        while(!s2.empty()){
            postorder.push_back(s2.top()->data);
            s2.pop();
        }
        return postorder;
    // Write your code here.
}