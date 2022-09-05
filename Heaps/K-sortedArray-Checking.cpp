/*
gfg link - https://practice.geeksforgeeks.org/problems/k-sorted-array1610/1
*/

//T.C=O(NlogN) S.c=o(N)
    string isKSortedArray(int arr[], int n, int k)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int j=0;
        for(int i=0;i<n;i++){
            q.push({arr[i],i});
        }
        while(!q.empty()){
            int diff=(q.top().second-j);
            q.pop();j++;
            if(abs(diff)<=k)
                continue;
            else return "No";
        }
        return "Yes";
    }
