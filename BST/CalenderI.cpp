/*
leetcode link - https://leetcode.com/problems/my-calendar-i/
*/

//uses set which indeed implemented with balanced bst 
//T.C=O(nlogn) S.C=o(n)
class MyCalendar {
public:
    set<pair<int,int>>s;
    MyCalendar() {
    }
    
    bool book(int start, int end) {
      //if evnt is booked we can consider event to happen
        if(s.size()==0){
            s.insert({start,end});
            return 1;              
        }
      //find upperbpund (>) event to given event 
        auto it=s.upper_bound({start,end});
      //if upper_bound  iterator points to begin  we need to check only end insert or not 
        if(it==s.begin()){
            if(end<=(*it).first){
                s.insert({start,end});
                return 1;
            }
            else
                return 0;
        }
      
      //it may haven upper_bound may not be present in set  we just need to check start with it--.
      //if upper_bound is not s.end() then we need to check both end with it  and start with it--.
      
        if(it!=s.end()){
            if(end>(*it).first)
                return 0;
        }
      
        it--;
        if(start>=(*it).second){
            s.insert({start,end});
            return 1;
        }
        else return 0;
    }
};
