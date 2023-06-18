class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(!node) return;
        Node *swap = node->left;
        node->left = node->right;
        node->right = swap;
        mirror(node->left);
        mirror(node->right);
        
        // code here
    }
};