#include <iostream>
#include <string>
#include <vector>
#include <treenode.h>

//takeaway: working backward is a useful way to reduce duplicates.
using namespace std;

void dfs_helper(TreeNode *root, int sum, vector<int> ans, vector<vector<int> > &ans_coll) {
	if (!root) return;

	ans.push_back(root->val);
	int temp(0)
	for (int i=ans.size()-1;i>=0;i--){
		temp+=ans[i];
		if (temp==sum) ans_coll.push_back(vector<int>(ans.begin()+i,ans.end()));
	}

	dfs_helper(root->left,num,ans,ans_coll);
	dfs_helper(root->right,num,ans,ans_coll);
}
		
