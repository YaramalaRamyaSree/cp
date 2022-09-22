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
