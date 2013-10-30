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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //base case I
        if(p==NULL && q!=NULL) return false;
        if(p!=NULL && q==NULL) return false;
        //base case II
        if(p==NULL && q==NULL) return true;
        //recursion
        if(p->val==q->val)
        		return isSameTree(p->left, q->left)&&isSameTree(p->right,q->right);
        	else return false;
    }
    

};
