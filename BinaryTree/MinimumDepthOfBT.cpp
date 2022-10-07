/*
gfg  link - https://practice.geeksforgeeks.org/problems/minimum-depth-of-a-binary-tree/1
*/

//T.C=O(N) S.C=O(n)

    int minDepth(Node *root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return 1;
        if(!root->left) return 1+minDepth(root->right);
        else if(!root->right) return 1+minDepth(root->left);
        else return 1+min(minDepth(root->left),minDepth(root->right));
    }
    
    //Second method
    bool f=0;
    int minDepth(TreeNode* root) {
        if(!root) return f==0?0:1e5;
        if(!root->left&&!root->right) return 1;
        f=1;
        int lh=minDepth(root->left);
        int rh=minDepth(root->right);
        return 1+min(lh,rh);
    }
