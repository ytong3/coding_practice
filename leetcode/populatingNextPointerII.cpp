/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//using only constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        //root is used as the current node;
        while (root) {
            TreeLinkNode *nextHead=NULL;//the first node in the next level
            TreeLinkNode *previous=NULL;//the previous node in the current level
            
            for (; root; root=root->next) {
                if (!nextHead) {
                    nextHead=root->left?root->left:root->right;
                }
                if (root->left) {
                    if (previous) {
                        previous->next=root->left;
                    }
                    previous=root->left;
                }
                if (root->right) {
                    if (previous) {
                        previous->next=root->right;
                    }
                    previous=root->right;
                }
            }
            //done processing this level and
            root = nextHead;
        }
    }
};