/*
leetcode link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
*/

//T.C=O(N),S.C=O(N)=auxilary -RECURSIVE SOLUTION 
   TreeNode* prev=NULL;
    void flatten(TreeNode* root) {
        if(root==NULL)
            return ;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
//T.C=O(N),S.C=O(N) -STACK SPACE Iterative solution
    void flatten(TreeNode* root) {
        if(!root) return ;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur=st.top();
            st.pop();
            if(cur->right){
                st.push(cur->right);
            }
            if(cur->left){
                st.push(cur->left);
            }
            if(!st.empty())
            cur->right=st.top();
            cur->left=NULL;
        }
    }
//OPTIMISED T.C=O(N),S.C=O(1)
    void flatten(TreeNode* root) {
        if(!root) return ;
        while(root!=NULL){
            if(root->left!=NULL){
                TreeNode* prev= root->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=root->right;
                root->right=root->left;
                root->left=NULL;
            }
            root=root->right;
        }
    }
