/*
gfg link - https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/0
*/

class Solution
{
    public:
    //Function to merge k sorted arrays.
    typedef pair<int,int> pii;
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans;
        priority_queue<pii,vector<pii>,greater<pii>>q;
        for(int i=0;i<arr.size();i++){
            q.push({arr[i][0],i});
        }
        vector<int>curr(arr.size(),0);
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            ans.push_back(it.first);
            int row =it.second;
            curr[row]++;
            if(curr[row]<arr.size()){
                q.push({arr[row][curr[row]],row});
            }
        }
        return ans;
    }
};
