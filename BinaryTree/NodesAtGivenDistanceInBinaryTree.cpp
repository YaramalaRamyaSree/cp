/*
gfg link - https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
*/

class Solution
{
private:
    unordered_map<Node*,Node*>parent;
    Node* node;
public:

    void makeParents(Node* root,int target){
        queue<Node *>q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            if(temp->data==target) node=temp;
            q.pop();
            if(temp->left)
                {
                    parent[temp->left]=temp;
                    q.push(temp->left);
                }
            if(temp->right)
                {
                    parent[temp->right]=temp;
                    q.push(temp->right);
                }
        }
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        makeParents(root,target);
        unordered_map<Node*,bool>vis;
        queue<Node*>q;
        q.push(node);
        vis[node]=true;
        vector<int>res;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level==k) break;
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left&&!vis[temp->left]){
                    vis[temp->left]=true;
                    q.push(temp->left);
                }
                if(temp->right&&!vis[temp->right]){
                    vis[temp->right]=true;
                    q.push(temp->right);
                }
                if(parent[temp]&&!vis[parent[temp]]){
                    vis[parent[temp]]=true;
                    q.push(parent[temp]);
                }
            }
            level++;
        }
        while(!q.empty()){
            res.push_back(q.front()->data);
            q.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};
