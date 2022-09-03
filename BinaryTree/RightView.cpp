/*
gfg link - https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
*/

//T.C=O(N) S.C=O(H)
   void helper(Node* root,int level,vector<int>&ans){
        if(!root) return ;
        if(ans.size()==level) 
            ans.push_back(root->data);
        helper(root->right,level+1,ans);
        helper(root->left,level+1,ans);
    }
    vector<int> rightView(Node *root)
    {
       if(!root) return {};
       vector<int>ans;
       helper(root,0,ans);
       return ans;
    }
