class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len(0);
        ListNode *p=head;
        while(p){
            p=p->next;
            len++;
        }
        return sortedListToBST(head,0,len-1);
        
    }
    TreeNode *sortedListToBST(ListNode *&head, int start, int end){
        if(start>end){
            return NULL; //remember we can always retern NULL to mean returning nothing
        }
        int mid=(start+end)/2;
        TreeNode *lSubTree = sortedListToBST(head, start, mid-1);
        TreeNode *parent = new TreeNode(head->val);
        parent->left=lSubTree;
        head=head->next;
        parent->right=sortedListToBST(head,mid+1,end);
        
        return parent;
    }
};