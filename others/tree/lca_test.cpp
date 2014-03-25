#include<iostream>
#include "treenode.h"

using namespace std;


TreeNode *findLCA(TreeNode *root,int n1, int n2){
    if (!root) return NULL;
    
    if(root->val==n1||root->val==n2) return root;
    
    TreeNode *l = findLCA(root->left,n1,n2);
    if (l&&l->val!=n1&&l->val!=n2) return l;
    TreeNode *r = findLCA(root->right,n1,n2);
    if (l==NULL) return r;
    if (r==NULL) return l;
    return root;
}

int main(){
    TreeNode root(0);
    root.insert(-2);
    root.insert(4);
    root.insert(5);
    root.insert(6);
    root.insert(7);
    root.insert(8);
	root.insert(100);
	root.insert(40);

	for(int i=12;i<20;i++)
		root.insert(i);
	
    
	cout<<"Finding LCA of 19 and 40, which is:\n";
    TreeNode* res=findLCA(&root,19,40);
    cout<<res->val<<endl;
	
	cout<<"Finding LCA of 5 and 6, which is:\n";
    res=findLCA(&root,5,6);
    cout<<res->val<<endl;

	cout<<"Current tree is"<<endl;
	root.level_traverse();
	
	root.delete_node(0);
	
	cout<<"After deleting 0, Current tree is"<<endl;
	root.level_traverse();
    
    
}