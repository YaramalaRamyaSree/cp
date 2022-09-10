/*
gfg link - https://practice.geeksforgeeks.org/problems/sum-tree/0
*/


//T.C=O(N) S.C=O(H)
    int  helper(Node* root,bool &f){
        if(!root) return 0;
        if(!root->left&&!root->right){
            return root->data;
        } 
        if(f==0) return 0;
        int a=helper(root->left,f);
        int b=helper(root->right,f);
        if(a+b!=root->data) f=0;
        return a+b+root->data;
        
    }
    bool isSumTree(Node* root)
    {
        bool f=1;
        helper(root,f);
        return f;
        
    }
