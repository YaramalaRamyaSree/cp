/*
gfg link - https://practice.geeksforgeeks.org/problems/josephus-problem/1
*/
    int f(int n,int k){
        if(n==1) return 0;
        return (f(n-1,k)+k)%n;
    }
    int josephus(int n, int k)
    {
       return f(n,k)+1;
       
    }
/*
pep coding link - https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/bit-manipulation/josephus-special-official/ojquestion
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int power;
    for(int i=31;i>=0;i--){
        if(n & (1<<i)){
            power =1<<i;
            break;}
    } 
    
    int ans= 2*(n-power) + 1;
    cout<<ans;
    return 0;
}
