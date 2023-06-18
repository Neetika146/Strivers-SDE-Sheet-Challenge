#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
        vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode<int>*, pair<int,int>>>q;
        q.push({root,{0,0}});
        map <int, map <int, vector<int>>> nodes;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode<int>* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].push_back(node->data);
            if(node->left) q.push({node->left, {x - 1, y + 1}});
            if(node->right) q.push({node->right, {x + 1, y + 1}});
        }
        for(auto i : nodes){
            // vector<int> temp;
            for(auto j : i.second) {
                ans.insert(ans.end(), j.second.begin(), j.second.end());
            }
            // ans.push_back(temp);
        }
        return ans;
    //    Write your code here.
}