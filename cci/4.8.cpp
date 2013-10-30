#include <iostream>
#include "treenode.h"
#include <vector>
#include <exception>

using namespace std;
void print(vector<int>*, int, int);
void findSumPath(TreeNode* root, int sum, vector<int> *buffer, int level){
	if(!root) return;//base case
	
	try{
		buffer->push_back(root->val);
	}
	catch(exception& e){
		cout<<"Standard exception: "<<e.what()<<endl;
	}
	
	int tmp_sum=0;
	for(int buf_idx=level;buf_idx>=0;buf_idx--){
		tmp_sum+=(*buffer)[buf_idx];
		if(tmp_sum==sum) print(buffer, buf_idx, level);
	}
	
	//use constructor to copy a vector
	vector<int> *new_buffer1=new vector<int>(*buffer);
	vector<int> *new_buffer2=new vector<int>(*buffer);
	
	
	if(root->left) findSumPath(root->left, sum, new_buffer1, level+1);
	if(root->right) findSumPath(root->right,sum, new_buffer2, level+1);
}

void print(vector<int> *buffer, int buf_idx, int level){
	for(int idx=buf_idx;idx<=level;idx++)
		cout<<(*buffer)[idx]<<" ";
	cout<<endl;
}
	
	
