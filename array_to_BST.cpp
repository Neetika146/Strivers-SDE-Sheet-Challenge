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
    TreeNode<int>* helper(vector<int>& nums, int start, int end) {
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode<int> *root = new TreeNode<int>(nums[mid]);
        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }

TreeNode<int>* sortedArrToBST(vector<int> &nums, int n)
{
     return helper(nums, 0, nums.size()-1);
    // Write your code here.
}