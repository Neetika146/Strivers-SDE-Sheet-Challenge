#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTiterator {
private:
    stack<BinaryTreeNode<int>*> st;
    bool reverse = true;
public:
    BSTiterator(BinaryTreeNode<int>* root, bool isReverse){
        reverse = isReverse;
        pushALL(root);
    }
    bool hasnext(){
        return !st.empty();
    }
    int next(){
        BinaryTreeNode<int> *node = st.top();
        st.pop();
        if(!reverse) pushALL(node->right);
        else pushALL(node->left);
        return node->data;
    }
private:
    void pushALL(BinaryTreeNode<int>* root){
        while(root){
            st.push(root);
            if(!reverse) root = root->left;
            else root= root->right;
        }
    }
};

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
        if(!root) return false;
        BSTiterator l(root, false);
        BSTiterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i<j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    // Write your code here
}