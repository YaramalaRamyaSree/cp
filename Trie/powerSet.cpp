/*
gfg link - https://practice.geeksforgeeks.org/problems/power-set4302/1#
*/

   // T.C=O((2^N)*N),S.C=O(2^N)-BIT MANIPULATION 
                  vector<string> AllPossibleStrings(string s){
                            int n =s.length();
                            vector<string>v;
                            string subsequence;
                            for(int i=0;i<=(1<<n)-1;i++){
                                subsequence="";
                                for(int j=0;j<n;j++){
                                    if(i&(1<<j)) subsequence+=s[j];
                                }
                                if(subsequence.length()>0)v.push_back(subsequence);

                            }
                            sort(v.begin(),v.end());
                            return v;
                }
   
   //T.C=O(2^N),S.C=O(2^N)=RECURSION
               	void subsequence(int i,string s,string f,vector<string>&v){
            	       if(i==s.length()){
            	           if(f.length()>0)v.push_back(f);
            	           return ;
            	       }
            	       f=f+s[i];
            	       subsequence(i+1,s,f,v);
            	       f.pop_back();
            	       subsequence(i+1,s,f,v);
            	}
            		vector<string> AllPossibleStrings(string s){
            		    vector<string>v;
            		    subsequence(0,s,"",v);
            		    sort(v.begin(),v.end());
            		    return v;
            		}
