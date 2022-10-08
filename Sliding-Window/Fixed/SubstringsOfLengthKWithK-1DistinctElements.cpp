/*
gfg link - https://practice.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1
*/

    int countOfSubstrings(string S, int K) {
        int n=S.size();
        int start = 0, end = 0;
        int Count=0;
        unordered_map<int, int> um;
        while (end < n)
        {
            um[S[end]]++;
            if (end - start + 1 < K)
            {
                end++;
                continue;
            }
            if(um.size()==K-1)
                Count++;
            um[S[start]]--;
            if (um[S[start]] == 0)
                um.erase(S[start]);
            start++, end++;
        }
        return Count;
    }
