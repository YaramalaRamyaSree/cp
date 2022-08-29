/*
gfg link - https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
*/

//T.C=O(N) S.C=O(26) or o(n)
	int search(string pat, string txt) {
	   unordered_map<char,int>m;
	   for(int i=0;i<pat.size();i++){
	       m[pat[i]]++;
	   }
	   int i=0,j=0;
	   int n=txt.size();
	   int count=m.size(),k=pat.size(),ans=0;
	   while(j<n){
	       if(m.find(txt[j])!=m.end()){
	           m[txt[j]]--;
	           if(m[txt[j]]==0)
	                count--;
	       } 
	       if(j-i+1<k) j++;
	       else if(j-i+1==k){
	           if(count==0) 
	                ans++;
	           if(m.find(txt[i])!=m.end()){
	                m[txt[i]]++;
	               if(m[txt[i]]==1) count++;
	           }
	           i++;
	           j++;
	       }
	   }
	   return ans;
	}
