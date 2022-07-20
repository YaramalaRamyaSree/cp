/*
leetcode link - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
*/

   //T.C=O(NlogN),S.C=O(N)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>todo;    // node,line,level 
        map<int,map<int,multiset<int>>>nodes;        //line,level,set of nodes
        todo.push({root,{0,0}});
        while(!todo.empty()){
            auto p=todo.front();
            todo.pop();
            TreeNode*node= p.first;
            int line=p.second.first;
            int level=p.second.second;
            nodes[line][level].insert(node->val);
            if(node->left)
                todo.push({node->left,{line-1,level+1}});
            if(node->right)
                todo.push({node->right,{line+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto v:nodes){
            vector<int>col;
            for(auto l:v.second){
                col.insert(col.end(),l.second.begin(),l.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
