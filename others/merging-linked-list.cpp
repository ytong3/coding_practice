#include <iostream>
#include "linkedlist.h"

using namespace std;

ListNode *merge_node (ListNode *l1, ListNode *l2){
    if (!l1||!l2) return NULL;

    ListNode *p1 = l1, *p2 = l2;
    size_t len1(0), len2(0);
    while (p1->next){
        p1=p1->next;
        len1++;
    }
    while (p2->next){
        p2=p2->next;
        len2++;
    }

    if (p1!=p2) return NULL;

    ListNode *pLong,*pShort;
    if (len1>len2){
        pLong = l1;
        pShort = l2;
    }else{
        pLong = l2;
        pShort= l1;
    }

    size_t step = len1-len2;
    while (step){
        pLong=pLong->next;
        --step;
    }

    while (pLong&&pShort){
        if (pLong==pShort)
            return pLong;
        pLong=pLong->next;
        pShort=pShort->next;
    }
    return NULL;
}

int main(){
    ListNode l1(1);
    ListNode *p(&l1);
    p = p->next = new ListNode(3);
    p = p->next = new ListNode(5);
    p = p->next = new ListNode(7);

    ListNode l2(2);
    p = &l2;
    //p = p->next = new ListNode(4);
    p->next = l1.next->next;
    
    l1.traverse_from();
    l2.traverse_from();
    
    p = merge_node(&l1,&l2);
    if(p){
        cout<<p->val<<endl;
    }
}
        

    
        
