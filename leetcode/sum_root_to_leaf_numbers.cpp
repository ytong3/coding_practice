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
    int res;

    
    void DFS(TreeNode* root, int inter_res){
            //res+=1;
            if(!root) return; //must do error-check even before the base case!
            if(root->left==NULL&&root->right==NULL){
                res=res+inter_res*10+root->val;
                return;
            }
            
            //inter_res=inter_res*10+root->val;
            int tempSum=inter_res*10+root->val;
            //std::cout<<inter_res<<endl;
            if(root->left!=NULL)//Error check before operating pointers)
                DFS(root->left,tempSum);
            if(root->right!=NULL)//Error check before operating pointers)
                DFS(root->right,tempSum);
            
    }
    
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res=0;
        DFS(root,0);
        return res;
    }
};
