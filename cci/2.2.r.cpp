#include <iostream>
#include "LLNodes.h"

using namespace std;
//if you need interrupt recursion (reap results during the recursion), consider use this form, i.e. let the recurring function have access to an external variable.
int reverse_order(LLNode* ptr, int n, LLNode *ans){
	if(ptr->next==NULL) return 0;
	int res=1+reverse_order(ptr->next, n, ans);
	if(res==n) ans=ptr;
	return res;
}

/*
//this function will return NULL if the node examined is less than N spots apart from the last of the list and otherwisely the point of extractly the Nth node from the end of the list.
LLNode* reverse_order(LLNode* ptr, int n, int found){
	if(!head){
		found=1;
		return NULL;
	}

	LLNode* res=reverse_order(LLNode* ptr, int n, int found){
	if(n=found){
		res=ptr;
	}
	found++;
	return res;
}
	
