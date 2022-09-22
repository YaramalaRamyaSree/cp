/*
gfg link - https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1
*/


//T.C=O(2^N * N) S.C=O(2*N*X)
    void helper(int open,int close,string s,vector<string>&ans){
        if(open==0&&close==0)   
            {
                ans.push_back(s);
                return;
            }
        if(open>close) return;
        if(open>0){
            helper(open-1,close,s+'(',ans);
        }
        if(close>0){
            if(open<close)
                helper(open,close-1,s+')',ans);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        string s="";
        vector<string>ans;
        helper(n,n,s,ans);
        return ans;
    }
