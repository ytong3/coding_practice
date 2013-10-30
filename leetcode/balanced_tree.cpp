//A not so good solution
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
    
		if(abs(max_depth(root->left)-max_depth(root->right))>1) return false;
		return isBalanced(root->left)&&isBalanced(root->right);
    }

	int max_depth(TreeNode *root){
		if(!root) return 0;
		return max(max_depth(root->left),max_depth(root->right))+1;
		}
		
};
