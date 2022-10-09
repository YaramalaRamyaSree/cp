/*
coding ninjas-https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723
*/

void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;
    int child=0;
    if(root->left) child+=root->left->data;
    if(root->right) child+=root->right->data;
    if(child>=root->data)root->data=child;
    else
    {
        root->left->data=root->data;
        root->right->data=root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int sum=0;
    if(root->left) sum+=root->left->data;
    if(root->right) sum+=root->right->data;
    if(root->left||root->right) root->data=sum;
    return ;
}  
