/*
gfg link - https://practice.geeksforgeeks.org/problems/license-key-formatting/1
*/

//T.C=(N) S.C=O(N)
    string ReFormatString(string S, int K){
    	string s="";
    	int i;
    	int count=0,cnt=0;
        for(i=0;i<S.size();i++){
            if(S[i]=='-'){
              count++;}
        }
        int rem=(S.size()-count)%K;
        int j;
        if(rem!=0){
        for(j=0;rem>0;j++){
            if(S[j]=='-') continue;
            if(isalpha(S[j])) 
                    S[j]=toupper(S[j]);
            s+=S[j];
            rem--;
        }
        s+="-";
        i=j;
        }
        else i=0;
        
        int len=0;
        for(;i<S.size();i++){
            if(S[i]=='-') continue;
            if(len<K){
                if(isalpha(S[i])) 
                    S[i]=toupper(S[i]);
                s+=S[i];
                len++;}
            if(len==K){
                len=0;
                s+="-";
            }
        }
        if(s[s.size()-1]=='-') return s.substr(0,s.size()-1);
        return s;
    }
