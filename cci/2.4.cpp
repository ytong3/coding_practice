//Better solution is to use recursion.
#include <iostream>
#include "LLNode.h"

using namespace std;

LLNode *LLNode_add(LLNode* n1, LLNode* n2){
	LLNode* h1=n1;
	LLNode* h2=n2;
	if(!n1) return copyLL(LLNode* n2);
	if(!n2) return copyLL(LLNode* n1);
	
	LLNode* pRes=new LLNode(0);
	int carry=0
	while(h1->next&&h2->next){
		int val=(carry+h1->val+h2->val)%10
		carry=(h1->val+h2->val)/10;
		pRes->val=val;
		pRes->next=new LLNode;
		pRes=pRes->next;
		h1=h1->next;
		h2=h2->next;
	}

	if(h1->next==
	if(h1->next==NULL) 
		LLNode *residual=h2->next;
	else
		LLNo

LLNode* copyLL(LLNode* head){
	if(!head) return NULL;
	LLNode* res=new LLNode(head->val);
	
	LLNode* pNode=head->next;
	LLNode* pRes=res->next;
	while(pNode->next){
		pRes->next=new LLNode(pNode->val);
		pRes=pRes->next;
		pNode=pNode->next;
	}
}
		
		
