/*
gfg link - https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
*/

//T.C=O(N) S.C=O(1)
   string smallestWindow (string s, string p)
    {
        if(s.length()<p.length())
        return "-1";
        int m[256]={0};
        int count=0;
     //Store frequency of string p ele and maintain count of unique char in p's string.
        for(int i=0;i<p.length();i++){
            if(m[p[i]]==0)
             count++;
            m[p[i]]++;
            
        }
     //As we need to print miminum len string we maintain start index and len of min window so that we can easily find substring 
     //intiliasie two pointers i,j=0
        int i=0,j=0,start=0;
        int res=INT_MAX;
        for(int j=0;j<s.length();j++){
          //decrement for every s[i]
            m[s[j]]--;
          //decrement count only when frequency of a char in P is cancelled in s
            if(m[s[j]]==0)
            count--;
          // if count is zero we found a substring which meets our requirements but it may not be smallest
            if(count==0){
              //further minimise the len till count stays as zero 
                while(count==0){
                    if(res>j-i+1){
                       res=j-i+1;
                       start=i;}
                    m[s[i]]++; //a char not present in p will maximum reach zero on addition here.
                    if(m[s[i]]==1) count++; 
                    i++;
                }
            }
        }
        if(res==INT_MAX)
           return "-1";
        return s.substr(start,res);
    }
