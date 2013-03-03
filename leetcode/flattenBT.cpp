//flatten binary tree
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
	void flatten(TreeNode *root) {
    	// Start typing your C/C++ solution below
    	// DO NOT write int main() function
    	if(!root) return;
    	//printf("Node:%d\n",root->val);
    	flatten(root->left);
    	flatten(root->right);

    	TreeNode* left_tail=root->left;
    	if(left_tail){
        	while(left_tail->right) left_tail=left_tail->right;
        	left_tail->right=root->right;
        	root->right=root->left;
        	root->left=NULL;//set pointer to NULL if not use it anymore!!!!!!!!!
    	}
	}
};
