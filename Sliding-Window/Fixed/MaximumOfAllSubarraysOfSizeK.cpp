/*
gfg link - https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/0
*/
//T.C=O(N) S.C=O(K)
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int>ans;
        deque<int>q;
        int i=0,j=0;
        while(j<n){
            //remove elements which are less than arr[j],this ensures our dequeue always in descending order
            while(!q.empty()&&q.back()<arr[j])
                q.pop_back();
            q.push_back(arr[j]);
            if(j-i+1<k) j++;
            else {
                int maxi=q.front();
                ans.push_back(maxi);
                if(arr[i]==q.front())
                    q.pop_front();
                i++;j++;
            }
        }
        return ans;
    }
