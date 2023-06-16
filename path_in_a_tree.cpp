#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
bool getPath(TreeNode<int> *root, int x, vector<int> &ans){
	if(!root) return false;
	ans.push_back(root->data);
	if(ans.back() == x) return true;
	if(getPath(root->left, x, ans) == false && getPath(root->right, x, ans) == false){
		ans.pop_back();
		return false;
	}
	return true;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
	vector<int> ans;
    if(!root) return ans;
	getPath(root, x, ans);
	return ans;
}
