/*
GFG LINK - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1 
*/

//T.C=O(N) S.C=O(H)
    void helper(Node *root,int &k,int &ans){
        if(!root ||k<0) return ;
        helper(root->right,k,ans);
        if(k==0)
            ans=root->data;
        k--;
        helper(root->left,k,ans);
    }
    int kthLargest(Node *root, int K)
    {
         int ans=-1;
        K=K-1;
        helper(root,K,ans);
        return ans;
    }
