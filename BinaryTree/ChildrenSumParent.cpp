/*
gfg link - https://practice.geeksforgeeks.org/problems/children-sum-parent/0
*/

//T.C=O(N) S.C=O(H)
    int isSumProperty(Node *root)
    {
        if(!root|| (!root->left&&!root->right))
            return 1;
        int sum=0;
        if(root->left)
            sum+=root->left->data;
        if(root->right)
            sum+=root->right->data;
        if(sum==root->data&&isSumProperty(root->left)&&isSumProperty(root->right))
            return 1;
        return 0;
    }
