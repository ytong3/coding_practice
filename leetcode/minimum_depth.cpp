//note: be careful when dealing with leaf nodes of a binary tree

class Solution {
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;

		//if(root->left==NULL && root->right==NULL) return 1;
        if(!root->left) return minDepth(root->right)+1;
        if(!root->right) return minDepth(root->left)+1;
        
        return min(minDepth(root->left),minDepth(root->right))+1;
        
    }
};
