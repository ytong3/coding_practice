#include <iostream>
#include <string>
#include <vector>
#include "treenode.h"

using namespace std;

TreeNode *m_height_tree(vector<int> &array, int first, int last) {
	if (first>last) return NULL;

	int mid = first + (last-first)/2;

	TreeNode *root=new TreeNode(array[mid]);
	root->left = m_height_tree(array,first,mid-1);
	root->right = m_height_tree(array,mid+1,last);
	return root;
}

/*
int main(){
	vector<int> arr;
	for (int i=0;i<10;i++)
		arr.push_back(i);
	

	TreeNode *root = m_height_tree(arr,0,arr.size()-1);
	root->preorder_traverse();
	vector<vector<char> > res = root->level_traverse();
	for(vector<char> t:res){
		for(char tch:t)
			cout<<tch<<" ";
		cout<<endl;
	}
}
*/
