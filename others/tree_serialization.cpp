#include <iostream>
#include "treenode.h"
#include <vector>
#include <string>

using namespace std;

void serialize_tree(TreeNode* root, vector<char> &output) {
	//a preorder traveral of subtree root
	if (!root){
		output.push_back('#');
		return;
	}
	
	output.push_back('0'+root->val);
	serialize_tree(root->left,output);
	serialize_tree(root->right,output);
}

//we use a reference of a integer here (&index) to let it increment along the way we call the recurring function. Whenever the recurring fucntion is called, index is incremented by 1. and this is what we need.
TreeNode *deserialize_tree(const vector<char> input, int &index) {
	cout<<index<<" "<<input.size()<<"**"<<endl;
	if (index>input.size()||input[index]=='#')
		return NULL;
	
	char label = input[index];
	TreeNode *root = new TreeNode(label-'0');
	index++;
	root->left = deserialize_tree(input, index);

	index++;
	root->right = deserialize_tree(input,index); 
	return root;
	//notice that since index is a reference, the index in the 'second' call is not different by 1 to the index in the 'first' call. 
}

void inorder_pre_test(TreeNode *root){
	static TreeNode *pre = NULL;
	if (root==NULL) return;
	inorder_pre_test(root->left);
	cout<<"Current Node: "<<root->val<<" Its pre is "<<(pre==NULL?-1:pre->val)<<endl;;
	pre = root;
	inorder_pre_test(root->right);
}

void dfs_helper(TreeNode *root, bool &ans) {
    if (!root||!ans) return;
    static TreeNode *pre = NULL;
    dfs_helper(root->left,ans);
    if (pre!=NULL&&root->val<=pre->val){
        ans = false;
        return;
    }
    pre = root;
    dfs_helper(root->right,ans);
}

bool isValidBST(TreeNode *root) {
    bool ans=true;
    //TreeNode *pre = NULL;
    dfs_helper(root,ans);
    return ans;
}


int main(){
	/*
    TreeNode *root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->right = new TreeNode(9);
	root->left->right=new TreeNode(2);
     */
    TreeNode *root = new TreeNode(0);
	root->left = new TreeNode(-1);

	vector<char> res;
	serialize_tree(root,res);
	for(char i:res) cout<<i<<" ";
	cout<<endl;
	int index=0;
	cout<<"Begin deserializing"<<endl;
	TreeNode *newroot=	deserialize_tree(res,index);
	res.clear();
	serialize_tree(newroot,res);
	for(char i:res) cout<<i<<" ";
	cout<<endl;

	if(isValidBST(root)){
        cout<<"OK"<<endl;
    }
    else cout<<"NO"<<endl;
}
