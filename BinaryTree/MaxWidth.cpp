/*
leetcode link - https://leetcode.com/problems/maximum-width-of-binary-tree/
*/

//T.C=O(N),S.C=O(N)
 int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int minn=q.front().second;
            int first,last;
                for(int i=0;i<size;i++){
                    long int currid=q.front().second-minn;
                    TreeNode* node = q.front().first;
                    q.pop();
                    if(i==0) first =currid;
                    if(i==size-1) last =currid;
                    if(node->left){
                        q.push({node->left,currid*2+1});
                    }
                    if(node->right){
                        q.push({node->right,currid*2+2});
                    }
                    ans=max(ans,last-first+1);
                }
        }
        return ans;
    }
