/*
leetcode link - https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
*/

//T.C=O(n) S.C=o(1)
    int minCost(string colors, vector<int>& neededTime) {
        int mn=0;
        for(int i=0;i<colors.size()-1;i++)
        {
           if(colors[i]==colors[i+1])
           {
              while(i<colors.size()-1&&colors[i+1]==colors[i] )
               {
                   if(neededTime[i]<neededTime[i+1])
                   {
                       mn+=neededTime[i];
                   }
                  else
                    {
                        mn+=neededTime[i+1];
                        swap(neededTime[i],neededTime[i+1]);

                    }
                  i++;
               } 
           }
        }
        return mn;
    }
