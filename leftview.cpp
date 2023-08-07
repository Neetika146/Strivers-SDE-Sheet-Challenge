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
void leftview(TreeNode<int> *root, int level, vector<int> &ans){
    if(!root) return;
    if(level == ans.size()){
        ans.push_back(root->data);
    }
    if(root->left) leftview(root->left, level + 1, ans);
    if(root->right) leftview(root->right, level + 1, ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    
    vector<int> ans;
    if(!root) return ans;
    leftview(root,0, ans);
    return ans;
   // Your code here
}


// vector<int> leftView(Node *root)
// {
//    vector<int> ans;
//    if(!root) return ans;
//    queue<Node*> q;
//    q.push(root);
//    while(!q.empty()){
//        int s=q.size();
//        ans.push_back(q.front()->data);
//        while(s--){
//            Node* t=q.front();
//            q.pop();
//            if(t->left) q.push(t->left);
//            if(t->right) q.push(t->right);
//        }
//    }
//    return ans;
// }