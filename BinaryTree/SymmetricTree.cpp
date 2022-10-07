/*
gfg link - https://practice.geeksforgeeks.org/problems/symmetric-tree/1
*/

    bool helper(Node* r1,Node*r2){
        if(r1==NULL ||r2==NULL) return r1==r2;
        return r1->data==r2->data&&helper(r1->left,r2->right)&&helper(r1->right,r2->left);
    }
    bool isSymmetric(struct Node* root)
    {
        if(!root) return 1;
	    return helper(root->left,root->right);
    }
