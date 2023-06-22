#include <bits/stdc++.h> 
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

class BSTiterator
{
    stack<TreeNode<int>*> st;
    public:
    BSTiterator(TreeNode<int> *root)
    {
        pushALL(root);
        // write your code here
    }

    int next()
    {
        TreeNode<int> *node = st.top();
        st.pop();
        pushALL(node->right);
        return node -> data;
        // write your code here
    }

    bool hasNext()
    {
        return !st.empty();
        // write your code here
    }
    void pushALL(TreeNode<int> *root){
        while(root){
            st.push(root);
            root = root ->left;
        }
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/