/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //get the length first
        if(!head) return NULL;
        if(k==0) return head;
        
        ListNode* tail=head;
        ListNode* ptr1=head;
        ListNode* ptr2=head;
        int len(1);
        
        while(tail->next){
            tail=tail->next;
            len++;
        }
        
        if(k%len==0) return head;
        
        int headIdx=len-k%len-1;
        
        ptr2=ptr1->next;
        while(headIdx){
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            headIdx--;
        }
        
        
        ptr1->next=NULL;
        tail->next=head;
        return ptr2;
        
    }
        
};

/*
Note: pay attention to the special case that k is 
*/
