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
void s(TreeNode<int> *r, TreeNode<int> *p, TreeNode<int> *l, bool &q, TreeNode<int> *&ans){
    if(!r) return;
    if(r->data == l->data){
        r->left = p;
        q = 1;
        ans = r;
        return;
    }
    s(r->left, r, l, q, ans);
    if(q){  
       r->left=p;
       return;
    }
    s(r->right, r, l, q, ans);
    if(q){
        if(r->left){
            r->right=r->left;
        }
        else{
            r->right=NULL;
        }
        r->left=p;
        return;    
    }
}

TreeNode<int> * invertBinaryTree(TreeNode<int> *r, TreeNode<int> *l)
{
    bool q = 0;
    TreeNode<int> *ans =NULL;
    s(r, NULL, l, q, ans);
    return ans;
	// Write your code here.
}
