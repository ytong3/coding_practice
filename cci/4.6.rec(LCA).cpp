//note that this recursion function does not always return 
//basic idea: if the e1 and e2 are on the each side of a node, then the node is the LCA of the e1 and e2

NodeType* findLCA(NodeType* root, NodeType* e1, NodeType* e2)
{
    if(root == NULL) return NULL;

    if(root->left== e1 || root->right == e2 ||root->left==e2||root->right==e1)
	return root;

    NodeType* lRet = findLCA(root->l, e1, e2);
    NodeType* rRet = findLCA(root->r, e1, e2);
    if(lRet && rRet) return root;
    if(!lRet) return rRet;
    return lRet;
}
