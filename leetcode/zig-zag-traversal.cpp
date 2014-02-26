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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode*> bfsq;
        bfsq.push(root);
        int counter(1),curCounter(0);
        bool l2r=true;
        while(!bfsq.empty())
        {
            //a new layer;
            vector<int> em;
            res.push_back(em);
            curCounter=0;
            
            while (counter)
            {
                TreeNode* cur=bfsq.front();
                res.back().push_back(cur->val);
                bfsq.pop();
                if (cur->left) {
                    bfsq.push(cur->left);
                    curCounter++;
                }
                if (cur->right) {
                    bfsq.push(cur->right);
                    curCounter++;
                }
                counter--;
            }
            counter=curCounter;
            if (!l2r)
                reverse(res.back().begin(),res.back().end());
            l2r=!l2r;
        }
        return res;
    }
};