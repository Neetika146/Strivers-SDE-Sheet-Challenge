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
#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
        string ans = "";
        if(!root) return ans;
        queue<TreeNode<int>*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode<int> *node = q.front();
            q.pop();
            if(node==NULL) ans.append("#,");
            else ans.append(to_string(node->data) +',');
            if(node!=NULL) {
                q.push(node->left);
                q.push(node->right);
            }
        }

        return ans;
 //    Write your code here for serializing the tree

}

TreeNode<int>* deserializeTree(string &data)
{
    if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode<int> *root = new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode<int> *node = q. front();
            q.pop();

            getline(s, str, ',');

            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode<int> *leftNode = new TreeNode<int>(stoi(str));
                node -> left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode<int> *rightNode = new TreeNode<int>(stoi(str));
                node -> right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
 //    Write your code here for deserializing the tree

}



