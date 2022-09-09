/*
gfg link - https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/0
*/

//T.C=O(1) S.C=O(N)
class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       stack<int>mini;
       int getMin(){
           if(s.empty()) return -1;
           return mini.top();
       }
       
       /*returns poped element from stack*/
       int pop(){
           int t=-1;
           if(!s.empty()){
               t=s.top();
               s.pop();
               mini.pop();
           }
           return t;
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()) mini.push(x);
           else mini.push(min(x,mini.top()));
           s.push(x);
           
       }
};

//T.C=O(1) S.C=O(N)
class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       
       int getMin(){
           if(s.empty()) return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(!s.empty()){
               int t=s.top();
               if(t<minEle){
               t=minEle;
               minEle=2*minEle - s.top();
               s.pop();
               }
               else s.pop();
               return t;
           }
           return -1;
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()){
               s.push(x);
               minEle=x;
           }
           else{
            if(x>=minEle)
                s.push(x);
            else{
                  s.push(2*x-minEle);
                  minEle=x;
               }
           }
       }
