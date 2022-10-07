/*
gfg link - https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
*/

//T.C=O(N) S.C=O(H)
    //Function to return maximum path sum from any node in a tree.
    int helper(Node* root,int&maxi){
        if(!root) return 0;
        int l=max(0,helper(root->left,maxi));
        int r=max(0,helper(root->right,maxi));
        maxi=max(maxi,root->data+l+r);
        return root->data+max(l,r);
    }
    int findMaxSum(Node* root)
    {
        int maxi=INT_MIN;
        helper(root,maxi);
        return maxi;
    }
