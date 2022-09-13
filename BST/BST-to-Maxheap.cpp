/*
gfg link  - https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1
*/

class Solution{
  public:
    
    vector<int>arr;
  
    void inorder(Node* root){
        if(!root) return ;
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }
    int i=0;
    void postorder(Node* root){
        if(!root) return ;
        postorder(root->left);
        postorder(root->right);
        root->data=arr[i++];
    }
  
    void convertToMaxHeapUtil(Node* root)
    {
        inorder(root);
        postorder(root);
    }    
};
