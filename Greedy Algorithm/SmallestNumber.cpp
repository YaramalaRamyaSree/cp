/*
gfg link - https://practice.geeksforgeeks.org/problems/smallest-number-with-sum-of-digits-as-n-and-divisible-by-10n4032/1
*/
//T.C=O(N) S.C=O(N)
	string digitsNum(int N)
	{
	    string s="";
	    int c=N;
	    while(c>9){
	        s+="9";
	        c-=9;
	    }
	    s+=to_string(c);
	    reverse(s.begin(),s.end());
	    for(int i=0;i<N;i++){
	        s+="0";
	    }
	    return s;
	}
