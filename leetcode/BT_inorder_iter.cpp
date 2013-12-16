/*
Definition for binary tree
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
        vector<int> res;
        if(!root)
            return res;
            
        stack<TreeNode*> s;//keep all those visited
        TreeNode* current = root;
        
        do{
            if(current!=NULL){
                s.push(current);//record the visited node in the stack so we can print it when we visit it at the second time.
                current=current->left;
            }
            else{
                current=s.top();//must ensure that no NULL pointer is pushed in. since we will access the pointer's object later.
                s.pop();
                res.push_back(current->val);
                current=current->right;
            }
        }while(!s.empty()||current);

        return res;
    }
};