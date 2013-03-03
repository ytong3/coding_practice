/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
	void connect(TreeLinkNode *root) {
    	// Start typing your C/C++ solution below
    	// DO NOT write int main() function
    	if(!root) return;
    	BFS(root);
	}
    
	void BFS(TreeLinkNode* root){
    	vector<TreeLinkNode* > queue;
    	queue.clear();
    	queue.push_back(root);
    	while(queue.size()){//stupid if the condition is !queue.size()
        	vector<TreeLinkNode*> temp_queue = queue;
        	while(temp_queue.size()>1){
            	temp_queue[0]->next=temp_queue[1];
            	if(temp_queue[0]->left) queue.push_back(temp_queue[0]->left);
            	if(temp_queue[0]->right) queue.push_back(temp_queue[0]->right);
            	temp_queue.erase(temp_queue.begin());
            	queue.erase(queue.begin());
        	}
        	if(temp_queue[0]->left) queue.push_back(temp_queue[0]->left);
        	if(temp_queue[0]->right) queue.push_back(temp_queue[0]->right);
        	temp_queue.erase(temp_queue.begin());
        	queue.erase(queue.begin());
    	}
	}
};
