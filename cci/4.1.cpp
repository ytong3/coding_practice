/*
Implement a function to check if a tree is balanced. For the purposes of this question,
a balanced tree is defined to be a tree such that no two leaf nodes differ in distance
from the root by more than one.
*/



#include <iostream>
#include <vector>
#include "math.h"
#include "treenode.h"

using namespace std;

vector<int> max_min(TreeNode* root){
	if(!root){
		vector<int> res;
		res.resize(2,0);
		return res;
	}
	
	vector<int> res;
	res.clear();
	res.resize(2,0);

	vector<int> tmp_l=max_min(root->left);
	vector<int> tmp_r=max_min(root->right);
	res[0]=1+max(tmp_l[0],tmp_r[0]);
	res[1]=1+min(tmp_l[1],tmp_r[1]);
	//cout<<"R result: "<<root->val<<" "<<res[0]<<" "<<res[1]<<endl;
	return res;
}
	

int maxDepth(TreeNode* root){
	if(!root) return 0;
	
	return 1+max(maxDepth(root->left),maxDepth(root->right));
}

int minDepth(TreeNode* root){
	if(!root) return 0;
	return 1+min(minDepth(root->left),minDepth(root->right));
}

int isBalanced(TreeNode* root){
	if(!root)
		return 1;
	
	if((maxDepth(root)-minDepth(root))>1)
		return 0;
	
	return 1;
}

int isBalanced2(TreeNode* root){
	vector<int> res=max_min(root);
	if(res[0]-res[1]<=1) return 1;
	return 0;
}

int main(){
	TreeNode* root=new TreeNode(9);
	root->left=new TreeNode(2);
	root->left->right=new TreeNode(10);
	root->left->right->left=new TreeNode(1);
	root->right=new TreeNode(3);

	cout<<"Tree is balanced: "<<isBalanced(root)<<endl;
	cout<<"Tree is balanced: "<<isBalanced2(root)<<endl;

}
