/*
gfg link - https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/0
*/

//T.C=O(N) S.C=O(H)
    bool helper(struct Node *root,vector<int>&ans,int target){
        if(!root) return false;
        if(root->data==target) return true;
        bool left=helper(root->left,ans,target);
        bool right=helper(root->right,ans,target);
        if(left | right){
            ans.push_back(root->data);
            return true;}
        return false;
        
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
         vector<int>ans;
         helper(root,ans,target);
         return ans;
    }
