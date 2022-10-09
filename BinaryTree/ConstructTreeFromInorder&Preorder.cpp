/*
gfg link - https://practice.geeksforgeeks.org/problems/construct-tree-1/1
*/


class Solution{
    public:
    
    Node* buildTree(int in[],int pre[], int n)
    {
       unordered_map<int,int>inmap;
       for(int i=0;i<n;i++){
           inmap[in[i]]=i;
       }
       Node * root=buildTree(inmap,in,0,n-1,pre,0,n-1);
       return root;
    }
    
    Node* buildTree(unordered_map<int,int>&inmap,int in[],int instart,int inend,int pre[],int prestart,int preend){
        if(prestart>preend||instart>inend) return NULL;
        Node *root=new Node(pre[prestart]);
        int index=inmap[pre[prestart]];
        int len=index-instart;
        root->left=buildTree(inmap,in,instart,index-1,pre,prestart+1,prestart+len);
        root->right=buildTree(inmap,in,index+1,inend,pre,prestart+len+1,preend);
        return root;
    }
    
};
