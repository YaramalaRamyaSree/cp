/*
gfg link - https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/0
*/

class BSTiterator{
    bool isReverse;
    stack<Node*>s;
    public:
    BSTiterator(bool val,Node* root){
        isReverse=val;
        pushAll(root);
    }
    bool hasNext(){
        return !s.empty();
    }
    int  next(){
        Node * top_ele=s.top();
        s.pop();
        if(!isReverse)pushAll(top_ele->right);
        else pushAll(top_ele->left);
        return top_ele->data;
    }
    void pushAll(Node*root){
        if(!root) return ;
        while(root){
            s.push(root);
            if(isReverse){
                root=root->right;
            }
            else root=root->left;
        }
    }
};
class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    int isPairPresent(struct Node *root, int target)
    {
      BSTiterator l(false,root);
      BSTiterator r(true,root);
      int i=l.next();
      int j=r.next();
      while(i<j){
          if(i+j==target) return 1;
          if(i+j<target) i=l.next();
          else j=r.next();
      }
      return 0;
    }
};
