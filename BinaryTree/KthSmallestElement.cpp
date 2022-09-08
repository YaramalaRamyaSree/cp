/*
gfg link - https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/0
*/

//T.C=O(N) S.C=O(1)
    void helper(Node *root,int &k,int &ans){
        if(!root ||k<0) return ;
        helper(root->left,k,ans);
        if(k==0)
            ans=root->data;
        k--;
        helper(root->right,k,ans);
    }
    int KthSmallestElement(Node *root, int K) {
        int ans=-1;
        K=K-1;
        helper(root,K,ans);
        return ans;
    }
