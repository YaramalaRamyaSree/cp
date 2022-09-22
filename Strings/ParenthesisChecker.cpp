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
