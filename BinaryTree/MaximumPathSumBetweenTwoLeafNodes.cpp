/*
GFG LINK - https://practice.geeksforgeeks.org/problems/maximum-path-sum/1
*/

//T.C=O(N) S.C=O(H)
    int helper(Node*root,int &maxi){
        if(!root) return INT_MIN;
        if(!root->left&&!root->right) return root->data;
        int lsum=helper(root->left,maxi);
        int rsum=helper(root->right,maxi);
        if(lsum!=INT_MIN&&rsum!=INT_MIN)maxi=max(maxi,lsum+rsum+root->data);
        return root->data+max(lsum,rsum);
        
    }
    int maxPathSum(Node* root)
    {
        int maxi=INT_MIN;
        int temp=helper(root,maxi);
        if(root->left == NULL || root->right == NULL) 
            return max(temp,maxi);
        return maxi;
    }
