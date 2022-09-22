/*
gfg link - https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
*/

//T.C=O(N) S.C=O(N)
    bool ispar(string x)
    {
        stack<char>s;
        for(auto i:x)
        {   
            if(i=='('||i=='['||i=='{')
              s.push(i);
            else if(s.empty())
              return false;
            else if(i==')'&&s.top()=='(')
              s.pop();
            else if(i==']'&&s.top()=='[')
              s.pop();
            else if(i=='}'&&s.top()=='{')
              s.pop();
            else
              return false;
            
        }
        if(!s.empty()) return false;
        return true;
    }

//T.C=O(N^2) S.C=O(1)

    bool isValid(string s) {
        int top=-1;
        unordered_map<char,char>m;
        m[')']='(';
        m['}']='{';
        m[']']='[';
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end())
                top=i;
            else{
                if(top==-1 || m[s[i]]!=s[top])
                    return 0;
                top=find_top(s,top-1,m);
            }
        }
        return top==-1;
    }
    
    int find_top(string s,int index,unordered_map<char,char>m){
        int right=0;
        while(index>=0){
            if(m.find(s[index])!=m.end())
                right++;
            else right--;
            if(right<0)return index;
            index--;
        }
        return -1;
    }
