/*
gfg link - https://practice.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1
*/

//T.C=O(X+Y) S.C=O(1)
    string findSum(string X, string Y) {
       string ans="";
       reverse(X.begin(),X.end());
       reverse(Y.begin(),Y.end());
       long long i=0,j=0;
       long long sum=0;
       long long carry=0;
       while(i<X.length() || j<Y.length())
       {
           sum=carry+(i<X.length()?(X[i]-'0'):0)+(j<Y.length()?(Y[j]-'0'):0);
           ans+=((sum%10)+'0');
           carry=sum/10;
           i++;
           j++;
       }
       if(carry!=0)
       {
           ans+=(carry+'0');
       }
       reverse(ans.begin(),ans.end());
      //Removing leading zeroes.
       int k=0;
       for(;k<ans.length();k++)
       {
           if(ans[k]!='0')
               break;
       }
       if(k==ans.length())
           return "0";
       return ans.substr(k);    
   }
