ass Solution {
public:
    void recoverTree(TreeNode *root) {
        //constant space
        vector<TreeNode*> pSL;
        vector<int> SL;
        in_order(root,pSL,SL);
        
        sort(SL.begin(),SL.end());
        
        for(int i=0;i<pSL.size();i++)
            pSL[i]->val=SL[i];
    }
    
    void in_order(TreeNode *root, vector<TreeNode*> &pSortedList, vector<int> &sortedList){
        if(!root)
            return;
        in_order(root->left,pSortedList,sortedList);
        pSortedList.push_back(root);
        sortedList.push_back(root->val);
        in_order(root->right,pSortedList,sortedList);
    }
};