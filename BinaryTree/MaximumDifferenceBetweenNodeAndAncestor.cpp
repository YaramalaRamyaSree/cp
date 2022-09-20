/*
GFG LINK - https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/0
*/

//T.C=O(N) S.C=O(H)
//JUST RETURN MINI VALUE TO ROOT NODE OF EVERY SUBTREE UR JOB IS DONE 
int helper(Node* root,int &ans){
    if(!root) return INT_MAX;
    if(!root->left&&!root->right) return root->data;
    int l=helper(root->left,ans);
    int r=helper(root->right,ans);
    int mini=min(l,r);
    ans=max(root->data-mini,ans);
    return min(mini,root->data);
}

int maxDiff(Node* root)
{
    int ans=INT_MIN;
    helper(root,ans);
    return ans;
}
