#include <iostream>
#include "linkedlist.h"


//use recursion
LLNode* ll_add(int carry, LLNode* head1, LLNode* head2){
	if(head1==NULL&&head2==NULL){
		if(carry==0) return NULL;
		return new LLNode(carry);
	}

	if(head1==NULL||head2==NULL){
		LLNode *ptmp=head1==NULL?head2:head1;
		int val=ptmp->val+carry;
		LLNode* res = new LLNode(val%10);
		res->next=ll_add(val/10, ptmp->next, NULL);
		return res;
	}

	int val=head1->val+head2->val+carry;
	LLNode* res=new LLNode(val%10);
	res->next=ll_add(val/10,head1->next,head2->next);
	return res;
}

int main(){
	LLNode *l1=new LLNode(8);
	LLNode *l2=new LLNode(4);

	l1->next=new LLNode(4);
	l1->next->next=new LLNode(5);

	l2->next=new LLNode(3);
	l2->next->next=new LLNode(5);

	LLNode *l3=ll_add(0,l1,l2);

	LLNode* ptr=l3;
	while(ptr){
		std::cout<<ptr->val<<"<-";
		ptr=ptr->next;
	}
	std::cout<<std::endl;
}



class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        return helper(l1,l2,0);
    }
    
    ListNode *helper(ListNode *l1, ListNode *l2, int carry){
        if(l1==NULL&&l2==NULL){
        		if(carry)
        			return new ListNode(carry);
            return NULL;
        }
        
        int val = carry;
        
        if(l1!=NULL)
            val+=l1->val;
        if(l2!=NULL)
            val+=l2->val;
            
        ListNode *res = new ListNode(val%10);
        res->next = helper(l1->next,l2->next, val/10);
 
        return res;
    }
};
