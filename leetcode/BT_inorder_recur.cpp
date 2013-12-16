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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int>* res = new vector<int>;
        res->clear();
        helper(root, *res);
        return *res;
    }
    
    void helper(TreeNode *root, vector<int> &res_coll){
        if(!root)
            return;
        helper(root->left,res_coll);
        res_coll.push_back(root->val);
        helper(root->right,res_coll);
    }
};