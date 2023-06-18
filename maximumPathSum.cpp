#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int maxPath(TreeNode<int>* root, long long int &maxi){
        if(root == NULL) return 0;
        long long int leftSum = maxPath(root->left, maxi);
        long long int rightSum = maxPath(root->right, maxi);
        maxi = max(maxi, leftSum + rightSum + root->val);
        return root->val + max(leftSum, rightSum);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
        if(root == NULL|| !root->left || !root->right) return -1;
        long long int maxi = 0;
        maxPath(root, maxi);
        return maxi;
    // Write your code here.
}