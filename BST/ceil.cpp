/*
gfg link - https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1
*/

//T.C=O(H)=O(logn),S.C=O(1)
int findCeil(struct Node* root, int input) {
    int ceil_node=-1;
    while(root){
        if(root->data==input){
            ceil_node=input;
            break;
        }
        if(root->data>input){
            ceil_node=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ceil_node;
    
}
