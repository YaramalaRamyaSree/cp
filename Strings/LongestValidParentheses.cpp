/*
gfg link - https://practice.geeksforgeeks.org/problems/longest-valid-parentheses5657/1
*/

//T.C=O(N) S.C=O(N)

    int findMaxLen(string s) {
        stack<int>st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                st.push(i);
            else{
                st.pop();
                if(st.empty())   
                    st.push(i);
                else
                   maxi=max(i-st.top(),maxi);
            }
        }
        return maxi;
    }

//T.C=O(N) S.C=O(1)

public:
    int maxLength(string s){
        int open = 0 , close = 0;
        int maxi = 0;
        
        // 0 -- n
        for(int i=0;i<s.length();i++){
            char c = s[i];
            if(c == '('){
                open++;
            }
            else{
                close++;
            }
            
            if(open == close){
                int len = open + close;
                maxi = max(maxi,len);
            }
            else if(close > open ){
                open = close = 0;
            }
        }
         open = close = 0;
        // n -- 0
        for(int i= s.length()-1; i>=0 ;i--){
            char c = s[i];
            if(c == '('){
                open++;
            }
            else{
                close++;
            }
            
            if(open == close){
                int len = open + close;
                maxi = max(maxi,len);
            }
            else if(open > close ){
                open = close = 0;
            }
        }
        return maxi;
    }
