/*
leetcode link - https://leetcode.com/problems/poor-pigs/
*/

//this can even be sloved using recursion,dp 
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int x= minutesToTest/minutesToDie;
        int pigs=0;
        /*
        //this will exceed time
        while(pow(x+1,pigs)<buckets){
            pigs++;
        }
        */
        pigs=ceil(log(buckets)/log(x+1));
        return pigs;
    }
