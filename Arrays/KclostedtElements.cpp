/*
gfg link - https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1
*/

    static bool cmp(pair<int,int>a,pair<int,int>b){
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        vector<pair<int,int>>q;
        for(int i=n-1;i>=0;i--){ //o(n)
            q.push_back({abs(x-arr[i]),arr[i]});
        }
        sort(q.begin(),q.end(),cmp);//nlogn
        vector<int>ans;
        int i=0;
        while(i<n && ans.size()<k){//o(k)
            if(q[i].second!=x)
                ans.push_back(q[i].second);
            i++;
        }
        return ans;
    }
