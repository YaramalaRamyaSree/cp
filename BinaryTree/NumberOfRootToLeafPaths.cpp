/*
gfg link - https://practice.geeksforgeeks.org/problems/number-of-root-to-leaf-paths/0
*/
void helper(Node * root,map<int,int>&mpp,int len){
    if(!root) return ;
    len++;
    if(!root->left&&!root->right){
        mpp[len]++;
        return ;
    }
    helper(root->left,mpp,len);
    helper(root->right,mpp,len);
    len--;
}

void pathCounts(Node *root)
{
   map<int,int>mpp;
   int len=0;
   helper(root,mpp,len);
   for(auto it:mpp){
       cout<<it.first<<" "<<it.second<<" $";
   }
   return;
}
