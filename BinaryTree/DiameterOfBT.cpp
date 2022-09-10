/*
gfg link - https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/0
*/

//T.C=O(N) S.C=O(H)
    int height(Node* root,int &maxi){
        if(!root) return 0;
        int lh=height(root->left,maxi);
        int rh=height(root->right,maxi);
        maxi=max(maxi,1+lh+rh);
        return 1+max(rh,lh);
    }
    int diameter(Node* root) {
        int maxi=0;
        height(root,maxi);
        return maxi;
    }
