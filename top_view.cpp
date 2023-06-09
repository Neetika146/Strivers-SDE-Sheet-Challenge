#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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

vector<int> getTopView(TreeNode<int> *root) {
    vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode<int> *, int>> q;
        map<int, int> mpp;
        q.push({root,0});
        while(!q.empty()){
            TreeNode<int> *temp = q.front().first;
            int line = q.front().second;
            q.pop();
            if(mpp.find(line) == mpp.end()) mpp[line] = temp->val;
            if(temp ->left) q.push({temp->left, line-1});
            if(temp ->right) q.push({temp->right, line+1});
        } 
        for(auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;
    // Write your code here.
}