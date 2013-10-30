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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        return validateHelper(root);
    
    }
    int max_node(TreeNode *root){
        if(!root) return INT_MIN;
        return max(root->val, max(max_node(root->left), max_node(root->right)));
    }
    int min_node(TreeNode *root){
        if(!root) return INT_MAX;
        return min(root->val, min(min_node(root->left), min_node(root->right)));
    }
    
    int validateHelper(TreeNode *root){
        if(!root) return true;
        //if(root->left&&root->left->val>root->val) return false;
        //if(root->right&&root->right->val<root->val) return false;
        if(root->val<=max_node(root->left)) return false;
        if(root->val>=min_node(root->right)) return false;
        return validateHelper(root->left)&&validateHelper(root->right);
    }
        
};

/* A much better solution. Kudos to g0na in StackOverflow
Pseudocode as follows. The rationale is very node in BST has it own valid range of value and a child node has a narrower range (more restricted) than its parent does.

IsValidBST(root,-infinity,infinity);

bool IsValidBST(BinaryNode node, int MIN, int MAX) 
{
     if(node == null)
         return true;
     if(node.element > MIN 
         && node.element < MAX
         && IsValidBST(node.left,MIN,node.element)
         && IsValidBST(node.right,node.element,MAX))
         return true;
     else 
         return false;
}
*/

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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        return Helper(root,INT_MAX,INT_MIN);
    }
    
    bool Helper(TreeNode *root, int maxNode, int minNode){
        if(!root) return true;
        
        if(root->val>=maxNode) return false;
        if(root->val<=minNode) return false;
        
        return Helper(root->left, root->val, minNode)&&Helper(root->right,maxNode, root->val);
    }
};
