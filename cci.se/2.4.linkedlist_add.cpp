#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

LLNode* ll_add (LLNode *n1, LLNode *n2, int carry){
	if (!n1&&!n2&&carry==0) return NULL;

	LLNode *res = new LLNode(0);

	int val=carry;
	LLNode *nextn1(NULL), *nextn2(NULL);
	if (n1){
		val+=n1->val;
		nextn1 = n1->next;
	}
	if (n2){
		val+=n2->val;
		nextn2 = n2->next;
	}

	res->val = val%10;
	res->next = ll_add(nextn1,nextn2,val/10);
	return res;
}

int main() {
	LLNode n1(3);
	n1.next = new LLNode(1);
	n1.next->next = new LLNode(5);

	LLNode n2(8);
	n2.next = new LLNode(9);
	n2.next->next=new LLNode(4);

	LLNode *res = ll_add(&n1,&n2,0);
	res->traverse_from();
}

