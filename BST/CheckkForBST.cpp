/*
gfg link - https://practice.geeksforgeeks.org/problems/check-for-bst/1
*/

    bool helper(Node* root,int minval ,int maxval){
        if(!root) return 1;
        if(root->data>=maxval || root->data <=minval) return 0;
        return helper(root->left,minval,root->data)&& helper(root->right,root->data,maxval);
    
    }
    bool isBST(Node* root) 
    {
        return helper(root,INT_MIN,INT_MAX);
    }
