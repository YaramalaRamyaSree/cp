/*
gfg link - https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
*/

//T.C=O(NlogK) S.C=O(K)
    vector <int> nearlySorted(int arr[], int num, int K){
        int j=0;
        vector<int>v(num,0);
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<num;i++){
            q.push(arr[i]);
            if(q.size()>K){
                v[j++]=q.top();
                q.pop();
            }
        }
        while(!q.empty()){
            v[j++]=q.top();
                q.pop();
        }
        return  v;
    }
