/*
leetcode link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/

class Solution {
public:
    TreeNode* buildTree(unordered_map<int,int>inmap,vector<int>& in,int instart,int inend, vector<int>&post,int poststart,int postend){
    if(poststart>postend||instart>inend) return NULL;
        TreeNode* root=new TreeNode(post[postend]);
    int index=inmap[post[postend]];
    int len=index-instart;
    root->left=buildTree(inmap,in,instart,index-1,post,poststart,poststart+len-1);
    root->right=buildTree(inmap,in,index+1,inend,post,poststart+len,postend-1);
    return root;
    
}

TreeNode *buildTree(vector<int>& in, vector<int>& post) {
    int n= in.size();
    unordered_map<int,int>inmap;
    for(int i=0;i<n;i++){
        inmap[in[i]]=i;
    }
    TreeNode * root=buildTree(inmap,in,0,n-1,post,0,n-1);
    return root;
}
};
