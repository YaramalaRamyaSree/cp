/*
leetcode link - https://leetcode.com/problems/palindrome-partitioning/
*/

    //T.C= each time in strng len n we can have  at max n-1 partitions and we can pick or not pick partition every time so 2 chnaces O( (2^n) *k*(n/2) ) 
    //k is avg len we insert into result every time and n/2 is checking each string is palindrome or not 
    //S.C=for storing result O(k*x) k len x vectors on avg 
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(0,s, currentList,result);
        return result;
    }

    void dfs( int ind,string &s, vector<string>&currentList, vector<vector<string>> &result) {
        if (ind == s.length()) 
        {
            result.push_back(currentList);
            return;
        }
        for (int i = ind; i < s.length(); i++) {
            
            if (isPalindrome(s, ind, i)) {
                currentList.push_back(s.substr(ind, i-ind + 1));
                dfs(i + 1, s, currentList, result);
                currentList.pop_back();
            }
            
        }
    }

    bool isPalindrome(string &s, int low, int high) {
        while (low < high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
