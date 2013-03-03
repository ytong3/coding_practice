//Path Sum II
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
	vector<int> temp_path;
	vector<vector<int> > result;
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
    	// Start typing your C/C++ solution below
    	// DO NOT write int main() function
    	result.clear();
    	temp_path.clear();
    	if(!root) return result;
    	pathSumHelper(root,sum);
    	return result;
	}
    
	void pathSumHelper(TreeNode *root, int remain){
    	//base case: leaf node. Can we have null node as the base case??
    	if(!root->left&&!root->right){
        	if(root->val==remain){
            	temp_path.push_back(root->val);
            	result.push_back(temp_path);
            	temp_path.pop_back();
        	}
    	}
    	temp_path.push_back(root->val);
    	if(root->left) pathSumHelper(root->left,remain-root->val);
    	if(root->right) pathSumHelper(root->right,remain-root->val);
    	temp_path.pop_back();
    	//NOTE: since the recursion function is void type, there is no need to return a value;
    	//However, if the recursion is not of void type, there must be a value to be returned from both the base case and non-base case.
	}
};
