/*
code studio - https://www.codingninjas.com/codestudio/problems/1062712?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
*/

//given start and end time of activity can oincide
//T.C=O(NlogN)+O(N)
#include <algorithm>
struct activity{
    int start;
    int end;
};
bool comparator(struct activity  a,struct activity  b){
    return a.end<b.end;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n=start.size();
    struct activity activities[n];
    for(int i=0;i<n;i++){
        activities[i].start=start[i];
        activities[i].end=finish[i];
    }
    sort(activities,activities+n,comparator);
    int e=activities[0].end,count=1; // we already considered intial activity so count starts at 1;
    for(int i=1;i<n;i++){
        if(activities[i].start>=e){
            count++;
            e=activities[i].end;
        }
    }
    return count;
}
