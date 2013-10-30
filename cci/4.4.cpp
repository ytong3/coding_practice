/*
Given a binary search tree, design an algorithm which creates a linked list of all the
nodes at each depth (eg, if you have a tree with depth D, you’ll have D linked lists).
*/

#include <iostream>
#include <vector>
//#include "treenode.h"
#include "4.3.cpp"
using namespace std;

//basically a BFS 
vector<vector<int> > convert_to_lists(TreeNode *root){
	vector <vector<int> > to_return;
	to_return.clear();
	
	//error checking
	if(root==NULL) return to_return;
	
	vector <TreeNode*> queue;//queue for BFS
	int counter;
	vector<int> list;
	queue.push_back(root);
	while(queue.size()){
		//create a vector for each level
	
		list.clear();
		counter=queue.size();//to keep track of the number of nodes in each level

		while(counter){
			list.push_back(queue[0]->val);
			if(queue[0]->left) queue.push_back(queue[0]->left);
			if(queue[0]->right) queue.push_back(queue[0]->right);
			queue.erase(queue.begin());//deque
			counter--;
		}
		to_return.push_back(list);		
	}
}
			
int main(){
	
	vector<int> arr;
	arr.clear();

	for(int i=0;i<10;i++)
		arr.push_back(i);

	TreeNode* root=add_to_tree(arr, 0, arr.size()-1);
	
	vector<vector<int> > lists=convert_to_lists(root);
	
	for(int i=0;i<lists.size();i++){
		for(int j=0;j<lists[i].size();j++)
			cout<<lists[i][j]<<" ";
		cout<<endl;
	}
}
			
		

