#include <iostream>
#include "linkedlist.h"
#include <map>

//use a map to keep track of the existed element if extra buffer is allowed.
//do not be afraid to use heavy data structures such as map.
//trade space for time is sometimes a tactic.

LLNode* remove_duplicates(LLNode* head){
	if(LLNode==NULL) return LLNode;
	map<int, int> table;
	table.clear();
	
	LLNode* pnode=head;
	LLNode* pnext=pnode->next;
	while(pnode->next!=NULL){
		if(table.find(pnode->next->val)!=table.end()){
			pnode->next=pnext->next;//delete 
		}
		else{
			pnode=pnode->next;
			pnext=pnode->next;
		}
	}
}

//O(N^2) use two pointers. Maintain a invariance area and take in new element while keeping the invariance and expanding the invariant area.
LLNode* remove_duplicates_2(LLNode* head){
	if(
		
