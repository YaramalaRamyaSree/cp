/*
gfg link - https://practice.geeksforgeeks.org/problems/largest-bst/1
*/

//T.C=O(N) S.C=O(H)
class  nodeinfo{
     public:
        int minval;
        int maxval;
        int maxsize;
        nodeinfo(int minval,int maxval,int maxsize){
            this->minval=minval;
            this->maxval=maxval;
            this->maxsize=maxsize;
        }
};
class Solution{
    public:

    nodeinfo helper(Node* root){
        if(!root){
            return nodeinfo(1000001,0,0);
        }
        auto l=helper(root->left);
        auto r=helper(root->right);
        if((l.maxval<(root->data))&&((root->data)<r.minval)){
            return nodeinfo(min(l.minval,root->data),max(root->data,r.maxval),1+l.maxsize+r.maxsize);
        }
        return nodeinfo(0,1000001,max(l.maxsize,r.maxsize));
    }
    int largestBst(Node *root)
    {
    	auto s=helper(root);
    	return s.maxsize;
    }
};
