/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
    int findmax(TreeNode<int>* root, int &maxi){
        if(!root) return 0;
        int lh = findmax(root->left, maxi);
        int rh = findmax(root->right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode<int>* root) {
        if(!root) return 0;
        int maxi = 0;
        findmax(root, maxi);
        return maxi;
    }
