/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool isSymmetricHelp (BinaryTreeNode<int>* left, BinaryTreeNode<int>* right){
    if(!left || !right) return left==right;
    if(left->data != right->data) return false;
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(BinaryTreeNode<int>* node)
{
    if(!node) return true;
    return isSymmetricHelp(node->left, node->right);
    // Write your code here.    
}