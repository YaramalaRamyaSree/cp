/*
gfg link  -  https://practice.geeksforgeeks.org/problems/leaf-at-same-level/0
*/


//T.C=O(N)
    void helper(Node *root, int level,set<int>&s){
        if(!root) return;
        if(!root->left&&!root->right)
        {
            s.insert(level);
        }
        helper(root->left,level+1,s);
        helper(root->right,level+1,s); 
        return;
    }
    
    bool check(Node *root)
    {
        set<int>s;
        helper(root,0,s);
        if(s.size()==1)
             return 1;
        return 0;
    }
