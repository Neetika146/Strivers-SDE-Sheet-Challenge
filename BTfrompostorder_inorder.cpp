/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
 #include<bits/stdc++.h>
 TreeNode<int>* buildTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map <int, int> &inMap) {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode<int> *root = new TreeNode<int>(postorder[postEnd]);

        int inRoot = inMap[postorder[postEnd]];
        int numsLeft = inRoot - inStart;

        root->left = buildTree (inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, inMap);
        root->right = buildTree (inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, inMap);
        return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
     if(inorder.size() != postorder.size()) return NULL;
        map <int, int> inMap;

        for(int i = 0; i < inorder.size(); i++){
            inMap[inorder[i]] = i;
        }

        return buildTree (inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
	// Write your code here.
}
