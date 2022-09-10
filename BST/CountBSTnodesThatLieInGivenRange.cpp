/*
gfg link - https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/0
*/


    int getCount(Node *root, int l, int h)
    {
      int count=0;
      if(root==NULL)
      return 0;
      if(l<=root->data&& root->data<=h)
      count+=1;
      count+=getCount(root->left,l,h);
      count+=getCount(root->right,l,h);
      return count;
    }
