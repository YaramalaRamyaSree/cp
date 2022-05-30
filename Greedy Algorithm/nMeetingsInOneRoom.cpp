/*
gfg link - https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
*/

   //The sooner the meeting finishes we will have maximum meetings taking place in room so we sort the meetings according to end timings 
   //T.C=O(N)+O(NlogN)+O(N)=O(NlogN),S.c=O(N)
   struct meet{
        int start;
        int end;
    };
    bool static comparator(struct meet m1,meet m2){
        return (m1.end<m2.end);
    }
    int maxMeetings(int start[], int end[], int n)
    {
       struct meet meeting[n];
       for(int i=0;i<n;i++){
          meeting[i].start=start[i];
          meeting[i].end=end[i];
       }
       sort(meeting,meeting+n,comparator);
       int count=1;
       int e=meeting[0].end;
       for(int i=1;i<n;i++){
           if(meeting[i].start>e)
           {
               count++;
               e=meeting[i].end;
           }
       }
       return count;
    }
