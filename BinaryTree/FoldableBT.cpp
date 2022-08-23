/*
gfg link - https://practice.geeksforgeeks.org/problems/foldable-binary-tree/1
*/

bool check(Node* p,Node* q){
    if(!p && !q) return true;
    if(p&&!q || !p&&q) return false;
    return  check(p->left,q->right)&&check(p->right,q->left);
    
}
bool IsFoldable(Node* root)
{
    if(!root) return true;
    return check(root->left,root->right);
}
