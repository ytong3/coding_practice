//Convert Sorted Array to Binary Search Tree

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size()==0)
            return NULL;
        return converter_helper(num, 0, num.size()-1);
    }
    
    TreeNode *converter_helper(vector<int> &num, int head, int tail){
        if (head==tail)
            return new TreeNode(num[head]);
        
        int mid = (head+tail)/2;
        TreeNode* res=new TreeNode(num[mid]);
        
        if(head!=mid)//Important!
            res->left=converter_helper(num,head,mid-1);
        if(tail!=mid)//Important!
            res->right=converter_helper(num,mid+1,tail);
        return res;
    }
};
