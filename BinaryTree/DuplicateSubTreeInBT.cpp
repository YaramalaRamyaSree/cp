/*
gfg link - https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/0
*/

    unordered_set<string>mp;
    
    bool isleaf(Node* root){
        return (!root->left&&!root->right)?true:false;
    }
    
    string helper(Node* root,bool &flag){
        if(!root) return "$";
        if(isleaf(root))
        {
            return to_string(root->data)+" ";
        }
        string s="";
        s+=helper(root->left,flag);
        s+=to_string(root->data);
        s+=helper(root->right,flag);
        if(mp.find(s)!=mp.end()){
            flag=true;
        }
        mp.insert(s);
        return s;
    }
    
    int dupSub(Node *root) {
         bool flag=false;
         helper(root,flag);
         return flag;
    }
