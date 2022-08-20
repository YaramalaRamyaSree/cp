/*
leetcode link - https://leetcode.com/problems/minimum-number-of-refueling-stops/
*/

//T.C=O(nlogn) S.C=O(n)
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int miles=startFuel;
        int n=stations.size();
        priority_queue<int>q;
        int count=0;
        int i=0;
        while(miles<target){}
            while( i<n && miles>=stations[i][0]){
                q.push(stations[i][1]);
                i++;
            }
            if(q.empty()) return -1;
            miles+=q.top();
            q.pop();
            count++;
        }
        
        return count;
    }
