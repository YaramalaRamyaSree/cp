/*
gfg link - https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/0
*/

int helper(Node* root,int x,int &count){
    if(!root) return 0;
    if(!root->left&&!root->right) {if(root->data==x) count++;return root->data;}
    int a=helper(root->left,x,count);
    int b=helper(root->right,x,count);
    if(a+b+root->data==x) count++;
    return a+b+root->data;
    
}
int countSubtreesWithSumX(Node* root, int X)
{
	int count=0;
	helper(root,X,count);
	return count;
}
