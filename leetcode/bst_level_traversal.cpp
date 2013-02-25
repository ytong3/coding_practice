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
    vector<vector<int> > res;
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        if(!root)
            return res;
        BFS(root);
        return res;
    }
    
    void BFS(TreeNode *root){//note the termination condition.
        vector<TreeNode*> queue;
        queue.push_back(root);
        queue.push_back(NULL);
        vector<int> sublist;
        sublist.clear();
        while(queue.size()){
            TreeNode* current_node = queue[0];
            if(queue[0]==NULL){
                 res.push_back(sublist);
                 sublist.clear();
                 queue.erase(queue.begin());
                 if(queue.size()!=0)
                    queue.push_back(NULL);
            }
            else{
                if(current_node->left) queue.push_back(current_node->left);
                if(current_node->right) queue.push_back(current_node->right);
                sublist.push_back(current_node->val);
                queue.erase(queue.begin());
            }
        }
    }
    
};


//A neater and better solution
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
    vector<vector<int> > res;
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        if(!root)
            return res;
        BFS(root);
        return res;
    }
    
    void BFS(TreeNode *root){
        vector<TreeNode*> queue;
        queue.push_back(root);
        queue.push_back(NULL);
        vector<int> sublist;
        sublist.clear();
        while(queue.size()){
            TreeNode* current_node = queue[0];
            if(queue[0]==NULL){
                 res.push_back(sublist);
                 sublist.clear();
                 queue.erase(queue.begin());
                 if(queue.size()!=0)
                    queue.push_back(NULL);
            }
            else{
                if(current_node->left) queue.push_back(current_node->left);
                if(current_node->right) queue.push_back(current_node->right);
                sublist.push_back(current_node->val);
                queue.erase(queue.begin());
            }
        }
    }
    
};
