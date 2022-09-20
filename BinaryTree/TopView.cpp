/*
gfg link - https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/0
*/

//T.C=O(N) S.C=O(N)
   vector<int> topView(Node *root)
    {
        map<int,int>mpp;
        vector<int>ans;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            Node * temp=q.front().first;
            int line=q.front().second;
            q.pop();
            if(mpp.find(line)==mpp.end())
                mpp[line]=temp->data;
            if(temp->left)
                q.push({temp->left,line-1});
            if(temp->right)
                q.push({temp->right,line+1});
        }
        for(auto it:mpp)
            ans.push_back(it.second);
        return ans;
    }

};
