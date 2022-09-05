/*
gfg link - https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
*/

    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<n;i++){
            q.push(arr[i]);
            if(q.size()>k) q.pop();
            if(q.size()<k)
                ans.push_back(-1);
            else    
                ans.push_back(q.top());
        }
        return ans;
    }
