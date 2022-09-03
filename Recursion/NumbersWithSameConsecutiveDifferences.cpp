/*
leetcode link - https://leetcode.com/problems/numbers-with-same-consecutive-differences/
*/

//Just Recurssion and backtracking
    void helper(int x,int n,int k,int length,vector<int>&ans){
        if(length==n){
            ans.push_back(x);
            return ;
        }
        for(int i=0;i<10;i++){
            int lastDigit=x%10;
            if(abs(lastDigit-i)==k)
                helper(x*10+i,n,k,length+1,ans);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        int curr=1;
        for(int i=1;i<10;i++)
            helper(i,n,k,curr,ans);
        return ans;
    }

//Using BFS (Queue)
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        queue<pair<int,int>> q;
				for(int i=1;i<=9;i++){   
            q.push({i,1});
            while(!q.empty()){
                pair<int, int> curr=q.front();
                q.pop();
                int num=curr.first;
                int length=curr.second;
                if(length==n){
                    result.push_back(num);
                    continue;
                }
                int last_digit=num%10;
                if(k==0)
                    q.push({num*10+last_digit, length+1});
                else{
                    if(last_digit+k<10)
                        q.push({num*10+last_digit+k, length+1});
                    if(last_digit-k>=0)
                        q.push({num*10+last_digit-k, length+1});
                }
            }
        }
        return result;
    }
