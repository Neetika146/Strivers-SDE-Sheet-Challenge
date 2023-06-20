#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
    TreeNode<int>* helper(vector<int>& preorder, int &s, int ub) {
        if(s>=preorder.size() || preorder[s] > ub) return NULL;
        TreeNode<int> *root = new TreeNode<int>(preorder[s++]);
        root->left = helper(preorder, s, root->data);
        root->right = helper(preorder, s, ub);
        return root;
    }
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i = 0;
        return helper(preOrder, i, INT_MAX);
    // Write your code here.
}