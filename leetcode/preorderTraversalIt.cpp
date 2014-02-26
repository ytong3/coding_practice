/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        recur_helper(root,res);
        return res;
    }
    
    void recur_helper(TreeNode *root, vector<int> &res){
        if (!root)
            return;
        res.push_back(root->val);
        recur_helper(root->left,res);
        recur_helper(root->right,res);
    }
};