/**
 * Definition for binary tree
 * struct TreeNode {
 * 	int val;
 * 	TreeNode *left;
 * 	TreeNode *right;
 * 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	bool hasPathSum(TreeNode *root, int sum) {
    	// Start typing your C/C++ solution below
    	// DO NOT write int main() function
    	if(!root) return false;
    	return hasPathSumHelper(root,sum);
	}
    
	bool hasPathSumHelper(TreeNode* root,int remain_sum){
    	/*
    	//leaf node must be identified explicityly. seems base case should not be null node.
    	if(!root){//not good if say !root&&remain_sum==0, the condition for base case and the condition for returning true are not the same.
        	if(remain_sum==0) return true;
        	return false;
    	}
    	return hasPathSumHelper(root->left,remain_sum-root->val)||hasPathSumHelper(root->right,remain_sum-root->val);
	}*/
   	 
   	 
    	if(!root) return false;//very helpful. multiple base cases.
    	if(!root->left&&!root->right){
        	if(root->val==remain_sum) return true;
    	}
   	 
    	return hasPathSumHelper(root->left,remain_sum-root->val)||hasPathSumHelper(root->right,remain_sum-root->val);
   	 
}

};
