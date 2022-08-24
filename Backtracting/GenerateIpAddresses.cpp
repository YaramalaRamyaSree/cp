/*
gfg link - https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1
*/

  void helper(int i,string s,int dots,string curr,vector<string>&ans){
      if(dots<0 || dots > s.size()-i) 
        return ;
      if(i==s.size()){
          if(dots>0) 
            return ;
          curr.pop_back();
          ans.push_back(curr);
          return ;
      }
      string segment="";
      for(int k=i;k<i+3&&k<s.size();k++){
          segment+=s[k];
          if(segment.size()>1 and segment[0]=='0')
          return ;
          if(stoi(segment)>255) return;
          helper(k+1,s,dots-1,curr+segment+".",ans);
      }
          return;
  }
    vector<string> genIp(string &s) {
        if(s.size()>12) return {};
        vector<string>ans;
        helper(0,s,4,"",ans);
        return ans;
    }
