/*
leetcode  link - https://leetcode.com/problems/reduce-array-size-to-the-half/
*/

//Its Greedy pick.
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        priority_queue<pair<int,int>>q;
        for(auto i:m){
            q.push({i.second,i.first});
        }
        int ele=0;
        int count=0;
        while(true){
            ele+=q.top().first;
            count++;
            q.pop();
            if(arr.size()-ele<=(arr.size()/2))
                break;
        }
        return count;
    }
