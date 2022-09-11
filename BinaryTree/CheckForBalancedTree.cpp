/*
gfg link  - https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/0
*/

//T.C=O(N) S.C=O(H)

    int helper(Node * root){
        if(!root) return 0;
        int lh=helper(root->left);
        if(lh==-1) return -1;
        int rh=helper(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+(max(lh,rh));
    }
    bool isBalanced(Node *root)
    {
        return helper(root)!=-1;
    }
