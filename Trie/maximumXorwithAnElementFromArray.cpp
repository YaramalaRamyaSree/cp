/*
leetcode link - https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
*/

    struct Node{
        Node *links[2];
        bool containsKey(int bit){
            return links[bit]!=NULL;
        }
        void put(int bit,Node* node){
            links[bit]=node;
        }
        Node* get(int bit){
            return links[bit];
        }
    };
    class Trie{
        private: Node* root;
        public: 
        Trie(){
            root=new Node();
        }
        void insert(int num){
            Node* node=root;
            for(int i=31;i>=0;i--){
                int bit = (num>>i)&1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }
                node=node->get(bit);
            }
        }
        int getmax(int num){
            Node* node=root;
            int maxnum=0;
            for(int i=31;i>=0;i--){
                int bit=(num>>i)&1;
                if(node->containsKey(1-bit)){
                    maxnum=maxnum | (1<<i);
                    node=node->get(1-bit);
                }
                else 
                node=node->get(bit);
            }
            return maxnum;
        }
    };
    class Solution {
    public:
        vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
            //T.C=O(NlogN)
            sort(nums.begin(),nums.end());
            vector<pair<int,pair<int,int>>>oQ;
            for(int i=0;i<queries.size();i++){
                oQ.push_back({queries[i][1],{queries[i][0],i}});
            } 
            //T.C=O(qlogq)
            sort(oQ.begin(),oQ.end());
            int ind=0,i=0;
            int n=nums.size();
            vector<int>ans(queries.size());
            Trie trie;
            //T.C=O(Q*32+N*32)
           for(int i=0;i<queries.size();i++){
                int ai=oQ[i].first;
                int xi=oQ[i].second.first;
                int index=oQ[i].second.second;
                while(ind<n && nums[ind]<=ai){
                    trie.insert(nums[ind++]);
                }
                if(ind==0) ans[index]=-1;
               else ans[index]=trie.getmax(xi);

            }
            return ans;
        }
    };
