#include "stdio.h"
#include <vector>
#include <queue>
#include <sstream>
#include <iostream>
#include <assert.h>
using namespace std;
// Definition for binary tree
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
	 TreeNode *parent;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	 
	 void preorder_traverse();
     vector<vector<string> > level_traverse();
	 void insert(int val);
	 TreeNode* delete_node(int val);
 };

TreeNode* TreeNode::delete_node(int target){
	//find the node first
	TreeNode dummy(-1);
	dummy.left = this;
	TreeNode *current=this, *pre=&dummy;
	while (current&&current->val!=target){
		if (current->val==target) 
			break;
		if(current->val>target){
			pre = current;
			current=current->left;
		}else{
			pre = current;
			current=current->right;
		}
	}
	if (!current) {cerr<<"Key not found."<<endl;return this;}
	if (current->left==NULL&&current->right==NULL){
		delete current;
		pre->right = pre->left = NULL;
		return dummy.left;
	}
	else if (!current->left){
		if (current==pre->left) {
			pre->left = current->right;
			delete current;
			return dummy.left;
		}else{
			pre->right = current->right;
			delete current;
			return dummy.left;
		}
	}else if (!current->right){
		if (current==pre->left) {
			pre->left = current->left;
			delete current;
			return dummy.left;
		}else{
			pre->right = current->left;
			delete current;
			return dummy.left;
		}
	}else {
		//find the leftmost node in the right substree;
		TreeNode *temp = current->right;
		while (temp->left){
			temp = temp->left;
		}
		int tempVal = temp->val;
		cout<<"Test current node "<<current->val<<endl;
		current->delete_node(tempVal);
		current->val = tempVal;
		return this;
	}
}
		

void TreeNode::insert(int newval){
	assert(this!=NULL);
	if (newval<val) {
		if (!left) left = new TreeNode(newval);
		else left->insert(newval);
	}else{
		if(!right) right = new TreeNode(newval);
		else right->insert(newval);
	}
}

void TreeNode::preorder_traverse(){
    if(this==NULL) return;
    
    printf("NODE %d\n", val);
    left->preorder_traverse();
    right->preorder_traverse();
}

vector<vector<string> > TreeNode::level_traverse(){
    queue<TreeNode*> bfsq;
    bfsq.push(this);
    int  n_cur_level=1;
    int  n_next_level;
    vector<vector<string> > res;
    while (!bfsq.empty()) {
        res.push_back(vector<string>());
        n_cur_level = bfsq.size();
        while (n_cur_level>0){
            TreeNode *n = bfsq.front();
            bfsq.pop();
            n_cur_level--;
            string ch;
            if(!n){
                ch = "#";
            }
            else{
				ostringstream convert;
				convert<< n->val;
				ch = convert.str();
                bfsq.push(n->left);
                bfsq.push(n->right);
            }
            res.back().push_back(ch);
            cout<<ch<<" ";
        }
        cout<<endl;
    }
    return res;
}

//function to traverse the tree
