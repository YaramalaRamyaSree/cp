/*
gfg link - https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
*/

//T.C=O(N) S.C=O(1)
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>>v;
        if(!head->next) return v;
        Node* root=head;
        while(head->next){
            head=head->next;
        }
        Node*last=head;
        while(root->data<last->data){
            int sum=root->data+last->data;
            if(sum==target){
                v.push_back({root->data,last->data});
            }
            else if(sum>target){
                last=last->prev;
                continue;
            }
            root=root->next;
        }
        return v;
    }
