#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
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
class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode; 
        this->minNode = minNode ;
        this->maxSize = maxSize ;
    }
    
};
    NodeValue maxSumBSThelper(TreeNode<int>* root) {
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

        auto left = maxSumBSThelper(root->left);
        auto right = maxSumBSThelper(root->right);

        if(root->data > left.maxNode && root->data < right.minNode){
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
int largestBST(TreeNode<int>* root) 
{
    return maxSumBSThelper(root).maxSize;
    // Write your code here.
}
