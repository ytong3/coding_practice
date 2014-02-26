#include <iostream>
#include <string>
#include "linkedlist.h"
#include <unordered_map>
#include <set>
using namespace std;

void remove_dups_from_ll(LLNode *head){
	set<int> check;
	LLNode dummy(-1);
	dummy.next=head;
	LLNode *pre(&dummy);	
	while(head){
		if(check.count(head->val)){
			pre->next=head->next;
			//head = pre;
		}
		else{
			check.insert(head->val);		
			pre=head;//do not forget to update the pre
		}
		//head=pre->next;
		head=head->next;
	}
}

//this is a version that emulate the array version of removing dups.
void remove_dups_from_ll_wo_hash(LLNode *head){
	LLNode dummy(-1);
	dummy.next=head;
	LLNode *front(head);
	LLNode *back(head);
	LLNode *preb(&dummy);
	
	while(back){
		int val = back->val;
		LLNode *p(head);
		while(p!=front) {
			if (p->val==val)
				break;
			p=p->next;
		}

		if (p==front){
			if (front->val==val){
				preb=back;
				back=back->next;
			}else{
				//append back to front;
				preb->next=back->next;
				back->next=p->next;
				p->next=back;
				back=preb->next;
				front=front->next;
			}
		}else{
			preb=back;
			back=back->next;
		}
	}
	front->next=NULL;//need to put an end to the resulting linked list. anything after front are garbages.
}

void remove_dups_from_ll_wo_hash1(LLNode *head){
	if (!head) return;
	LLNode *previous = head;
	LLNode *current=previous->next;

	while (current) {
		LLNode *runner=head;
		while (runner!=current){
			if(runner->val==current->val){
				previous->next=current->next;
				current=current->next;
				break;
			}
			runner=runner->next;
		}
		if (runner==current){//no dups of current
			previous=current;
			current=current->next;
		}
	}
}
		
int main(){
	LLNode head(2);
	head.next=new LLNode(3);
	head.next->next=new LLNode(2);
	head.next->next->next=new LLNode(3);
	head.next->next->next->next=new LLNode(4);

	head.traverse_from();

	remove_dups_from_ll_wo_hash1(&head);
	//remove_dups_from_ll_wo_hash(&head);
	head.traverse_from();
	
}	