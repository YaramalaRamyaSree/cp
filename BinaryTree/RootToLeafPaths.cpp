/*
gfg link - https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1
*/

 void helper(Node*root,vector<int>temp,vector<vector<int>>&ans){
     if(!root)return ;
     temp.push_back(root->data);
     if(!root->left&&!root->right){
         ans.push_back(temp);
         temp.pop_back();
         return ;
     }
     helper(root->left,temp,ans);
     helper(root->right,temp,ans);
     temp.pop_back();
     return;
 }
vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>>ans;
    vector<int>temp;
    helper(root,temp,ans);
    return ans;
}
